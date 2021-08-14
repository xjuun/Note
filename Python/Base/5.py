import requests
import hashlib
from bs4 import BeautifulSoup

req=requests.session()
#change URL according to yours
url="http://139.59.166.56:30481/"

get_req=req.get(url)
html=get_req.content

soup = BeautifulSoup(html, 'html.parser')
hash_val=soup.h3.get_text().encode('utf-8')

md5hash=hashlib.md5(hash_val).hexdigest()
data=dict(hash=md5hash)
post_res=req.post(url=url,data=data)
print("flag:",post_res.text)