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
    vector<int> t={5,4,3,2,1};
    TreeNode *a,*b,*c,*d,*e;
    a=new TreeNode(1);
    b=new TreeNode(2);
    c=new TreeNode(3);
    d=new TreeNode(4);
    e=new TreeNode(5);
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    s.FindPath(a,3);
    
//    cout<<s.VerifySquenceOfBST(t)<<endl;
    return 0;
}

