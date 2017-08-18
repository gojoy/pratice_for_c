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
    vector<int> t={1,2,4,7,11,15};
    vector<int> res;
    char c[2]="";
//    *c=NULL;
    char pr[2]=".";
    char *p;
    p=pr;
    cout<<s.match(c,p)<<"end"<<endl;
    
    
    
//    cout<<s.VerifySquenceOfBST(t)<<endl;
    return 0;
}

