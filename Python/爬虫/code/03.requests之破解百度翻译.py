#!/usr/bin/env python
# -*- coding:utf-8 -*-
import requests
import json
if __name__ == "__main__":
    post_url = 'https://fanyi.baidu.com/sug'
    #post参数请求处理
    word = input('input word:')
    data={
        'kw':word
    }
    #进行ua伪装
    user_agent = 'Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/535.1 (KHTML, like Gecko) Chrome/14.0.835.163 Safari/535.1'
    headers = {
        'User-Agent': user_agent
    }
    response = requests.post(url=post_url,data=data,headers=headers)
    #获取相应数据：json方法返回的是obj（如果确认相应的数据时json类型的，才可以使用json）
    dic_obj = response.json()
    print(dic_obj)
    #持久化储存
    fp=open('./dog.json','w',encoding='utf-8')
    json.dump(dic_obj,fp=fp,ensure_ascii=False)
    print("over!")


