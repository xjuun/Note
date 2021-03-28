[TOC]



## Request请求数据包格式

`Request请求数据包格式：`

1.  请求行：请求类型/请求资源路径、协议的版本和类型
2.  请求头：一些键值对，浏览器与web服务器之间都可以发送，特定的某种含义
3.  空行：请求头与请求体之间用一个空行隔开
4.  请求体：要发送的数据

例：

```
GET / HTTP/1.1
Host: www.baidu.com
Connection: keep-alive
Cache-Control: max-age=0
sec-ch-ua: "Google Chrome";v="89", "Chromium";v="89", ";Not A Brand";v="99"
sec-ch-ua-mobile: ?0
Upgrade-Insecure-Requests: 1
User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/89.0.4389.82 Safari/537.36
Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9
Sec-Fetch-Site: same-site
Sec-Fetch-Mode: navigate
Sec-Fetch-User: ?1
Sec-Fetch-Dest: document
Referer: https://passport.baidu.com/
Accept-Encoding: gzip, deflate, br
Accept-Language: zh-CN,zh;q=0.9,zh-HK;q=0.8,zh-TW;q=0.7
Cookie:
```

```
User-Agent: 是客户浏览器的名称
Connection: 从来告诉服务器是否可以维持固定的HTTP链接
Cookie: 浏览器用这个属性向服务器发送cookie
Referer: 表明产生请求的晚网页URL。这个属性可以用来跟踪web请求是从什么网站来的。
```

## Response返回数据包数据格式

一个响应有4个部分组成

1.  状态行：协议版本、数字形式的状态码和状态描述，各元素之间以空格分隔
2.  响应头标：包含服务器类型、日期、长度、内容类型等
3.  空行：响应头与响应体之间用空行隔开
4.  响应数据：浏览器会将实体内容中的数据取出来，生成相应的页面

```
HTTP响应码：
1xx：信息，请求收到，继续处理
2xx：成功，行为被成功地接收、理解和采纳
3xx：重定向，为了完成请求，必须进一步执行的动作
4xx：客户端错误
5xx：服务器错误
```

举例：

```
HTTP/1.1 200 OK
Bdpagetype: 1
Bdqid: 0xc476938f000163f7
Cache-Control: private
Connection: keep-alive
Content-Encoding: gzip
Content-Type: text/html;charset=utf-8
Date: Sat, 27 Mar 2021 09:15:58 GMT
Expires: Sat, 27 Mar 2021 09:15:33 GMT
Server: BWS/1.1
Set-Cookie: BDSVRTM=0; path=/
Set-Cookie: BD_HOME=1; path=/
Set-Cookie: H_PS_PSSID=33764_33745_33273_31253_33692_33758_33392_33714_26350; path=/; domain=.baidu.com
Strict-Transport-Security: max-age=172800
Traceid: 1616836558056844647414156664721075430391
X-Ua-Compatible: IE=Edge,chrome=1
Transfer-Encoding: chunked
```

