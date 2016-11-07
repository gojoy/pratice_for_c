#!/bin/bash
p1="$1"
case $p1 in
	start)
	echo "start is $p1"
	mysqld --defaults-file=my.cnf --user=mysql &>/dev/null &
;;
	stop)
	echo "stop is $1"
	mysqladmin -uroot -p -S mysql.sock shutdown
;;
esac
