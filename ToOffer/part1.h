/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   part1.h
 * Author: gg
 *
 * Created on 2017年7月31日, 下午4:24
 */

#ifndef PART1_H
#define PART1_H

#include <vector>
#include <iostream>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class Solution {
public:
    //在一个二维数组中，每一行都按照从左到右递增的顺序排序，
    //每一列都按照从上到下递增的顺序排序。请完成一个函数，
    //输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
    bool Find(int target, vector<vector<int> > array);
    
//    请实现一个函数，将一个字符串中的空格替换成“%20”。
//    例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
    void replaceSpace(char *str,int length);
};

#endif /* PART1_H */

