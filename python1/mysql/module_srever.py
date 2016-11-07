#!/usr/bin/env python


import MySQLdb as _connector
import collections
import warnings

class Server(object):
    """A representation of a MySQL server.

    A server object is used as a proxy for operating with the
    server. The basic primitives include connecting to the server and
    executing SQL statements and/or shell commands."""

    class Row(object):
        """A row (iterator) returned when executing an SQL statement.

        For statements that return a single row, the object can be
        treated as a row as well.

        """
        
        def __init__(self, cursor):
            self.__cursor = cursor
            self.__row = cursor.fetchone()

        def __iter__(self):
            return self

        def next(self):
            row = self.__row
            if row is None:
                raise StopIteration
            else:
                self.__row = self.__cursor.fetchone()
                return row

        def __getitem__(self, key):
            #from mysql.replicant.errors import EmptyRowError
            if self.__row is not None:
                return self.__row[key]
            else:
                print 'null row error'
        def __str__(self):
            #from mysql.replicant.errors import EmptyRowError
            if len(self.__row) == 1:
                return str(self.__row.values()[0])
            else:
                print 'null error'
    def __init__(self, sql_user_name,sql_user_passwd,
                  host, port):

        self.sql_user_name = sql_user_name
        self.sql_user_passwd=sql_user_passwd
        self.host = host
        self.__conn = None
        self.port=port

    def _connect(self):
        """Method to connect to the server, preparing for execution of
        SQL statements.  If a connection is already established, this
        function does nothing."""
        #self.db=database
        if not self.__conn:
            self.__conn = _connector.connect(
                host=self.host, port=self.port,
                #db=self.db,
                user=self.sql_user_name,
                passwd=self.sql_user_passwd,charset="utf8")
        #elif database:
         #   self.__conn.select_database(database)


    def disconnect(self):
        self.__conn.close()
        self.__conn = None
        return self

    def sql(self,sql):
        self.sqloo=sql
        """Execute a SQL command on the server.

        This first requires a connection to the server.

        The function will return an iteratable to the result of the
        execution with one row per iteration.  The function can be
        used in the following way::

           for database in server.sql("SHOW DATABASES")
              print database["Database"]

        """
        
        self._connect()
        cur=self.__conn.cursor(_connector.cursors.DictCursor)
        cur.execute(self.sqloo)
        return Server.Row(cur)

    '''cur = self.__conn.cursor(_connector.cursors.DictCursor)
        with warnings.catch_warnings(record=True) as warn:
            cur.execute(command, args)
            self.__warnings = warn
        return Server.Row(cur)
        '''

    def ssh(self, command):
        """Execute a shell command on the server.

        The function will return an iteratable (currently a list) to
        the result of the execution with one line of the output for
        each iteration.  The function can be used in the following
        way:

        for line in server.ssh(["ls"])
            print line

        For remote commands we do not allow X11 forwarding, and the
        stdin will be redirected to /dev/null.

        """

        from subprocess import Popen, PIPE, STDOUT

        if self.host == "localhost":
            cmd = ["sudo", "-u" + self.ssh_user.name] + command
            process = Popen(cmd, stdout=PIPE, stderr=STDOUT)
        else:
            fullname = self.ssh_user.name + "@" + self.host
            process = Popen(["ssh", "-fqTx", fullname, ' '.join(command)],
                            stdout=PIPE, stderr=STDOUT)
        output = process.communicate()[0]
        return output.split("\n")


'''
    def fetch_config(self, path=None):
        return self.__config_manager.fetch_config(self, path)

    def replace_config(self, config, path=None):
        self.__config_manager.replace_config(self, config, path)
        return self
'''

'''
    def stop(self):
        self.__machine.stop_server(self)
        return self

    def start(self):
        self.__machine.start_server(self)
        return self
'''
if __name__=="__main__":
    user="root"
    pd="123456"
    host="127.0.0.1"
    host1="localhost"
    port=3378
    sql1="show master status"
    sql4="use mysql"
    sql2="select * from z1"
    sql3="select * from user"
    a=Server(user,pd,host,port)
    r1=a.sql(sql4)
    result=a.sql(sql3)
    print result["User"]
    print type(result),type(r1)
    #print result["Position"]

