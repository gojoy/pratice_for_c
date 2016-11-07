#!/usr/bin/env python
class SampleMore(object):
    def __call__(self, a):
        return a + 5
a=SampleMore()
print(a(2))
c=map(a,[2,4,5])
print c
class bird(object):
  fa=True
class chick(bird):
  fly=True
  def __init__(self,age):
    self.age=age
su=chick(2)
print(su.__dict__)
print(bird.__dict__)
print(chick.__dict__)
su.__dict__['age']=3
print(su.age)
f=open("new","w")
print(f.closed)
f.write("hello\n")
f.close()
print(f.closed)
class VOW(object):
    def __init__(self, text):
        self.text = text
    def __enter__(self):
        self.text = "I say: " + self.text    # add prefix
        return self                          # note: return an object
    def __exit__(self,exc_type,exc_value,traceback):
        self.text = self.text + "!"          # add suffix


with VOW("I'm fine") as myvow:
    print(myvow.text)

print(myvow.text)
