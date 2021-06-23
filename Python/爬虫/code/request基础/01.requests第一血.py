#!/usr/bin/env python
# -*- coding:utf-8 -*-

import requests

if __name__ == "__main__":
    #step1: 指定url
    url = 'https://www.bilibili.com'
    #step2: 发起请求
    #get方法会返回一个相应对象
    response = requests.get(url=url)
    #step3: 获取相应数据
    page_text = response.text
    print(page_text)
    #step: 持久化存储
    with open('../bilibili.html', 'w', encoding='utf-8') as fp:
        fp.write(page_text)
    print('爬取数据结束')