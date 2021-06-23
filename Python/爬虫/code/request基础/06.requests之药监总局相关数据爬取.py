#!/usr/bin/env python
# -*- coding:utf-8 -*-
import requests
import json
#药监总局地址：http://scxk.nmpa.gov.cn:81/xk/
if __name__ == "__main__":
    url = 'http://scxk.nmpa.gov.cn:81/xk/itownet/portalAction.do?method=getXkzsList'
    user_agent = 'Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/535.1 (KHTML, like Gecko) Chrome/14.0.835.163 Safari/535.1'
    headers = {
        'User-Agent': user_agent
    }
    data = {
        "on": "true",""
        "page": "1",
        "pageSize": "15",""
        "productName":"",
        "conditionType": "1",
        "applyname":"",
        "applysn":"",
    }
    json_ids = requests.post(url=url,headers=headers,data=data).json()
    print(json_ids)
    all_data_list = [] #存储所有企业的详情数据
    id_list = [] #存储企业的ID
    for dic in json_ids['list']:
        id_list.append(dic['ID'])
    print(id_list)#批量获取的ID

    #获取企业详情页信息
    print()
    post_url = 'http://scxk.nmpa.gov.cn:81/xk/itownet/portalAction.do?method=getXkzsById'
    for id in id_list:
        data = {
            'id':id
        }
        detail_json = requests.post(url=url,headers=headers,data=data).json()
        print(detail_json,"--------")
        all_data_list.append(detail_json)
    #持久化存储
    fp = open('../alldata.json', 'w', encoding='utf-8')
    json.dump(all_data_list,fp=fp,ensure_ascii=False)
    print("over")