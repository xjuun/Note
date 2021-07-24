[TOC]



之前看了好几次的爬虫的视频，结果无一例外都没坚持下去，这次必搞完

视频地址：https://www.bilibili.com/video/BV1Yh411o7Sz

# 1.爬虫简介

# 2.爬虫合法性探究

![image-20210622173053733](readme/image-20210622173053733.png)

# 3.爬虫初始深入

![image-20210622173700013](readme/image-20210622173700013.png)

# 4.http&https协议

**常用请求头信息**

```
User-Agent：请求载体的身份标识
Connection：请求完毕后，是乱开链接还是保持连接
```

**常用相应头信息**

```
Content-Type：服务器相应回客户端的数据类型
```



**加密方式**

```
对称密钥加密
非对称密钥加密
证书加密
```

# 5.request第一血

request模块：

-   urllib模块
-   request模块（主要）

--------------

request模块作用：模拟浏览器发型请求

如何使用：

-   指定url
-   发起请求
-   获取相应数据
-   持久化存储





# 6.requests巩固深入案例介绍

接下来几节课要写的代码

# 7.requests简易网页采集器

具体代码在：

>    code/02.requests之网页采集器.py



# 8.requests之破解百度翻译

涉及到ajax

AJAX 是一种在无需重新加载整个网页的情况下，能够更新部分网页的技术。

AJAX 不是新的编程语言，而是一种使用现有标准的新方法。

AJAX 是与服务器交换数据并更新部分网页的艺术，在不重新加载整个页面的情况下。

![image-20210622234523589](readme/image-20210622234523589.png)

![image-20210622234607214](readme/image-20210622234607214.png)

post请求，相应数据是json数据

# 9.requests之豆瓣电影爬取

具体代码在code文件夹下

# 10.作业

作业url：http://www.kfc.com.cn/kfccda/storelist/index.aspx

# 11. 综合练习-药监总局01

 药监总局地址：http://scxk.nmpa.gov.cn:81/xk/

![image-20210623160201968](readme/image-20210623160201968.png)

ajax

![image-20210623160224027](readme/image-20210623160224027.png)

# 12.综合练习-药监总局02

# 13.综合练习-药监总局03screenflow

# 14.综合练习-药监总局04screenflow

# 15.总结回顾

接下来要讲的：

-   聚焦爬虫
-   正则
-   bs4
-   xpath

# 16.数据解析概述

 数据解析分类：

-   正则
-   bs4
-   xpath

# 17.图片数据爬取

见0.图片爬取.py

# 18.正则解析案例01

# 20.bs4解析

环境：

```python
pip install bs4
pip install lxml
```



实例化beautifulsoup对象：

`from bs4 import BeautifulSoup`

对象的实例化：

1.  将本地的HTML文件的数据加载到该对象中：

    ```python
    fp = open("../bilibili.html",'r',encoding='utf-8')
    soup = BeautifulSoup(fp,'lxml')
    print(soup)
    ```

2.  将互联网上的。。。

    ```python
    page_text = response.text
    soup = BeautifulSoup(page_text,'lxml')
    ```

    

# 23.xpath解析

xpath解析：最常用且最便捷高效的一种解析方式。通用性。

    - xpath解析原理：
        - 1.实例化一个etree的对象，且需要将被解析的页面源码数据加载到该对象中。
        - 2.调用etree对象中的xpath方法结合着xpath表达式实现标签的定位和内容的捕获。
    - 环境的安装：
        - pip install lxml
    - 如何实例化一个etree对象:from lxml import etree
        - 1.将本地的html文档中的源码数据加载到etree对象中：
            etree.parse(filePath)
        - 2.可以将从互联网上获取的源码数据加载到该对象中
            etree.HTML('page_text')
        - xpath('xpath表达式')
    - xpath表达式:
        - /:表示的是从根节点开始定位。表示的是一个层级。
        - //:表示的是多个层级。可以表示从任意位置开始定位。
        - 属性定位：//div[@class='song'] tag[@attrName="attrValue"]
        - 索引定位：//div[@class="song"]/p[3] 索引是从1开始的。
        - 取文本：
            - /text() 获取的是标签中直系的文本内容
            - //text() 标签中非直系的文本内容（所有的文本内容）
        - 取属性：
            /@attrName     ==>img/src



















