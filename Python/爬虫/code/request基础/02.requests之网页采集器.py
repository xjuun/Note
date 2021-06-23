#!/usr/bin/env python
# -*- coding:utf-8 -*-

#UA :user-agent(请求载体的身份标识)(某一款浏览器)
#ua检测，UA伪装
import requests

if __name__ == "__main__":
    url = 'https://www.sogou.com/web?'
    user_agent = 'Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/535.1 (KHTML, like Gecko) Chrome/14.0.835.163 Safari/535.1'
    headers = {
        'User-Agent':user_agent
    }
    #处理url携带的参数：封装到字典中
    kw = input('enter a word:')
    param = {'query':kw}#query是上面url的参数
    #对指定的url发起的请求对应的url是携带参数的，并且请求过程中处理了参数
    response = requests.get(url=url, params = param,headers =  headers)
    page_text = response.text

    fileName = kw+'.html'
    with open(fileName,'w',encoding='utf-8') as fp:
        fp.write(page_text)
    print(fileName,'保存成功')

