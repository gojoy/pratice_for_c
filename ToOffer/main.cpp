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
#include "part1.h"

#if TEST==0

#include <cstdlib>
#include <string.h>
#include <iostream>
#include <vector>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    cerr<<"begin\n";
    Solution s;
    vector<int> pre={1,2,4,6,8,7,9,5,3};
    vector<int> mid={8,6,4,7,9,2,5,1,3};
    vector<int> res;
    TreeNode *t;
    t=s.reConstructBinaryTree(pre,mid);

    cout<<"print"<<endl;
    s.midPrintTree(t);
    cout<<endl<<"stack res is "<<endl;
    s.midPrintTree1(t);
    cout<<"knode is"<<s.KthNode(t,5)->Val<<endl;
    
//    res=s.PrintFromTopToBottom(t);
//    cout<<"show res"<<endl;
//    for (int i=0;i<res.size();i++) {
//        cout<<res[i]<<" ";
//    }
    cout<<endl;
    cout<<"distance is "<<s.maxDistanceTwoNode(t)<<endl;
    
    return 0;
}
#endif
