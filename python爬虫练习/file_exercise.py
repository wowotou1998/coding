porm='asasaasas'

f=open('D:\桌面\\aa.txt','r')


while (1):
    line=f.readline()
    if len(line)==0:
        break

    print(line,end='')
f.close()
