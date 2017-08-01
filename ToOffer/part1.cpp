/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "part1.h"


//利用二维数组由上到下，由左到右递增的规律，
//那么选取右上角或者左下角的元素a[row][col]与target进行比较，
//当target小于元素a[row][col]时，那么target必定在元素a所在行的左边,
//即col--；
//当target大于元素a[row][col]时，那么target必定在元素a所在列的下边,
//即row++；
bool Solution::Find(int target, vector<vector<int> > array) {
   if( array.empty()==0 )
        return false;

   int x,y,row,col;
   row=array.size();
   col=array[0].size();
   
   if(target > array[row-1][col-1] || target <array[0][0])
       return false;
   
   y=row-1;
   x=0;
   
   while( y>=0 && x<=col-1) {
       int v=array[y][x];
       if( v==target)
           return true;
       else if(v<target)
           x++;
       else 
           y--;
   }
    return false;
}

void Solution::replaceSpace(char* str, int length) {
    int countspace=0;
    if (length==0)
        return;
    cout<<"length is "<<length<<endl;
    int i=0;
    while(i<length) {
        if(str[i++]==' ') {
            cout<<"i is "<<i<<endl;
            countspace++;
        }
    }
    printf("str is %s\n",str);
    str=(char *)realloc(str,sizeof(char)*(length+2*countspace));
     cout<<"space is "<<countspace<<endl;
     if (str==NULL) {
         cout<<"str null"<<endl;
         return;
     }
     printf("str is %s\n",str);
     
    
    
}
