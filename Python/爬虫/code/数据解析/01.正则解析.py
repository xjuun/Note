#!/usr/bin/env python
# -*- coding:utf-8 -*-
import requests
import json
import re
import os
# 需求：爬取糗事百科中糗图板块下所有的糗图图片
if __name__ == "__main__":
    if not os.path.exists('./qiutuLibs'):
        os.makedirs('./qiutuLibs')
    url = 'https://www.qiushibaike.com/imgrank/'
    user_agent = 'Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/535.1 (KHTML, like Gecko) Chrome/14.0.835.163 Safari/535.1'
    headers = {
        'User-Agent': user_agent
    }
    page_text = requests.get(url=url,headers=headers).text
    #print(page_text)
    #正则
    ex = '<div class="thumb">.*?<img src="(.*?)" alt.*?</div>'
    img_src_list = re.findall(ex,page_text,re.S)
    print(img_src_list)
    for src in img_src_list:
        src = 'https:'+src
        img_dara = requests.get(url=url,headers=headers).content
        #生成图片名称
        img_name = src.split('/')[-1]
        #图片存储路径
        imgPath = './qiutuLibs/'+img_name
        with open(imgPath,'wb') as fp:
            fp.write(img_dara)
            print(img_name,'down ok!')