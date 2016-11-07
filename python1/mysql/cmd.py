#!/usr/bin/env python
import os
class putout(object):
  def cin(self):
    b=raw_input('input cmd:\n')
    return b
  def cmd(self,cmd):
    self.cmd=cmd
    a=os.popen(self.cmd)
    c=a.read()
    return c
#a=cin()
#print a
if __name__== "__main__":
  test=putout()
  a=test.cin()
  print 'in is',a
  b=test.cmd(a)
  print 'result is\n',type(b),b
