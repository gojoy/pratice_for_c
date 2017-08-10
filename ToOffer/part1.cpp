/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "part1.h"


//利用二维数组由上到下，由左到右递增的规律，
//那么选取右上角或者左下角的元素a[row][col]与target进行比较，
//当target小于元素a[row][col]时，那么target必定在元素a所在行的左边,
//即col--；
//当target大于元素a[row][col]时，那么target必定在元素a所在列的下边,
//即row++；

bool Solution::Find(int target, vector<vector<int> > array) {
    if (array.empty() == 0)
        return false;

    int x, y, row, col;
    row = array.size();
    col = array[0].size();

    if (target > array[row - 1][col - 1] || target < array[0][0])
        return false;

    y = row - 1;
    x = 0;

    while (y >= 0 && x <= col - 1) {
        int v = array[y][x];
        if (v == target)
            return true;
        else if (v < target)
            x++;
        else
            y--;
    }
    return false;
}

void Solution::replaceSpace(char* str, int length) {
    int countspace = 0;
    if (length == 0)
        return;
    cout << "length is " << length << endl;
    int i = 0;
    while (i < length) {
        if (str[i++] == ' ') {
            cout << "i is " << i << endl;
            countspace++;
        }
    }
    printf("str is %s\n", str);
    str = (char *) realloc(str, sizeof (char)*(length + 2 * countspace));
    cout << "space is " << countspace << endl;
    if (str == NULL) {
        cout << "str null" << endl;
        return;
    }
    printf("str is %s\n", str);

}

TreeNode* Solution::reConstructBinaryTree(vector<int> pre, vector<int> vin) {
    if (pre.size() != vin.size()) {
        return NULL;
    }

    TreeNode *res;
    res = constructtree(pre, 0, pre.size() - 1, vin, 0, vin.size() - 1);
    return res;

}

TreeNode *Solution::constructtree(vector<int> pre, int lb, int le, vector<int> vin, int rb, int re) {
    if (lb > le || rb > re) {
        return NULL;
    }
    TreeNode *res = new TreeNode(pre[lb]);
    for (int i = 0; i < vin.size(); i++) {
        if (pre[lb] == vin[i]) {
            res->left = constructtree(pre, lb + 1, lb + i - rb, vin, rb, i - 1);
            res->right = constructtree(pre, lb + i - rb + 1, le, vin, i + 1, re);
        }
    }
    return res;
}

void Solution::push(int node) {
    stack1.push(node);
}

int Solution::pop() {
    int res;
    while (!stack1.empty()) {
        stack2.push(stack1.top());
        stack1.pop();
    }
    res = stack2.top();
    stack2.pop();
    while (!stack2.empty()) {
        stack1.push(stack2.top());
        stack2.pop();
    }
    return res;
}

int Solution::minNumberInRotateArray(vector<int> rotateArray) {
    if (rotateArray.empty())
        return 0;
    int l = rotateArray.size();
    cout << rotateArray[l - 1] << endl;
    return reminnumber(rotateArray, 0, l - 1);
}

int Solution::reminnumber(vector<int> a, int left, int right) {
    if (left > a.size() - 1 || right > a.size() - 1) {
        throw "out";
    }
    //    cout<<left<<right<<endl;
    if (left >= right) {
        cout << a[left];
        throw "==";
        return a[left];
    }

    int mid;
    mid = (left + right) / 2;
    if (a[left] >= a[mid] && a[mid] < a[right])
        return reminnumber(a, left, mid);
    else
        return reminnumber(a, mid, right);
}

int Solution::minnumber(vector<int> a, int left, int right) {
    int mid;

    while (left < right) {
        mid = (left + right) / 2;

        if (right - left == 1) {
            break;
        }

        if (a[left] >= a[mid] && a[mid] <= a[right]) {
            right = mid;
        } else {
            left = mid;
        }
    }
    if (a[right] < a[left])
        return a[right];
    else
        return a[left];
}

int Solution::Fibonacci(int n) {
    vector<int> a={0,1};
    if(n<2) 
        return a[n];
    
    for (int i=2;i<=n;i++) {
        a.push_back(a[i-1]+a[i-2]);
    }
    return a[n];
    
}

int Solution::jumpFloorII(int number) {
    
    vector<int> a={0,1};
    int sum;
    if(number<2)
        return a[number];
    
    for(int i=2;i<=number;i++) {
        sum=0;
        for (int j=0;j<i;j++) {
            cout<<"sum is"<<sum<<endl;
            sum+=a[j];
        }
        
        a.push_back(sum+1);
    }
    return a[number];
}

int Solution::NumberOf1(int n) {

    int c = 0;
    while (n != 0) {
            c++;
        n = n & (n - 1);
    }
    return c;
}


double Solution::Power(double base, int exponent) {

    double res;
    int e=exponent;
    res = base;
    if (exponent < 0)
        e = -exponent;
    for (int i = 1; i < e; i++) {
        res = res*base;
    }
    if (exponent < 0)
        res = 1 / res;

    return res;
}

void Solution::reOrderArray(vector<int>& array) {
    
    vector<int> t;
    t.swap(array);
//    t.assign(array.begin(),array.end());
    for(int i=0;i<t.size();i++) {
        if(t[i]%2!=0)
            array.push_back(t[i]);
    }
    for(int i=0;i<t.size();i++) {
        if(t[i]%2==0)
            array.push_back(t[i]);
    }
    return;
}

 ListNode* Solution::FindKthToTail(ListNode* pListHead, unsigned int k) {
     
     if(pListHead==NULL)
         return NULL;
     
     ListNode *head;
     head=pListHead;
     ListNode *end;
     end=pListHead;
     
     int count=0;
     while(end) {
         count++;
         if(count>k)
             head=head->next;
         end=end->next;
     }
     if(count<k)
         return NULL;
     return head;
 }
 
 
  ListNode* Solution::ReverseList(ListNode* pHead){
      
      ListNode *h,*p,*tmp;
      h=NULL;
      tmp=NULL;
      
      p=pHead;
      while(p) {
          tmp=p->next;
          p->next=h;
          h=p;
          p=tmp;
      }
   
      return h;
      
  }
  
  
  bool Solution::HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {

      if(pRoot1==NULL || pRoot2==NULL)
          return false;
     
      return isSubTree(pRoot1,pRoot2) || HasSubtree(pRoot1->left,pRoot2) || HasSubtree(pRoot1->right,pRoot2);
         
  }
  
  bool Solution::isSubTree(TreeNode* a, TreeNode* b) {
      if(b==NULL) 
          return true;
      if(a==NULL)
          return false;
      if(a->Val==b->Val)
          return isSubTree(a->left,b->left) &&isSubTree(a->right,b->right);
      else 
          return false;
  }
  