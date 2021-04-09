# 文件上传之内容逻辑数组绕过

### Load labs less-14

`copy normal.jpg /b + shell.php /a webshell.jpg`

还需结合文件包含漏洞

?file=/asdfasf/xxx.jpg



后面的几关都是这样，只是函数不同



## 解析漏洞

**IIS6.0**

-   文件夹
    -   image/qq.jpg
    -   image/qq.jsp/qq.jpg
-   文件
    -   xxx.jsp;.xxx.jpg或xxx.jsp;.jpg

**Nginx**

-   



## day23 ~day24没看

记得后续看















