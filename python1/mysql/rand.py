#!/usr/bin/env python
import re
import random
import string 
class randil(object):
  def getnum(self):
    a=random.randint(1,100)
    return a
  def getstr(self):
    b=string.join(random.sample(['z','y','x','w','v','u','t','s','r','q','p','o','n','m','l','k','j','i','h','g','f','e','d','c','b','a'], 5)).replace(' ','')
    return b
if __name__=="__main__":
 
  f=open("po","r+")
  s=f.read()
  m1=re.search('\d+',s)
  m2=re.findall('\d+',s)
  m3=re.match('\d+',s)
  print 'findall',m2,len(m2)
  print 's',type(s)
  #print 'search is ',m1
  #print 'match is ',m3
  
  '''
  for line in f.readlines():
    sp=re.split('\s+',line)
    print 'split is',sp
  '''
  i=0
  while i <len(m2):
    print m2[i]
    i=i+1
  f.close()
  import random 
  import string
  a=random.randint(1,100)
  print 'random',a
  print string.join(random.sample(['z','y','x','w','v','u','t','s','r','q','p','o','n','m','l','k','j','i','h','g','f','e','d','c','b','a'], 5)).replace(' ','')
