#!/usr/bin/env python
# -*- coding:utf-8 -*-
import requests
import json
if __name__ == "__main__":
    url = 'https://movie.douban.com/j/chart/top_list'
    param = {
        "type": "11",
        "interval_id": "100:90",
        "action": "",
        "start": "0",
        "limit": "20",
    }
    user_agent = 'Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/535.1 (KHTML, like Gecko) Chrome/14.0.835.163 Safari/535.1'
    headers = {
        'User-Agent': user_agent
    }
    response = requests.get(url=url,params=param,headers=headers)
    list_data = response.json()
    fp = open('../douban.json', 'w', encoding='utf-8')
    json.dump(list_data,fp=fp,ensure_ascii=False)
    print('over!')
