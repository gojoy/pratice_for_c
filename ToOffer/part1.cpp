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

void Solution::showvec(vector<int> v) {
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << endl;
    ;

}

void swap(int &a, int &b) {
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
    return;
}

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

 void Solution::postordertree(TreeNode *t) {
     if (t==NULL)
         return;
     postordertree(t->left);
     postordertree(t->right);
     printf("%d ",t->Val);
     
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
    for (int i = rb; i <=re; i++) {
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
    vector<int> a = {0, 1};
    if (n < 2)
        return a[n];

    for (int i = 2; i <= n; i++) {
        a.push_back(a[i - 1] + a[i - 2]);
    }
    return a[n];

}

int Solution::jumpFloorII(int number) {

    vector<int> a = {0, 1};
    int sum;
    if (number < 2)
        return a[number];

    for (int i = 2; i <= number; i++) {
        sum = 0;
        for (int j = 0; j < i; j++) {
            cout << "sum is" << sum << endl;
            sum += a[j];
        }

        a.push_back(sum + 1);
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
    int e = exponent;
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
    for (int i = 0; i < t.size(); i++) {
        if (t[i] % 2 != 0)
            array.push_back(t[i]);
    }
    for (int i = 0; i < t.size(); i++) {
        if (t[i] % 2 == 0)
            array.push_back(t[i]);
    }
    return;
}

ListNode* Solution::FindKthToTail(ListNode* pListHead, unsigned int k) {

    if (pListHead == NULL)
        return NULL;

    ListNode *head;
    head = pListHead;
    ListNode *end;
    end = pListHead;

    int count = 0;
    while (end) {
        count++;
        if (count > k)
            head = head->next;
        end = end->next;
    }
    if (count < k)
        return NULL;
    return head;
}

ListNode* Solution::ReverseList(ListNode* pHead) {

    ListNode *h, *p, *tmp;
    h = NULL;
    tmp = NULL;

    p = pHead;
    while (p) {
        tmp = p->next;
        p->next = h;
        h = p;
        p = tmp;
    }

    return h;

}

bool Solution::HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {

    if (pRoot1 == NULL || pRoot2 == NULL)
        return false;

    return isSubTree(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);

}

bool Solution::isSubTree(TreeNode* a, TreeNode* b) {
    if (b == NULL)
        return true;
    if (a == NULL)
        return false;
    if (a->Val == b->Val)
        return isSubTree(a->left, b->left) && isSubTree(a->right, b->right);
    else
        return false;
}

bool Solution::IsPopOrder(vector<int> pushV, vector<int> popV) {

    vector<int> tmp;
    for (int i = 0, j = 0; i < pushV.size();) {
        tmp.push_back(pushV[i++]);
        while (tmp.back() == popV[j] && j < popV.size()) {
            tmp.pop_back();
            j++;
        }
    }
    for (auto i : tmp)
        cout << i;
    return tmp.empty();
}

vector<int> Solution::PrintFromTopToBottom(TreeNode* root) {

    
    TreeNode *tmp;
    vector<int> res;
     if (root==NULL) {
        cerr<<"print error:root NULL\n"<<endl;
        return res;
    }
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        tmp = q.front();
        res.push_back(tmp->Val);
        cout<<tmp->Val;
        q.pop();
        if (tmp->left)
            q.push(tmp->left);
        if (tmp->right)
            q.push(tmp->right);
    }
    return res;
}

TreeNode* Solution::KthNode(TreeNode* pRoot, int k) {
     if (pRoot==NULL)
        return NULL;
    stack<TreeNode*> s;
    TreeNode *t;
    t=pRoot;
    while(t) {
        s.push(t);
        t=t->left;
    }
    while(!s.empty()){
        t=s.top();
        if(k==1) {
            return t;
        }
//        cout<<t->Val<<" ";
        s.pop();
        k--;
        if (t->right)
            s.push(t->right);
    }
    return t;
}

void Solution::prePrintTree(TreeNode *t) {
    if (t==NULL)
        return;
    cout<<t->Val<<" ";
    prePrintTree(t->left);
    prePrintTree(t->right);
}

void Solution::midPrintTree1(TreeNode *root) {
    if (root==NULL)
        return;
    stack<TreeNode*> s;
    TreeNode *t;
    t=root;
    while(t) {
        s.push(t);
        t=t->left;
    }
    while(!s.empty()){
        t=s.top();
        cout<<t->Val<<" ";
        s.pop();
        if (t->right)
            s.push(t->right);
    }
}

void Solution::midPrintTree(TreeNode *t) {
    if (t==NULL)
        return;
    midPrintTree(t->left);
    cout<<t->Val<<" ";
    
    midPrintTree(t->right);
}

void Solution::postPrintTree(TreeNode *t) {
    if (t==NULL)
        return;
    postPrintTree(t->left);
    postPrintTree(t->right);
    cout<<t->Val<<" ";
}

void Solution::printTree(TreeNode *t) {
    if (t==NULL)
        return;
    queue< TreeNode *> q;
    TreeNode *tmp;
    tmp=t;
    q.push(tmp);
    int l=0;
    while(!q.empty()) {
        l=q.size();
        while(l--) {
            tmp=q.front();
            cout<<tmp->Val<<" ";
            q.pop();
            if (tmp->left)
                q.push(tmp->left);
            if(tmp->right)
                q.push(tmp->right);
        }
        cout<<endl;
    }
}

void cloneall(RandomListNode *p) {
    RandomListNode *pnode, *c;
    pnode = p;
    while (pnode != NULL) {
        c = new RandomListNode(pnode->label);
        c->next = pnode->next;
        pnode->next = c;
        pnode = c->next;
    }
}

void addRandom(RandomListNode *p) {
    RandomListNode *pnode, *c;
    pnode = p;
    while (pnode != NULL) {
        c = pnode->next;
        if (pnode->random)
            c->random = pnode->random->next;
        pnode = c->next;
    }

}

RandomListNode* getclone(RandomListNode *p) {

    RandomListNode *h, *res, *clone;
    h = p;
    res = h->next;
    while (h != NULL) {
        clone = h->next;
        h->next = clone->next;
        h = h->next;
        if (h != NULL)
            clone->next = h->next;
    }
    return res;
}

RandomListNode* Solution::Clone(RandomListNode* pHead) {
    if (pHead == NULL)
        return NULL;
    cloneall(pHead);
    addRandom(pHead);
    return getclone(pHead);

}

vector<string> Solution::Permutation(string str) {
    vector<string> res;

    getallPermutation(&str, 0, str.size() - 1, &res);
    return res;
}

bool isswapp(string str, int from, int to) {
    //    cout << "str is " << str << " from is " << from << " to is " << to << endl;
    for (int i = from; i < to; i++) {
        if (str[i] == str[to]) {

            return false;
        }
    }
    return true;
}

void Solution::getallPermutation(string* str, int from, int to, vector<string>* res) {

    if (from == to) {
        res->push_back(*str);
    } else {
        for (int j = from; j <= to; j++) {
            if (isswapp(*str, from, j)) {
                swap((*str)[j], (*str)[from]);
                getallPermutation(str, from + 1, to, res);
                swap((*str)[j], (*str)[from]);
            }
        }
    }
    return;
}

int Solution::MoreThanHalfNum_Solution(vector<int> numbers) {

    int len = numbers.size();
    int num;
    int times = 1;
    if (len == 0)
        return 0;
    if (len == 1)
        return numbers[0];
    num = numbers[0];
    for (int i = 1; i < len; i++) {
        if (numbers[i] == num)
            times++;
        else
            times--;

        if (times <= 0) {
            num = numbers[i];
            times = 1;
        }
        //        cout<<"i is "<<i<<"times is "<<times<<" num is "<<num<<endl;
    }
    times = 0;
    for (int i = 0; i < len; i++) {
        if (numbers[i] == num)
            times++;
    }
    if (times > len / 2)
        return num;
    else
        return 0;
}

vector<int> Solution::GetLeastNumbers_Solution(vector<int> input, int k) {
    int len = input.size();
    vector<int> res;
    if (k > len)
        return res;
    vector<int> other;
    auto l = input.begin();
    for (int i = 0; i < k; i++)
        l++;
    res.assign(input.begin(), l);
    other.assign(l, input.end());
    //    cout<<"res is";
    //    showvec(res);
    //    cout<<"other len is "<<other.size()<<endl;
    //    showvec(other);

    int rlen = other.size();
    int rmin;
    int min;

    for (int i = 0; i < k; i++) {
        min = i;
        rmin = 0;
        for (int j = i; j < k; j++) {
            //            cout<<res[j];
            if (res[j] < res[min])
                min = j;
        }
        //            cout<<"left ri is "<<res[min]<<endl;
        swap(res[min], res[i]);

        for (int r = 0; r < rlen; r++) {
            if (other[r] < other[rmin])
                rmin = r;
        }
        //            cout<<"rmax is "<<other[rmin]<<endl;
        if (res[min] > other[rmin])
            swap(res[min], other[rmin]);
        //            cout<<"ri is "<<res[i]<<endl;
    }
    return res;
}

int max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

int Solution::FindGreatestSumOfSubArray(vector<int> array) {
    int currsum = 0;
    int maxsum = array[0];
    for (int i = 0; i < array.size(); i++) {
        currsum = max(array[i], currsum + array[i]);
        maxsum = max(maxsum, currsum);
    }
    return maxsum;
}

//分别判断每一位的1的个数，由低到高诸位判断，其中每一位的个数都和高位ihighnum与地位ilowernum有关。

int Solution::NumberOf1Between1AndN_Solution(int n) {
    if (n <= 0)
        return 0;
    int res = 0;
    int ifactor = 1;
    int icurrnum = 0;
    int ilowernum = 0;
    int ihighnum = 0;
    while (n / ifactor != 0) {
        ilowernum = n - (n / ifactor) * ifactor;
        icurrnum = (n / ifactor) % 10;
        ihighnum = n / (ifactor * 10);
        switch (icurrnum) {
            case 0:
                //                当该位为0时，1的个数等于高位的数字*当前位数 20 h=2,c=0,l=0 个位1个数=2*1
                res += ihighnum*ifactor;
                break;
            case 1:
                //                当该位为1时，1个数=高位个数*当前位数+低位个数+1 212时，h=2，c=1；low=2；十位的1个数为2*10+2+1
                res += ihighnum * ifactor + ilowernum + 1;
                break;
            default:
                //                当该位为其他>1时，1个数=（高位个数+1）*当前位数 23，h=2,c=3,l=0 个位1个数=（2+1） *1
                res += (ihighnum + 1) * ifactor;
                break;
        }
        ifactor *= 10;
        //        cout<<"low is "<< ilowernum <<" cur is "<<icurrnum<<" high is "<<ihighnum<<endl;
    }
    return res;
}

//static bool cmp(int a,int b) {
//    string A=std::to_string(a)+to_string(b);
//    string B=to_string(b)+to_string(a);
//    return A<B;
//}
//
//string Solution::PrintMinNumber(vector<int> numbers) {
//        int len = numbers.size();
//        if(len == 0) return "";
//        sort(numbers.begin(), numbers.end(), cmp);
//        string res;
//        for(int i = 0; i < len; i++){
//            res += to_string(numbers[i]);
//        }
//        return res;
//}
//
//int Solution::FirstNotRepeatingChar(string str) {
//    if(str.size()==0)
//        return 0;
//    
//    vector<int> tb(58,-1);
//    int res=10000;
//
//    for(int i=0;i<str.size();i++) {
//        int pos=str[i]-'A';
////        cout<<str[i]<<" pos is "<<pos<<" i is "<<i<<endl;
//        if(tb[pos]==-1) {
//            tb[pos]=i;
//        } else if(tb[pos]==-2) {
//            continue;
//        } else if(tb[pos]>=0) {
//            tb[pos]=-2;
//        }
//    }    
//        for(int i=0;i<tb.size();i++) {
//        cout<<tb[i]<<" ";
//    }   
//    for(int j=0;j<58;j++ ) {
//        if (tb[j]>=0) {
//            if(tb[j]<res)
//                res=tb[j];
//        }
//    }
//    return res;
//}

int Solution::FirstNotRepeatingChar(string str) {
    if (str.size() == 0)
        return -1;
    char ch[256] = {0};
    for (int i = 0; i < str.size(); i++)
        ch[str[i]]++;

    for (int i = 0; i < 256; i++) {
        printf("%d ", ch[i]);
    }
    cout << endl;

    for (int i = 0; i < str.size(); i++)
        if (ch[str[i]] == 1)
            return i;
    return 0;
}
//
//int Solution::InversePairs(vector<int> data) {
//    int len=data.size();
//    int count=0;
//    if(len<2)
//        return 0;
//    for(int i=0;i<len-1;i++) {
//        for(int j=i+1;j<len;j++) {
//            if(data[i]>data[j])
//                count++;
//        }
//    }
//    return count%1000000007;
//}

long long InversePairsCore(vector<int> &data, vector<int> &copy, int start, int end) {
    //    cout<<"inv start is "<<start<<"end is "<<end<<endl;
    if (start == end) {
        //        copy[start] = data[start];
        return 0;
    }
    int length = (end - start) / 2;
    long long left = InversePairsCore(copy, data, start, start + length);
    long long right = InversePairsCore(copy, data, start + length + 1, end);

    int i = start + length;
    int j = end;
    int indexcopy = end;
    long long count = 0;
    while (i >= start && j >= start + length + 1) {
        if (data[i] > data[j]) {
            copy[indexcopy--] = data[i--];
            count = count + j - start - length; //count=count+j-(start+length+1)+1;
        } else {
            copy[indexcopy--] = data[j--];
        }
    }
    //    cout<<"copy is indexcopy is " << indexcopy<<endl;
    //    for(int i=0;i<copy.size();i++) {
    //        cout<<copy[i]<<" ";
    //    }
    //    cout<<endl;

    for (; i >= start; i--)
        copy[indexcopy--] = data[i];
    for (; j >= start + length + 1; j--)
        copy[indexcopy--] = data[j];

    //        cout<<"after copy is index is "<< indexcopy<<endl;
    //    for(int i=0;i<copy.size();i++) {
    //        cout<<copy[i]<<" ";
    //    }
    return left + right + count;
}

long long inverse1(vector<int> &data, int start, int end) {
    cout << start << " end " << end << endl;
    if (start == end) {
        cout << "return 0" << endl;
        return 0;
    }
    int length = (end - start) / 2;
    long long left = inverse1(data, start, start + length);
    long long right = inverse1(data, start + length + 1, end);
    int i = start + length;
    int j = end;
    int indexcopy = end;
    long long count = 0;
    while (i >= start && j >= start + length + 1) {
        if (data[i] > data[j]) {
            i--;
            count = count + j - start - length; //count=count+j-(start+length+1)+1;
        } else {
            j--;
        }
    }
    cout << "count is " << count << endl;
    return left + right + count;
}

int Solution::InversePairs(vector<int> data) {
    int length = data.size();
    if (length <= 0)
        return 0;
    //vector<int> copy=new vector<int>[length];
    vector<int> copy;
    for (int i = 0; i < length; i++)
        copy.push_back(data[i]);
    long long count = InversePairsCore(data, copy, 0, length - 1);
    //    long long count=inverse1(data,0,length-1);
    for (int i = 0; i < data.size(); i++) {
        cout << data[i] << " ";
    }
    cout << endl;
    //delete[]copy;
    return count % 1000000007;
}

int BinSearch(vector<int> data, int start, int end, int k) {

    while (end >= start) {
        int mid = (end + start) / 2;
        if (data[mid] == k)
            return mid;
        else if (data[mid] > k) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return -1;
}

int Solution::GetNumberOfK(vector<int> data, int k) {
    int pos;
    pos = BinSearch(data, 0, data.size() - 1, k);
    if (pos == -1) {
        return 0;
    }
    int res = 1;

    for (int i = pos - 1; i >= 0; i--) {
        if (data[i] == k)
            res++;
        else if (data[i] < k)
            break;
    }
    for (int j = pos + 1; j < data.size(); j++) {
        if (data[j] == k)
            res++;
        else if (data[j] > k)
            break;
    }
    return res;
}

//int Solution::TreeDepth(TreeNode* pRoot) {
//    if(pRoot==NULL)
//        return -1;
//    return 1+max(TreeDepth(pRoot->left),TreeDepth(pRoot->right));
//}

//非递归方法

int Solution::TreeDepth(TreeNode* pRoot) {
    if (pRoot == NULL) {
        return 0;
    }
    queue<TreeNode *> q;
    q.push(pRoot);
    int level = 0;
    while (!q.empty()) {
        int len = q.size();
        level++;
        while (len--) {
            TreeNode *tmp = q.front();
            q.pop();
            if (tmp->left)
                q.push(tmp->left);
            if (tmp->right)
                q.push(tmp->right);

        }
    }
    return level;
}

bool Solution::IsBalanced_Solution(TreeNode* pRoot) {
    if (pRoot == NULL)
        return false;
    int left=TreeDepth(pRoot->left);
    int right=TreeDepth(pRoot->right);
    int diff=left-right;
    if (diff>1 || diff <-1)
        return false;
    return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
}

bool checkBST(vector<int> seq, int start, int end) {
    cout << "end is " << end << "start is " << start << endl;
    if (end <= start)
        return true;
    int root = seq[end];
    cout << "root is " << root << endl;
    int i = end;
    for (i = end - 1; i >= start; i--) {
        if (seq[i] < root)
            break;
    }
    cout << "break i is " << i << endl;
    for (; i >= start; i--) {
        if (seq[i] >= root)
            return false;
    }
    cout << "i is " << i << endl;
    return checkBST(seq, start, i) && checkBST(seq, i + 1, end - 1);
}

bool Solution::VerifySquenceOfBST(vector<int> sequence) {
    int len = sequence.size();
    if (len == 0)
        return false;
    return checkBST(sequence, 0, len - 1);

}

vector<vector<int> > FindPath1(TreeNode* root, int expectNumber) {
    vector<vector<int> > res;
    vector<int> trace;
    int sum;
    int flag;
    stack<TreeNode *> q;
    if (root == NULL) {
        return res;
    }
    TreeNode *p;
    p = root;
    //    sum=root->Val;
    while (!q.empty() || p) {
        if (p) {
            trace.push_back(p->Val);
            sum += p->Val;
            cout << p->Val << " ";
            q.push(p);
            if (!p->left && !p->right) {
                cout << " trace is " << endl;
                for (int i = 0; i < trace.size(); i++) {
                    cout << trace[i];
                }
                cout << endl;
                if (sum == expectNumber)
                    res.push_back(trace);
            }
            p = p->left;
        } else {
            trace.pop_back();
            p = q.top();
            q.pop();
            p = p->right;
        }
    }
    return res;
}

void handPath(TreeNode *p, vector<vector<int> > &res, vector<int> t, int sum, int exp) {
    if (p == NULL) {
        return;
    }
    t.push_back(p->Val);
    sum += p->Val;
    if (!p->left && !p->right) {
        if (sum == exp) {
            res.push_back(t);
        }
        //        cout<<" sum is "<<sum<<" trace is "<<endl;
        //        for(int i=0;i<t.size();i++) {
        //            cout<<t[i]<<" ";
        //        }
        //        cout<<endl;
        return;
    }

    handPath(p->left, res, t, sum, exp);
    handPath(p->right, res, t, sum, exp);
    //    if(p->left) {
    //        t.push_back(p->left->Val);
    //        sum+=p->left->Val;
    //        handPath(p->left,res,t,sum,exp);
    //    }
    //    if(p->right) {
    //        t.push_back(p->right->Val);
    //        sum+=p->right->Val;
    //        handPath(p->right,res,t,sum,exp);
    //    }
}

vector<vector<int> >Solution::FindPath(TreeNode* root, int expectNumber) {
    vector<vector<int> > res;
    vector<int> trace;
    if (root == NULL)
        return res;
    handPath(root, res, trace, 0, expectNumber);
    return res;
}

ListNode* Solution::FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
    ListNode *p1 = pHead1;
    ListNode *p2 = pHead2;
    while (p1 != p2) {
        p1 = (p1 == NULL ? pHead2 : p1->next);
        p2 = (p2 == NULL ? pHead1 : p2->next);
    }
    return p1;
}

void Solution::FindNumsAppearOnce(vector<int> data, int* num1, int* num2) {
    int len = data.size();
    if (len == 0)
        return;
    set<int> s;
    for (int i = 0; i < len; i++) {
        if (!s.insert(data[i]).second) {
            s.erase(data[i]);
        }
    }
    auto p = s.begin();
    *num1 = *p;
    p++;
    *num2 = *p;
    return;

}

vector<int> Solution::FindNumbersWithSum(vector<int> array, int sum) {
    vector<int > res;
    multiset<int> s;
    int len = array.size();
    cout<<"len is "<<len<<endl;
    if (len<1)
        return res;
    for (int i = 0; i < len; i++) {
        auto pos=s.insert(array[i]);
        cout<<"insert "<<*pos;
    }
    for (int i = 0; i < len; i++) {
        if (s.find(sum - array[i]) != s.end()) {
            //            cout<<"find "<<array[i]<<endl;
            res.push_back(array[i]);
            res.push_back(sum - array[i]);
            return res;
        }
    }
    return res;
}

int Solution::LastRemaining_Solution(int n, int m) {
    int count = n;
    //标记哪位同学出列
    vector<int> isin(n, 0);
    int i = -1, step = 0;
    while (count > 0) {
        i++;
        //        模拟环
        if (i >= n)
            i = 0;
        if (isin[i] == 1)
            continue;
        step++;
        if (step == m) {
            isin[i] = 1;
            count--;
            step = 0;
        }
    }
    return i;
}

int Solution::Sum_Solution(int n) {
    int res;
    res = n;
    //        短路特性，当 &&左边为0时，右边不用计算
    res && (res += Sum_Solution(n - 1));
    return res;
}


//bool same(char *str,int &i,char *p,int &j) {
//    if(p[j]=='*') {
//        j++;
//        return same(str,i,p,j);
//    }
//    if(j==strlen(p)-1)
//        return eq(str[i],p[j]);
//    if(p[j+1]!='*') {
//        if(!str[i],p[j])
//            return false;
//        else {
//            i++;
//            j++;
//            return same(str,i,p,j);
//        }
//            
//    }
////    j+1为*的情况
////    当前不匹配，则*作用为0个 j+2
//    if(!eq(str[i],p[j])) {
//        if(j<strlen(p)-2){
//            j=j+2;
//            return same(str,i,p,j);
//        }else
//            return false;
//    }else {
////        当前匹配
//        if(i==strlen(str)-1)
//            return true;
//        if(j<strlen(p)-2 && eq(str[i],p[j+2])) {
//            j=j+2;
//            return same(str,i,p,j);
//        }
//        else {
//            while( i<strlen(str) && eq(str[i++],p[j]) );
//            if(i==strlen(str))
//                return true;
//            return same(str,i,p,j);
//        }
//    }  
//}

bool same(char *str, int i, char *p, int j) {
    if (i == strlen(str) && j == strlen(p)) {
        cout << "j is " << j << endl;
        return true;
    }
    if (i != strlen(str) && j == strlen(p))
        return false;
    //    第二个为*时
    if (j + 1 < strlen(p) && p[j + 1] == '*') {
        //        当当前匹配时
        if (i != strlen(str) && ((str[i] == p[j]) || p[j] == '.')) {
            //            *为出现0次或者出现1次
            return same(str, i, p, j + 2) || same(str, i + 1, p, j);
        } else {
            //            当前不相等，则*为出现0次
            return same(str, i, p, j + 2);
        }
    }
    //    if( (i!=strlen(str) )&& ( str[i]==p[j] || p[j]=='.' ) )
    if ((i != strlen(str))&& (str[i] == p[j] || p[j] == '.'))
        return same(str, i + 1, p, j + 1);
    return false;
}

bool Solution::match(char* str, char* pattern) {

    if (str == NULL || pattern == NULL)
        return false;
    int i = 0, j = 0;

    return same(str, i, pattern, j);
}

string Solution::LeftRotateString(string str, int n) {
    if (n < 0)
        return NULL;
    if (n == 0)
        return str;
    string tmp = "";
    //    取子串
    tmp = str.substr(0, n);
    //  移除子串
    str.erase(0, n);
    str = str + tmp;
    return str;
}

bool Solution::duplicate(int numbers[], int length, int* duplication) {
    if (length < 2)
        return false;
    set<int> s;
    s.insert(numbers[0]);
    for (int i = 1; i < length; i++) {
        if (!s.insert(numbers[i]).second) {
            *duplication = numbers[i];
            return true;
        }
    }
    return false;
}

bool seekpath(char *matrix, int rows, int cols, bool *ispath, char *str, int pos, int nextstr) {

    if (pos < 0 || pos > rows * cols || ispath[pos] || matrix[pos] != str[nextstr])
        return false;
    if (nextstr == strlen(str) - 1)
        return true;
    cout<<"pos is "<<pos<<endl;
    ispath[pos] = true;
    if (seekpath(matrix, rows, cols, ispath, str, pos + 1, nextstr + 1) ||
            seekpath(matrix, rows, cols, ispath, str, pos - 1, nextstr + 1) ||
            seekpath(matrix, rows, cols, ispath, str, pos + cols, nextstr + 1) ||
            seekpath(matrix, rows, cols, ispath, str, pos - cols, nextstr + 1)) {
        return true;
    }
    ispath[pos] = false;
    return false;
}

bool Solution::hasPath(char* matrix, int rows, int cols, char* str) {
    if (matrix == NULL || rows <= 0 || cols <= 0)
        return false;

    bool ispath[rows * cols];
    for(int x=0;x<rows*cols;x++)
        ispath[x]=false;
    for (int j = 0; j < rows; j++)
        for (int i = 0; i < cols; i++) {
            cout<<"in main pos is "<<j*cols+i<<endl;
            if (seekpath(matrix, rows, cols, ispath, str, j * cols + i, 0))
                return true;
        }
    return false;
}

int Solution::maxDistanceTwoNode(TreeNode* t) {
    if (t==NULL)
        return 0;
    if (t->left && t->right ) {
        return max( (TreeDepth(t->left)+TreeDepth(t->right) ),max(maxDistanceTwoNode(t->left),maxDistanceTwoNode(t->right)) );
    }
    
    if (t->left)
        return maxDistanceTwoNode(t->left);
    if (t->right)
        return maxDistanceTwoNode(t->right);
    
}
int Solution::Add(int num1, int num2) {
    while (num2!=0) {
            int temp = num1^num2;
            num2 = (num1&num2)<<1;
            num1 = temp;
        }
        return num1;
}

ListNode* Solution::EntryNodeOfLoop(ListNode* pHead) {
    ListNode *p,*pnext,*res;
    p=pHead;
    if(p->next==NULL)
        return NULL;
    
    while(p!=NULL) {
        res=p;
        pnext=p->next;
        p->next=NULL;
        p=pnext;
    }
    return res;
}


ListNode* Solution::deleteDuplication(ListNode* pHead) {
    ListNode *p,*tmp;
    p=pHead;
    if (p==NULL)
        return NULL;
    if(p->next==NULL)
        return p;
    tmp=p;
    p=p->next;
    while(p!=NULL) {
        while (p!=NULL && p->val==tmp->val) {
            p=p->next;
        }
        if(p==NULL)
            tmp->next=NULL;
        else {
        tmp->next=p;
        tmp=p;
        p=p->next;
        }
    }
}
