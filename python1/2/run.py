#!/usr/bin/env python
class isy(object):
  def __init__(self,y,m,d):
    print 'now is',y,m,d
    if y%100==0:
      if y%400==0:
        print 'yes'
      else:
        print 'no'
    elif y%4==0:
      print 'yes'
    else:
      print 'no'
a=isy(2004,1,1)

