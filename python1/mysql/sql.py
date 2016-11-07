#!/usr/bin/env python
#coding=utf8
import MySQLdb
h="localhost"
h1="127.0.0.1"
u="user"
p="123456"
po="3379"
d="mysql"
cod="utf8"
sql="select * from st"
sql1="show master status"
sql2="show create table st"
sql3="show slave status"
sql4="use mysql"
sql5="select * from user"
sql6='use ha'
id1=101
name="xiaolin"
sql7="insert into st values(id,name) values({0},{1})".format(id1,name)
sql8="insert into st values(%s,%s)"
#print p,po
'''

conn = MySQLdb.connect(port=3379,host=h1,user="root",passwd="123456",db=d,charset="utf8")
#conn=MySQLdb.connect(host=h,user=u,passwd=p,db=d,port=po,charset=cod)
cur=conn.cursor()
cur.execute(sql1)
lines=cur.fetchall()
print lines,"woo"
for line in lines:
  print line
'''
class server(object):
  def link(self,port):
    self.port=int(port)
    try:
      self.conn = MySQLdb.connect(host=h1,port=self.port,user="root",passwd="123456",db="mysql",charset="utf8")
    except Exception, e:
      print e
      return 0
    return 1
  def initcur(self):
    self.cur=self.conn.cursor()
  def sql(self,sql1,args=None):
    self.cur.execute(sql1,args)
  def getsql(self):
    lines=self.cur.fetchall()
    return lines
  def commit(self):
    self.conn.commit()
  def close(self):
    self.conn.close()
if __name__=="__main__":
  ud=5
  uname="daxiaolin"
  s1='select * from st where id > %d'%(ud)
  s2='insert into st values("%d","%s")'%(ud,uname)
  a=server()
  l=a.link(3378)
  if(l==1):
    a.initcur()
#    a.sql(sql4)
 #   a.sql(sql5)
    a.sql(sql6)
    a.sql(s2)
    a.commit()
    s=a.getsql()
    for line in s:
      print  line
    a.close()
  else:
    print 'link error'

