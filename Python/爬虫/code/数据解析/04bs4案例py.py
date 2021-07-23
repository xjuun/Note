#!/usr/bin/env python
# -*- coding:utf-8 -*-

import requests
import os
from bs4 import BeautifulSoup
user_agent = 'Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/535.1 (XHTML, like Gecko) Chrome/14.0.835.163 ' \
             'Safari/535.1 '
headers = {
    'User-agent': user_agent
}
if __name__ == "__main__":
    url = 'https://www.shicimingju.com/book/sanguoyanyi.html'
    page_text = requests.get(url = url,headers=headers).text.encode('ISO-8859-1')
    #解析出标题和详情页
    soup = BeautifulSoup(page_text,'lxml')
    li_list = soup.select('.book-mulu > ul > li ')
    fp = open('./sanguo.txt','w',encoding='utf-8')
    for li in li_list:
        title = li.a.string
        detail_url = 'https://www.shicimingju.com'+li.a['href']

        #发请求解析章节内容
        detail_page = requests.get(url=detail_url, headers=headers).text.encode('ISO-8859-1')
        # print(detail_page.encoding)
        detail_soup = BeautifulSoup(detail_page,'lxml')
        div_tag = detail_soup.find('div',class_='chapter_content')
        content = div_tag.text
        fp.write(title+':'+content+'\n')
        print(title+'is ok!')





