# Oracle，MongoDB等注入

简要学习各种数据库的注入特点

-   数据库架构组成，数据库高权限操作

简要学习各种注入工具的使用指南

-   熟悉工具的支持库，注入模式，优缺点

-   sqlmap，NoSQLAttack，pangolin等



数据库的不同

```
Access
	表 
		列
			数据
			
mssql等其他数据库
	数据库A
		表
			列
				数据
	数据库B	
		...
```

Access数据库的话没有`information_schema` ，所以只能靠猜。

MongoDB的查询文档的方式与其他数据库略微不同，当进行查询的时候，MySQL是用where，而MongoDB是以键值对形式进行查询的。



遗留问题：

-   Access猜不到表和列怎么办？

    Access偏移注入