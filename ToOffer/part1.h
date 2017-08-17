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
#include <queue>
#include <string>

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

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
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
     
//     输入一个链表，反转链表后，输出链表的所有元素
     ListNode* ReverseList(ListNode* pHead);
     
     
//     输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
     bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2);
     
//     输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
//     假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，
//     序列4，5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。
//     （注意：这两个序列的长度是相等的）
     bool IsPopOrder(vector<int> pushV,vector<int> popV);
     
//     从上往下打印出二叉树的每个节点，同层节点从左至右打印。
     vector<int> PrintFromTopToBottom(TreeNode* root);
     
     RandomListNode* Clone(RandomListNode* pHead);
     
//     输入一个字符串,按字典序打印出该字符串中字符的所有排列。
//     例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
     vector<string> Permutation(string str);
     
     void getallPermutation(string* str,int from,int to,vector<string>* res);
//     bool isswapp(string str, int from, int to);
//     数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
//     由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0
     int MoreThanHalfNum_Solution(vector<int> numbers);
     
//     输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
     vector<int> GetLeastNumbers_Solution(vector<int> input, int k);
     
     void showvec(vector<int> v);
     
//     最大子数组的和
     int FindGreatestSumOfSubArray(vector<int> array);
//     求到n之前所有数中1 出现的次数
     int NumberOf1Between1AndN_Solution(int n);
     
//     输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
//     例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323
     string PrintMinNumber(vector<int> numbers);
     
//     在一个字符串(1<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置
     int FirstNotRepeatingChar(string str);
     
     
     int InversePairs(vector<int> data);
     
//     统计一个数字在排序数组中出现的次数
     int GetNumberOfK(vector<int> data ,int k);
     
     
//     输入一棵二叉树，求该树的深度。
//     从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。
     int TreeDepth(TreeNode* pRoot);
     
     
     bool IsBalanced_Solution(TreeNode* pRoot);
     
private:
    TreeNode *constructtree(vector<int> pre,int lb,int le,vector<int> vin,int rb,int re);
    
    bool isSubTree(TreeNode *a,TreeNode *b);
    
    
//    int reminnumber(vector<int> a,int left,int right);
    
    
    stack<int> stack1;
    stack<int> stack2;
};

#endif /* PART1_H */
