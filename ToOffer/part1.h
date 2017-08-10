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
#include <stack>

using namespace std;

struct TreeNode {
    int Val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):Val(x),left(NULL),right(NULL){};
};

struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int x) :
    val(x), next(NULL) {
    }
};

class Solution {
public:
    //在一个二维数组中，每一行都按照从左到右递增的顺序排序，
    //每一列都按照从上到下递增的顺序排序。请完成一个函数，
    //输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
    bool Find(int target, vector<vector<int> > array);
    
//    请实现一个函数，将一个字符串中的空格替换成“%20”。
//    例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
    void replaceSpace(char *str,int length);
    
//    输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
//    例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin);
    
    void push( int node);
    int pop();
    
//    把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 
//    输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。 
//    例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 
//    NOTE：给出的所有元素都大于0,若数组大小为0，请返回0。
    int minNumberInRotateArray(vector<int> rotateArray);
    int reminnumber(vector<int> a,int left,int right);
    int minnumber(vector<int> a,int left,int right);
    
//    大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。
    int Fibonacci(int n);
    
//    一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
    int jumpFloorII(int number);
    
//    输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
     int  NumberOf1(int n);
     
     
     double Power(double base, int exponent);
     
//     输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，
//     所有的偶数位于位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
     void reOrderArray(vector<int> &array);
     
//     输入一个链表，输出该链表中倒数第k个结点。
     ListNode* FindKthToTail(ListNode* pListHead, unsigned int k);
     
private:
    TreeNode *constructtree(vector<int> pre,int lb,int le,vector<int> vin,int rb,int re);
//    int reminnumber(vector<int> a,int left,int right);
    
    
    stack<int> stack1;
    stack<int> stack2;
};

#endif /* PART1_H */

