#!/usr/bin/env python
s='asdfghj'
for (ind,ch) in enumerate(s):
  print ind
def gen(a,b):
  return a+b
re=map((lambda x,y:x+y),[1,2,3],[3,2,1])
print re
z1=iter(range(5))

try:
    for i in range(100):
        print z1.next()
except StopIteration:
    print 'here is end ',i

print 'HaHaHaHa'
x=3
print x**2
x1=[1,2,4]
y1=[2,6,8]
l=[x**2 for (x,y) in zip(x1,y1) if y>10]
print l
