// char.cpp : 定义控制台应用程序的入口点。
//



#include <stdio.h>
#include <stdlib.h>

int muttable(int row, int col, int rank);

int main(){
  int r, c, k;
  printf("begin\n");
  if(scanf("%d,%d,%d",&r, &c, &k)<0){
	  printf("scanf error\n");
	  return -1;
  }
  printf("%d %d %d\n",r,c,k);
  muttable(r, c, k);
  printf("end\n");
  return 0;
}

int muttable(int row, int col, int rank) {
  int *p, temp, pos, i;
  if((row<= 0)&& (col<= 0)){
    return -1;
  }
  p=(int *)malloc(row*col*sizeof(int));
  if(p==NULL) {
    return -1;
  }
  for(int i=1; i<row+1; i++){
    for(int j=1;j<col+1; j++){
      *(p++)=i*j;
    }
  }

  for(int l=0;l<row*col;l++){
	  printf("p l is %d,%d",l,*(p+l));
  }

  for( i=0; i<rank; i++){
    pos=i;
    for(int j=i+1; j<row*col; j++){
      if(*(p+j)>*(p+pos))
        pos=j;
    }
    temp=*(p+i);
    *(p+i)=*(p+pos);
    *(p+pos)=temp;
  }
  printf("i is %d,num is %d\n",i,*(p+i));
  return *(p+rank);
  
}

