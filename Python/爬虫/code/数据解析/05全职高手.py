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
    url = "https://www.ddxs.cc/ddxs/168019/"
    main_page = requests.get(url=url, headers=headers).text.encode('ISO-8859-1')
    # print(main_page.encoding)
    main_soup = BeautifulSoup(main_page, 'lxml')
    num = len(main_soup.select('.box_con > div > dl > dd'))
    fp = open('全职高手' + '.txt', 'a+', encoding='utf-8')
    for i in range(0,num):
        title_name = main_soup.select('.box_con > div > dl > dd > a')[i].string
        title_url = "https://www.ddxs.cc/" + main_soup.select('.box_con > div > dl > dd > a')[i]['href']

        fp.write(title_name+'\n')

        #detail_page = requests.get(url=title_url, headers=headers).text.encode('ISO-8859-1')

        # print("detail_name"+title_name)
        # print("detail_url" + title_url)

        #detail_soup = BeautifulSoup(detail_page, 'lxml')
        #text_context = detail_soup.find('div', id='content').text
        #fp.write(text_context+'\n\n')

        #print(text_context)
        if i % 10 == 0:
            print(str(i) +" is ok")
