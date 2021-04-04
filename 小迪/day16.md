[TOC]



# SQL注入之查询方式及报错盲注

当进行SQL注入时，有很多注入会出现无回显的情况，其中不回显的.原因可能是SQL语句查询方式的问题导致，这个时候我们需要用到相关的报错或盲注进行后续操作，同时作为手工注入时，提前了解或预知其SQL语句大概写法也能更好的选择对应的注入语句。



-   select注入

-   insert注入

    `insert into member(username,pw,sex,email,.....) value('xiaodi',md5('12345'),'man','12312313'...)`

    只有成功还是未成功

    

-   update注入

    

-   delete注入



盲注分类

-   基于布尔的SQL盲注--逻辑判断

    regexp，like，ascii，left，ord，mid

-   基于时间 的失去了盲注--延时判断

    if，sleep

-   基于报错的SQL盲注--报错回显

    floor，updatexml，extractvalue

```
参考:
like 'r%'						#判断xo或ro.. .是否成立
regexp '^xiaodi [a-z]' 			#匹配xiaodi及xiaodi...等
if (条件,5,0)					   #条件成立返回5反之返回0
sleep (5)						#sQI语句延时执行5秒
mid(a,b,c)						#从位置b开始，截取a字符串的c位
substr(a,b, c)					#从b位置开始，截取字符串a的c长度
left (database(),1)，database() #left (a, b)从左侧截取a的前b位
length (database ())=8			#判断数据库 database ()名的长度
ord=ascii ascii (x)=97			#判断x的ascii码是否等于97
```

