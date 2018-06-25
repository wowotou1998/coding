import requests
from bs4 import BeautifulSoup
import bs4
import re                              #正则表达式库
import csv



url='http://job.ahut.edu.cn/cms/view/wz!viewZph.action?id=f85103c65f22eb9e015f6c04f9101afb'       #要爬取的网址
kv={'user-agent': 'Chrome/10'}       # 这是一个键值对，来说明访问的头部

try:
    r=requests.get(url,headers=kv,timeout=30)
    r.raise_for_status()
    r.encoding='utf-8'
    r.text.replace(u'\xa0', u' ')
except:
     print('网络连接错误')



web_tree=BeautifulSoup(r.text,'html.parser')
# find_all方法,z这里有一个列表，只不过只有一个元素
# 单位基本信息----------------------------------------------------
# 单位基本信息----------------------------------------------------
p = re.compile(r'[:：\s]+') # 正则表达式去除空格的最佳方法

divs=web_tree.find_all("div", "c_1")
# 定义一个存储标签的列表
list=[1,2,3,6,7,8,9,10]
# 运用正则表达式打印招聘会的时间地点信息
for div in divs[0].contents:
    if div.name == 'font':
    #  强制类型转换, 转换为string类型
        n=str(div.get_text)
        match = re.findall(r'[:：][\s]?[\u4e00-\u9fa5\w\s：]{3,21}', n, re.M)   # re.M表示正则匹配以每行开头重新匹配
        for arg in match:
          new_arg=re.sub(p, '', arg)
          print(new_arg)
trs=divs[0].find_all("tr")
# 这是一个列表虽然只有两个元素
for arg in list:
    tds = trs[arg]('td')
    strings = str(tds[1].string)
    new_string = re.sub(p, '', strings)
    print(new_string)

# 招聘岗位信息---------------------------------------------------------------
# 招聘岗位信息 ---------------------------------------------------------------

tbodys = web_tree.find_all('tbody')
trs_employe_info = tbodys[0]('tr')
for trs_employe_info_arg in trs_employe_info:
        for td_employe_info in trs_employe_info_arg('td'):
           td_employe_info_new = re.sub(p, '', str(td_employe_info.string))
           print(td_employe_info_new)    # print(td_employe_info.string ,end=" ")




















