#include "apue.h"
#include<pthread.h>
pthread_t ntid,ntid1;
int exitcode=111;
int num=1;
pthread_mutex_t mutex;
pthread_cond_t con1;


void printids(const char *s){
	pid_t pid;
	pthread_t tid;
	pid=getpid();
	tid=pthread_self();
	printf("%s pid is %d,tid is %d\n",s,pid,tid);
}

void *thr_fn1(){
	while(1){
	if(pthread_mutex_lock(&mutex)!=0){
		printf("thread1 mutex error\n");
	}
	printf("in thread2 num is %d,begin to wait cont\n",num);
	pthread_cond_wait(&con1,&mutex);
	printf("now cond wait ok\n");
	/*
	if(pthread_join(ntid,(void *)&errcode)!=0){
		printf("thread2 join 1 error\n");
	}
	printf("in thread2 join thread1 code is %d\n",(int)*errcode);
	*/
	if(pthread_mutex_unlock(&mutex)!=0){
		printf("thread1 re mutex error\n");
	}
	}
	pthread_exit((void *)2);
	
}

void *thr_fn(){
	int c;
	if(pthread_mutex_lock(&mutex)!=0){
		printf("thread2 mutex error\n");
		exit(-1);
	}
	printf("in thread1 first num is %d\n",num);
	num++;
	if(pthread_mutex_unlock(&mutex)!=0){
		printf("thread2 re mutex error\n");
	}
	for( c=0;c<3;c++){
	sleep(2);
	printf("thread1 start sigal %d \n",c);
	pthread_cond_signal(&con1);
	}

	pthread_exit((void *)&exitcode);
}


int main(){
	int err;
	int  **breakcode;
	int b1;

	if(pthread_cond_init(&con1,NULL)!=0){
		printf("cont init error\n");
		exit(-1);
	}
	if(pthread_mutex_init(&mutex,NULL)!=0){
		printf("init mutex error\n");
		exit(-1);
	}
	printf("begin num is %d\n",num);
	err=pthread_create(&ntid,NULL,thr_fn,NULL);
	if(err!=0){
		printf("create thread error\n");
		exit(-1);
	}

	err=pthread_create(&ntid1,NULL,thr_fn1,NULL);
	if(err!=0){
		printf("create thread2 error\n");
		exit(-1);
	}

	err=pthread_join(ntid,(void *)breakcode);
	if(err!=0){
		printf("main join error\n");
	}
	printf("thread1 exit code is %d,num is %d\n",(int)**breakcode,num);

	err=pthread_join(ntid1,(void *)&b1);
	if(err!=0){
		printf("join 2 error");
	}else{
		printf("thread2 exitcode is %d\n",b1);
	}
	return 0;

}
