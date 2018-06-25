import requests
from bs4 import BeautifulSoup
import bs4
import re                              # 正则表达式库
import csv




url='http://job.ahut.edu.cn/cms/view/wz!viewZph.action?id=f85103c65f22eb9e01608d0b5602538b'       #要爬取的网址
try:
        kv = {'user-agent': 'Chrome/10'}   # 这是一个键值对，来说明访问的头部
        r = requests.get(url, headers=kv, timeout=30)
        r.raise_for_status()
        # 此处分析文本需要花费很多时间，可以人为指定文本编码一般为‘utf-8’或者‘GB-2312’
        r.encoding=r.apparent_encoding
       # r.encoding = 'GB-2312'

except:
        print("单个企业信息爬取出现网络连接错误")

        web_tree = BeautifulSoup(r.text, 'html.parser')
        # find_all方法,z这里有一个列表，只不过只有一个元素

# 单位基本信息----------------------------------------------------

        divs = web_tree.find_all("div", "c_1")
        # 定义一个存储标签的列表
        tag_list = [1, 2, 3, 6, 7, 8, 9]
        # 运用正则表达式打印招聘会的时间地点信息
        print(divs)
        for div in divs[0].contents:
            if div.name == 'font':
                #  强制类型转换,转换为string类型
                n = str(div.get_text)
                print(n)
                # 正则表达式强力去空格\s|(\u00A0)|(\u3000)
                # 正则表达式强力去空格\s|(\u00A0)|(\u3000)
                # 正则表达式强力去空格\s|(\u00A0)|(\u3000)
                match = re.findall(r'^[^<\s(\u00A0)(\u3000)] .* [^<]*', n, re.M)   # re.M表示正则匹配以每行开头重新匹配

                for arg in match:

                    print(arg)
