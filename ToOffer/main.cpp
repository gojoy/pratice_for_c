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
    vector<int> a={1,2,3,4,5};
    vector<int> b={4,6,3,2,1};
    cout<<s.IsPopOrder(a,b);
    return 0;
}

