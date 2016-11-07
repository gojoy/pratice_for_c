#!/usr/bin/env python
def f(**c):
  print type(c)
  print c
f(a=1,b=2)
f(x=5)
