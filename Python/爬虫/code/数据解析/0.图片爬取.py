#!/usr/bin/env python
# -*- coding:utf-8 -*-
import requests
import re
import json


if __name__ == "__main__":
    url = 'https://pic.qiushibaike.com/system/pictures/12433/124337776/medium/SKD4RPPD6AXG7D6Z.jpg'
    #content返回的是二进制的图片数据
    #text：字符串
    #content：二进制
    #json()：对象
    img_data = requests.get(url=url).content
    print(img_data)
    with open('./qiutu.jpg','wb') as fp:
        fp.write(img_data)
    print("over!!")