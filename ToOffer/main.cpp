/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: gg
 *
 * Created on 2017年7月31日, 下午4:23
 */

#include <cstdlib>
#include <string.h>
#include <iostream>
#include <vector>
#include "part1.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    Solution s;
    char buf[100]="hello world hello";
    char *buf1=(char *)malloc(sizeof(char)*100);
    sprintf(buf1,"hello world");
    printf("buf1 is %s\n",buf1);
    s.replaceSpace(buf,strlen(buf));
//    buf="hello";
    cout<<buf<<endl;
    buf[1]='%%';
    cout<<buf<<endl;
    return 0;
}

