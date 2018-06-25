import requests
url = 'http://eachother.top/projects/'
data = {'name':'zhangjiebao','age':'20'}
r = requests.post(url,data = data)
print(r.text)
