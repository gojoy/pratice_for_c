#!/usr/bin/env python
import cmd 
import sql as db
import rand
import time
if __name__=="__main__":
  getrand=rand.randil()
  num=getrand.getnum()
  nstr=getrand.getstr()
  print num,nstr
  sql0='use ha'
  sql1='insert into score(name,scores) values("%s","%s")'%(nstr,num)
  print sql1
  server=db.server()
  localtime = time.asctime( time.localtime(time.time()) )
  print 'before insert' , localtime
  if (server.link(3378)==1):
    server.initcur()
    i=1
    server.sql(sql0)
    while(i<100000):
      num=getrand.getnum()
      nstr=getrand.getstr()
      sql1='insert into score(name,scores) values("%s","%s")'%(nstr,num)
      server.sql(sql1)
      i=i+1
      server.commit()
    server.close()
    localtime = time.asctime( time.localtime(time.time()) )
    print 'after insert',localtime
  else:
    print 'link error'
'''
  a=cmd.putout()
  inms=int(a.cin())
  print inms,type(inms)
  server=sql.server()
  link=server.link(inms)
  if link==1:
    a1=cmd.putout()
    sql=a1.cin()
    ret=server.sql(sql)
    for line in ret:
      print line 
    ##print ret
  else:
    print 'error'
  server.close()
'''
