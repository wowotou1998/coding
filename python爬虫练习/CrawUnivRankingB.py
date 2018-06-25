#CrawUnivRankingB.py
import requests
from bs4 import BeautifulSoup
import bs4

def getHTMLText(url):
    try:
        r = requests.get(url, timeout=30)
        r.raise_for_status()
        r.encoding = r.apparent_encoding
        return r.text
    except:
        return ""

def fillUnivList(ulist, html):
    soup = BeautifulSoup(html, "html.parser")
    for tr in soup.find('tbody').children:                                 #寻找所有的tbody标签中的子类
        if isinstance(tr, bs4.element.Tag):                                 #判断tr标签是不是标签
            tds = tr('td')                                                  #将tr标签中的td标签加入列表tds
            ulist.append([tds[0].string, tds[1].string, tds[3].string])     #列表中可以添加其他列表

def printUnivList(ulist, num):
    tplt = "{0:^10}\t{1:{3}^10}\t{2:^10}"
    print(tplt.format("排名","学校名称","总分",chr(12288)))
    for i in range(num):
        u=ulist[i]
        print(tplt.format(u[0],u[1],u[2],chr(12288)))
    
def main():
    uinfo = []

    url = 'http://www.zuihaodaxue.cn/zuihaodaxuepaiming2016.html'
    html = getHTMLText(url)
    fillUnivList(uinfo, html)
    printUnivList(uinfo, 20) # 20 univs

