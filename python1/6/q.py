#!/usr/bin/env python
def line_conf():
    def line(x):
        return 2*x+1
    print(line(5))   # within the scope
    return line
a=line_conf()
print(a(5))
from sys import getrefcount

a = [1, 2, 3]
print(getrefcount(a))

b = a
print(getrefcount(b))
class from_obj(object):
    def __init__(self, to_obj):
        self.to_obj = to_obj

b = [1,2,3]
a = from_obj(b)
print(id(a.to_obj))
print(id(b))
