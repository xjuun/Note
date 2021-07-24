#!/usr/bin/env python
# -*- coding:utf-8 -*-
from lxml import etree
import requests
import json

if __name__ == "__main__":
    #tree = etree.parse('test.html')
    # parser = etree.HTMLParser(encoding="utf-8")
    # tree = etree.parse("test.html", parser=parser)
    # a = tree.xpath('//div[@class="song"]/p[1])')

    tree =  etree.parse('test.html')
    r = tree.xpath('//div[@class="tang"]//li[7]/i/text()')[0]
    print(r)