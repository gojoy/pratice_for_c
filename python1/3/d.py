#!/usr/bin/env python
dic={1:'tom',2:'jok'}
dic['gor']=100
print dic
for k in dic:
  print dic[k]
f=open("test12","a+")
f.write('hello\n')
co=f.readlines()
f.close()
print co,type(co)
