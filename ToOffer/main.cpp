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
    vector<int> a={1,2,4,7,11,16};
    vector<int> res;
    res=s.FindNumbersWithSum(a,17);
    cout<<"len is "<<res.size()<<endl;
    return 0;
}
#endif
