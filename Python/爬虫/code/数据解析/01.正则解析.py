#!/usr/bin/env python
# -*- coding:utf-8 -*-

import requests
import os
import re
import json
if __name__=="__main__":
    if not os.path.exists("./qiutuLibs"):
        os.makedirs('./qiutuLIbs')

    url = 'https://www.qiushibaike.com/imgrank/'
    user_agent = 'Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/535.1 (KHTML, like Gecko) Chrome/14.0.835.163 Safari/535.1'
    headers = {
        'User-agent':user_agent
    }
    page_text = requests.get(url=url,headers = headers).text

    ex = '<div class="thumb">.*?<img src="(.*?)" alt.*?</div>'
    img_src_list = re.findall(ex,page_text,re.S)
    #print(img_src_list)

    for src in img_src_list:
        src = "https:"+src
        img_data = requests.get(url = src,headers= headers).content
        img_name = src.split('/')[-1]

        img_path = './qiutuLibs/'+img_name
        with open(img_path,'wb') as fp:
            fp.write(img_data)
            print(img_name+' down ok!')
