#!/usr/bin/env python
class num(object):
    def __init__(self, value):
        self.value = value
    def getNeg(self):
        return -self.value
    def setNeg(self, value):
        self.value = -value
    def delNeg(self):
        print("value also deleted")
        del self.value
    neg = property(getNeg, setNeg, delNeg, "I'm negative")

x = num(1.1)
print(x.neg,x.value)
print('-22value is')
x.neg = -22
print(x.value)
print(x.neg,'neg')
print('doc=')
print(num.neg.__doc__)
print('del')
del x.neg
