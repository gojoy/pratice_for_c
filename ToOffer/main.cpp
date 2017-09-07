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

#undef TEST

#define TEST 0

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

//    ListNode *a,*b,*c,*d,*e,*f,*g,*res;
//    a=new ListNode(1);
//    b=new ListNode(2);
//    c=new ListNode(3);
//    d=new ListNode(3);
//    e=new ListNode(4);
//    f=new ListNode(5);
//    g=new ListNode(5);
//    a->next=b,b->next=c,c->next=d,d->next=e,e->next=f,f->next=g;
//    res=s.deleteDuplication(a);
//    while(res!=NULL) {
//        cout<<res->val<<" ";
//        res=res->next;
//    }
    
    string a;
    a="ababacabacbababaabcbac";
    string sub;
    sub="ababaca";
    s.KMPmatch(sub,a);
    
    
    return 0;
}
#endif
