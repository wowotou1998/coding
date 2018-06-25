import csv
import codecs
list1 = ['企业名称', '时间', '地点',  '联系方式', '专业']
list2 = [' ', '123', '李四', '456', '王二娃']

list4 =['','','','','','',"4556"]
list = [list1, list2]
fileHeader = ["宣讲会日期", "宣讲会时间段", "招聘活动的校区与场所", "招聘活动教室", \
                      "单位名称", "单位地址", "邮政编码", \
                      "联系人", "联系电话", "传真", "招聘邮箱", "网址",  \
                      "序号", "岗位名称与要求", "招聘专业名称", "招聘人数", "学历要求"]
empty_list = ['']                #   表示这是空行
csvFile3 = open(r'E:\new.csv', 'w+', encoding='UTF-8', newline='') # newline 相当于省略换行，就不会出现两行之间空一行的状况
writer2 = csv.writer(csvFile3)
writer2.writerow(fileHeader)           # writerow表示写入一行    如果要写入多行则可以使用writerows
# write(str(codecs.BOM_UTF8))                               # 每一行数据为一个列表list，因此写入一行的话，就是一维列表，如果多行，则就是二维列表
writer2.writerows([list1,list2])  # writerow 和writerows的参数都是列表，要么是一维的，要么是二维的
writer2.writerows(empty_list)
for i in list :                  # 也可以使用迭代的方法
    writer2.writerow(i)

csvFile3.close()
with open(r'E:\eggs.csv', 'r') as f:
    reader = csv.reader(f)
    for row in reader:
        print(row)

f='E:\\info.csv'

def save_csvfile_with_bom(f):
    with open (f,'r+') as f:
        content = f.read()
        f.seek(0,0)
        f.truncate()
        f.write(content.decode('UTF-8','ignore').encode('GB-2312','ignore'))
src = 'E:\\info.csv'
dst = 'E:\\new_info.csv'

def ReadFile(filePath,encoding):
    with codecs.open(filePath,"r",encoding) as f:
        return f.read()

def WriteFile(filePath,u,encoding):
    with codecs.open(filePath,"w",encoding) as f:
        f.write(u)

def GBK_2_UTF8(src,dst):
    content = ReadFile(src,encoding='GBK')
    WriteFile(dst,content,encoding='UTF_8')

f = codecs.open('E:\\info.csv', 'w', 'utf_8_sig')

writer = csv.writer(f)

writer.writerow(['奥迪','爱迪生','方法'])
f.close()
