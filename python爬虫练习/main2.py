import sys

list_2d = [ [0 for inner in range(5)] for outer in range(1)]
print(list_2d)
print("the command line argument are")
for i in sys.argv:
    print(i)
print("the pythonpath is",sys.path)
if __name__ == '__main__':
    print('This program is being run by itself')
else:
    print('I am being imported from another module')
dir(sys)
#列表,列表其实是一种序列
list = ['aa', 'bb', 'cc']
print(len(list))
list.append('dd')
print(len(list))
for i in list:
    print(i)

#元组，其实也是一种序列，有点像字符串，一旦定义，不可更改
zoo=('aaa','bbb','ccc')
for item in zoo:
    print(item)
new_zoo='ddd','eee',zoo
print(len(new_zoo))
for item2 in new_zoo:
    print(item2)

#字典就是一对对键值对
dic={
    'key1':'value1',
    'key2':'value2',
    'key3':'value3'
}
print("key3's  value is ",dic['key3'])
#删除一个键值对
del dic['key1']
#添加一对键值对
dic['key4']='value4'
#更新键值对
dic['key3']='value5'
print("key3's  value is ",dic['key3'])
#列表、元组和字符串可以看作序列（Sequence）的某种表现形式，可是究竟什么是序列，它又有什么特别之处？

#序列的主要功能是资格测试（Membership Test）（也就是 in 与 not in 表达式）和索引操作（Indexing Operations），它们能够允许我们直接获取序列中的特定项目。

#上面所提到的序列的三种形态——列表、元组与字符串，同样拥有一种切片（Slicing）运算符，它能够允许我们序列中的某段切片——也就是序列之中的一部分。

class people:
    name=''
    age=0
    _weight=0
    def __init__(self,n,a,w):
        self.name=n
        self.age=a
        self._weight=w
    def speak(self):
        print("{}{} ".format(self.name,self.age))

class student(people):
    grade=''
    def __init__(self,n,a,w,g):
        people.__init__(self,n,a,w)
        self.grade=g
    def speak(self):
        print("{} {} {} ".format(self.name,self.age,self.grade) )



class speaker:
    topic=''
    name=''
    def __init__(self,n,t):
        self.nam=n
        self.topic=t
    def speak(self):
        print("{}{}".format(self.topic,self.name))


class sample(speaker,student):
    a=''
    def __init__(self,n,a,w,g,t):
        student.__init__(self,n,a,w,g)
        speaker.__init__(self,n,t)
test =sample("tim",25,80,4,"python")
test.speak()
