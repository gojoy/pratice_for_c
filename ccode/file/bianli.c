#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <assert.h>
#include <dirent.h>

#define FILE_MODE (S_IRUER|S_IWUSR|S_IRGRP|S_IROTH)

static long nrge,ndir,nblk,nchr,nfifo,nslink,nsock,ntot;

typedef int Myfunc(const char *,const struct stat *,int);
typedef int Myint(int);
static Myint myint;
static Myfunc myfunc;
static int myftw(char *,Myfunc *);
static int dopath(Myfunc *);
static int next(Myint *);
static int myint(int n ){
 return n+1;
}
static int next(Myint func){
	printf("in next\n");
	return func(2)+1;
}

#define FTW_F 1;	//file 
#define FTW_D 2;	//directory
#define FTD_DNR 3;	//directory cannot read
#define FTW_NS 4;	//file cannot stat




int listdic(char *pth){
	DIR *dp;
	struct dirent *dirp;
	if((dp=opendir(pth))==NULL){
		printf("cannot open dir %s\n",pth );
		return -1;
	}
	while((dirp=readdir(dp))!=NULL){
		printf("file is  %s\n",dirp->d_name);
	}
	printf("finish\n");
	return 0;

}


int main(int argc, char const *argv[])
{
	printf("next is %d\n",next(myint) );
	if (argc!=2){
		printf("./aout + path\n");
		return -1;
	}
	char *ph;
	ph=argv[1];
	if(listdic(ph)<0){
		printf("list failed\n");
	}
	return 0;
}



