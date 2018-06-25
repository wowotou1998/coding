# -*- coding: UTF-8 -*-
# 字符编码说明
import requests
from bs4 import BeautifulSoup
import bs4
import re                              # 正则表达式库
import csv
import time
import codecs
from openpyxl import workbook

def getHTMLtext(url, code):
    try:
        kv = {'user-agent': 'Chrome/10'}   # 这是一个键值对，来说明访问的头部
        r = requests.get(url, headers=kv, timeout=30)
        r.raise_for_status()
        # 此处分析文本需要花费很多时间，可以人为指定文本编码一般为‘utf-8’或者‘GB-2312’
        r.encoding='utf-8'
        #r.content.decode("UTF-8", "ignore").encode("UTF-8", "ignore")
        return r.text    # 用此方法忽略HTML中空格的处理
    except:
        print("单个企业信息爬取出现网络连接错误")

def crawl_for_info(Rtext,baseinfoLIST,jobinfoLIST):
        baseinfoLIST = []
        # -----------------------------------------------------------------------------编码问题的最佳解决方法----------------------上知乎搜索----------------------------------------
        csvFile3 = open('E:\\new_info.csv', 'a+', encoding='UTF-8', newline='')
        writer2 = csv.writer(csvFile3)

        web_tree = BeautifulSoup(Rtext, 'html.parser')
        # find_all方法,z这里有一个列表，只不过只有一个元素


        # 单位基本信息----------------------------------------------------
        p = re.compile(r'[\s]+') #  正则表达式去除空格的最佳方法
        #p2 = re,compile(r'[\u003c]')
        divs = web_tree.find_all("div", "c_1")
        # 定义一个存储标签的列表
        tag_list = [1, 2, 3, 6, 7, 8, 9, 10]
        # 运用正则表达式打印招聘会的时间地点信息
        for div in divs[0].contents:
            if div.name == 'font':
                #  强制类型转换,转换为string类型
                n = str(div.get_text)
                # 正则表达式强力去空格\s|(\u00A0)|(\u3000)
                info_list = re.findall(r'[\u4e0a|\u9038|\u4e0b|\u4f73|\u79c0|\u6559|\u0032][^\u5ba4].{0,20}', n, re.M)   # re.M表示正则匹配以每行开头重新匹配
                for arg in info_list:
                    arg_new =arg.replace("<br/>", "")
                    baseinfoLIST.append(arg_new) # baseinfoLIST下标0-3分别为举办日期，时间，校区，教室,说明（说明不常用）--------------------------------------------------------


        trs = divs[0].find_all("tr")
        # 这是一个列表虽然只有两个元素
        for arg in tag_list:
            tds = trs[arg]('td')
            strings = str(tds[1].string)
            new_string = re.sub(p, '', strings)
            baseinfoLIST.append(new_string) # 下标为0-7，有7个属性分别是单位名称，地址，邮编，联系人，电话，传真，邮箱，网址
        writer2.writerow(baseinfoLIST)

        # 招聘岗位信息---------------------------------------------------------------

        tbodys = web_tree.find_all('tbody')
        trs_employe_info = tbodys[0]('tr')
        j = len(trs_employe_info)

        jobinfoLIST = [['' for inner in range(12)] for outer in range(j)]  # 这是一个二维列表，其中，每行有五个元素，一共有j行

        for tr_tag_number in range(j):
            tr_tags=trs_employe_info[tr_tag_number] # 这表示现在在第几个tr标签中
            for td_arg in tr_tags('td'):
                jobinfoLIST[tr_tag_number].append(td_arg.string)    # 这里有5个属性，分别是序号，岗位名称，专业，招聘人数，学历要求
        writer2.writerows(jobinfoLIST)

# 第一步，得到每个页码的链接-------------------------------------------------------------

def gen_address_info(count):
    first_url = "http://job.ahut.edu.cn/cms/view/lm!zpxxlist.action?zpfs=01&pager.offset={}&pageNo={}".format((count-1)*20,count)
    print('得到第{}页的链接'.format(count))
    return first_url



#  第二步，得出每个页码中所包含的20个企业的信息-------------------------------------------
def crawl_for_list_twenty_info(target1_url):
    try:
        kv = {'user-agent': 'Chrome/10'}   # 这是一个键值对，来说明访问的头部
        r = requests.get(target1_url, headers=kv, timeout=30)
        r.raise_for_status()
        # 此处分析文本需要花费很多时间，可以人为指定文本编码一般为‘utf-8’或者‘GB-2312’
        r.encoding=r.apparent_encoding
        # r.content.decode("UTF-8", "ignore").encode("UTF-8", "ignore")
        # r.text.replace(u'\xa0', u' ')
    except:
        print("企业列表爬取出现网络连接错误")


    web_tree = str(BeautifulSoup(r.text, 'html.parser'))
    # uls=web_tree.find_all('ul', class_='list_4')
    list_twenty = re.findall(r'\w{32}', web_tree, re.S)
    # list_twenty=web_tree.find_all(re.compile(r'\w{32}'))

    return list_twenty


def main():
    endPage = 1
    file_target = codecs.open('E:\\new_info.csv', 'w', 'utf_8_sig')

    print('开始运行时间为：',time.strftime("%Y-%m-%d %H:%M:%S", time.localtime()))
    for counter in range(endPage):
        BaseLIST, JobLIST = [], []
        print('正在抓取第{}页'.format(counter+1))
        FIRST_URL = gen_address_info(counter+1)  # 得到页码的链接----------------------------------
        LIST_enterprise = crawl_for_list_twenty_info(FIRST_URL)
        for i in range(20):
            SECOND_URL = 'http://job.ahut.edu.cn/cms/view/wz!viewZph.action?id={}'.format(LIST_enterprise[i])
            print("正在爬取第{}页中的第{}个企业信息".format(counter+1,i))
            text = getHTMLtext(SECOND_URL, '')
            crawl_for_info(text, BaseLIST, JobLIST)

    print('结束时间为：', time.strftime("%Y-%m-%d %H:%M:%S", time.localtime()))
# 运行main函数

main()
'''
不足：
时间的冒号还有网址的冒号被正则表达式所替换
有些企业的信息页有说明，但是正则截取很难搞
设置一个进度条就好了
真的很繁琐，希望以后被正则替代
编码问题很是头疼

'''








