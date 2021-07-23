#!/usr/bin/env python
# -*- coding:utf-8 -*-

from bs4 import BeautifulSoup

if __name__ == "__main__":
    fp = open("./test.html",'r',encoding='utf-8')

    soup = BeautifulSoup(fp,'lxml')
    # print(soup)
    print(soup.a)        #返回文档中第一次出现的tagName标签
    print(soup.find('div'))     #等同于  print(soup.div)
    print(soup.find('div',class_='song'))

    # print(soup.findAll('a'))
    # print(soup.find_all('a'))
    if soup.findAll('a') == soup.find_all('a'):
        print("yes")
    print('----------------------')
    #select：    select(某种选择器（id，class，标签）)，返回是一个列表
    # > 表示相邻层级
    print(soup.select('.tang > ul > li a')[0])
    # 空格表示多个层级
    print(soup.select('.tang > ul   li a')[0])
    print(soup.select('.tang > ul   li a')[0].string)
    print(soup.select('.tang > ul   li a')[0].text)
    print(soup.select('.tang > ul   li a')[1].get_text())
    print('----------------------')
    for i in range(0,len(soup.select('body'))):
        print(soup.select('body')[i].get_text())
    print('----------------------')
    print(soup.select('.tang a')[1]['href'])


