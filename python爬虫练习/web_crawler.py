import requests
from bs4 import BeautifulSoup
import bs4
import re                              #正则表达式库
import sys, os
import codecs
def ReadFile(filePath,encoding):
    with codecs.open(filePath,"r",encoding) as f:
        return f.read()
def WriteFile(filePath,u,encoding):
    with codecs.open(filePath,"w",encoding) as f:
        f.write(u)
def GBK_2_UTF8(src,dst):
    content = ReadFile(src,encoding='gbk')
    WriteFile(dst,content,encoding='utf_8')
url='http://job.ahut.edu.cn/cms/view/wz!viewZph.action?id=f85103c65f22eb9e01607db9015552d9'       #要爬取的网址
kv={'user-agent':'Chrome/10'}       #这是一个键值对，来说明访问的头部
try:
    r=requests.get(url,headers=kv)
    r.status_code

    r.content.decode('UTF-8', 'ignore').encode('UTF-8', 'ignore')

    print(r.text)
except:
    print('出现错误')



web_tree=str(BeautifulSoup(r.text, 'html.parser'))
# uls=web_tree.find_all('ul',class_='list_4')
li2=re.findall(r'\w{32}', web_tree, re.S)
# li2=web_tree.find_all(re.compile(r'\w{32}'))

print(li2)












'''''
trs=web_tree.find_all('tr')             #find_all方法
companyname_list=[]                             #定义一个存储标签的列表
tds=[]
list=[]
for tr in trs:                                             #在所有tr标签中
        if isinstance(tr, bs4.element.Tag) and tr.get('data-source')=="xjh":        # 根据标签信息和属性信息找出特定的tr标签
            td=tr.contents
            for arg in td[1].contents:
                print(arg.string)



            else :
                pass
            
for arg in tag:
    if arg.get('href')=="/article/576676.html":
        print(arg.get('title'))
    else:
        #print(arg.get('title'))
        pass

for arg in tag:
    print(arg.attrs['href'])        #获取属性中的链接信息

tag=tag[1].contents
for arg in tag:             #遍历子标签
    print(arg)




bodylistcontent=tag.contents
print(len(bodylistcontent))

bodylistchildren=tag.children
print(tag.next_sibling)
for arg in bodylistchildren:             #遍历子标签
    print(arg)
for arg2 in soup.a.next_siblings         #遍历后续标签（在同一父节点下）
    print(arg2)
    
print(soup.prettify())                     #可以很好地分行显示HTML的标签元素
print(soup)

'''
