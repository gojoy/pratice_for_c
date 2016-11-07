#!/usr/bin/env python
class nu(object):
  def setx(self,x):
    self.x=x
    print x
    print 'in s'
    return x
  def gxa(self):
    print 'in gx'
    m=self.x
    print 'm is',m
    b=self.setx(99)
    print 'b is',b
a=nu();
a.setx(5)
a.gxa()
a1=2
a2='"lili"'
sql="select into a values({0},{1})".format(a1,a2)
print sql
