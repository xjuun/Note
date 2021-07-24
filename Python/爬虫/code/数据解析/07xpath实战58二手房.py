#!/usr/bin/env python
# -*- coding:utf-8 -*-
from lxml import etree
import requests
import json
user_agent = 'Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/535.1 (XHTML, like Gecko) Chrome/14.0.835.163 ' \
             'Safari/535.1 '
headers = {
    'User-agent': user_agent
}

if __name__ == "__main__":
    url = "https://bj.58.com/ershoufang"
    page_text = requests.get(url=url,headers=headers).text

    tree = etree.HTML(page_text)
    list_li = tree.xpath('//section[@class="list-main"]/section[@class="list]/div')
    for li in list_li:
        a = li.xpath('./div[2]/h2/a/text()')
        print(a)
