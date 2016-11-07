#!/usr/bin/env python
print 'ok'
s=[1,2,3,'ss']
for a in [1,2,3,'sdf']:
  print a
for s in range(9):
  if s==2:
    continue
  print s,type(s)
a=1
def add(a):
  a=a+1
  return a
print add(a)
print a
class Bird(object):
  have_father=True
  way='egg'
  def move(self,x,y):
    p=[0,0]
    p[0]=p[0]+x
    p[1]=p[1]+y
    return p
class ol(Bird):
  def __init__(self,a):
    self.sa=a
  eat='kfc'
  def hu(self):
    print self.sa
tom=Bird()
print tom.way,tom.move(2,5) 
jck=ol('init')
print jck.sa,jck.have_father
jck.hu()
