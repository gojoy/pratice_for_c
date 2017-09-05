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
#include <set>

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
    
    void postordertree(TreeNode *t);
    
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
     
//     判断二叉树是否平衡
     bool IsBalanced_Solution(TreeNode* pRoot);
     
//     输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
//     如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同
     bool VerifySquenceOfBST(vector<int> sequence);
     
//     输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
//     路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径
     vector<vector<int> > FindPath(TreeNode* root,int expectNumber);
     
//     输入两个链表，找出它们的第一个公共结点
     ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2);
     
//     一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字
     void FindNumsAppearOnce(vector<int> data,int* num1,int *num2);
     
//     输入一个递增排序的数组和一个数字S，在数组中查找两个数，是的他们的和正好是S，
//     如果有多对数字的和等于S，输出两个数的乘积最小的
     vector<int> FindNumbersWithSum(vector<int> array,int sum);
     
//     每次喊到m-1的那个小朋友要出列唱首歌,然后可以在礼品箱中任意的挑选礼物,并且不再回到圈中,从他的下一个小朋友开始,
//     继续0...m-1报数....这样下去....直到剩下最后一个小朋友。请你试着想下,哪个小朋友会得到这份礼品呢？
//     (注：小朋友的编号是从0到n-1)
     int LastRemaining_Solution(int n, int m);
     
//     求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
     int Sum_Solution(int n);
     
//     请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，
//     而'*'表示它前面的字符可以出现任意次（包含0次）。
//     在本题中，匹配是指字符串的所有字符匹配整个模式。
//     例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配
     bool match(char* str, char* pattern);
     
//     对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。
//     例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。
     string LeftRotateString(string str, int n);
     
//     请找出数组中任意一个重复的数字。 
//     例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2。
     bool duplicate(int numbers[], int length, int* duplication);
     
//     。如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。 
//     例如 a b c e s f c s a d e e 矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，
//     因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。
     bool hasPath(char* matrix, int rows, int cols, char* str);
     
private:
    TreeNode *constructtree(vector<int> pre,int lb,int le,vector<int> vin,int rb,int re);
    
    bool isSubTree(TreeNode *a,TreeNode *b);
    
    
//    int reminnumber(vector<int> a,int left,int right);
    
    
    stack<int> stack1;
    stack<int> stack2;
};

#endif /* PART1_H */

