//
//  main.cpp
//  test
//  剑指 Offer
//  Created by jdlander on 15/12/10.
//  Copyright © 2015年 jdlander. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <deque>
#include <algorithm>
#include <math.h>
#include <semaphore.h>
#include <cmath>
#include <assert.h>
#include <memory>
#include <fstream>
#include <iterator>
#include <numeric>
#include <functional>
#include <set>
#define index int

using namespace std;


#pragma mark - C++ Primer
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x,TreeNode *l = NULL,TreeNode *ri = NULL) : val(x), left(l), right(ri) {}
};

class Solution_ {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode *> road_p;
        vector<TreeNode *> road_q;
        TreeNode *foot = root;
        road_p.push_back(foot);
        while (foot != NULL && foot->val != p->val) {
            if (foot->val > p->val)
            {
                foot = foot->left;
            }
            else
            {
                foot = foot->right;
            }
            road_p.push_back(foot);
        }
        
        foot = root;
        road_q.push_back(foot);
        while (foot != NULL && foot->val != q->val) {
            if (foot->val > q->val) {
                foot = foot->left;
            }
            else
            {
                foot = foot->right;
            }
            road_q.push_back(foot);
        }
        
        for (int i = min(road_q.size(), road_p.size()) - 1;i >= 0; --i) {
            if (road_q.at(i)->val == road_p.at(i)->val) {
                return road_q.at(i);
            }
        }
        
        
        return NULL;
    }
};

class Solution1 {
public:
    bool isUgly(int num) {
        if (num <= 0) {
            return false;
        }
        if(num == 1)
            return true;
        
        while (num > 1) {
            if (num % 2 == 0) {
                num /= 2;
            }
            else if(num % 3 == 0)
            {
                num /= 3;
            }
            else if (num % 5 == 0)
            {
                num /= 5;
            }
            else
                return false;
        }
        return true;
    }
};

class Solution3 {
public:
    bool isPowerOfTwo(int n) {
        int i = sizeof(int);
        i *= 8;
        for (int j = 0; j < i - 1; ++j) {
            int m = 1 << j;
            if(m == n)
                return true;
        }
        return false;
    }
};

class Solution4 {
public:
    
    bool isPalindrome(const char* begin,const char* end)
    {
        while (begin < end) {
            if (*begin++ != *end--) {
                return false;
            }
        }
        return true;
    }
    string longestPalindrome(string s) {
        unsigned long length = s.size() - 1;
        const char *c = s.c_str();
        while (length >= 0) {
            for(int i = 0; i + length <= s.size() - 1;++i)
            {
                if (isPalindrome(c + i, c + i + length)) {
                    return string(c + i,length + 1);
                }
            }
            length--;
        }
        return NULL;
    }
};


class Solution5 {
public:
    string convert(string s, int numRows) {
        unsigned long size = s.size();
        const char *c = s.c_str();
        string result;
        if (numRows == 1) {
            return s;
        }
        
        if(numRows == 2)
        {
            for (int i = 0; i < 2; ++i) {
                for (const char* j = i + c; j < c + size; j += 2){
                    result += *j;
                }
            }
            return result;
        }
        for (int i = 0; i < numRows; ++i) {
            if (i == 0 || i == numRows - 1) {
                for (const char *j = c + i; j < c + size;j += (2 * numRows - 2)) {
                    result += *j;
                }
            }
            else{
                bool tag = true;
                for (const char* j = c + i; j < c + size; j += (tag ? 2 * i : (2 * numRows - 2 * i - 2))){
                    result += *j;
                    tag = !tag;
                }
            }
        }
        return result;
    }
};


void reverse()
{
    char c;
    scanf("%c",&c);
    if (c != '\n') {
        reverse();
        printf("%c",c);
    }
}


class Solution {
public:
    int myAtoi(string str) {
        const char *c = str.c_str();
        //        cout<<str.length()<<endl;
        int result = 0;
        bool negativeFlag = false;
        while (*c == ' ' || *c == '\t' || *c == '\n' || *c == '\r') {
            c++;
        }
        string str1 = string(c);
        //        cout<<str1<<endl;
        int len = str1.length();
        cout<<len<<endl;
        for (int i = len - 1; i >= 0; --i,++c) {
            if(*c <= '9' && *c >= '0' && i != len - 1)
                result += (*c - '0') * pow(10, i);
            else if(*c == '+' && i == len - 1)
            {
                continue;
            }
            else if(*c == '-' && i == len - 1)
            {
                negativeFlag = true;
            }
            else
                break;
        }
        cout<<result<<endl;
        while (*c++ != '\0') {
            result /= 10;
        }
        return negativeFlag ? -1 * result : result;
    }
};

void hanoi(char x,char y, char z,int size)
{
    static int num = 0;
    if(size == 1)
        cout<<num++<<":"<<x<<"->"<<y<<endl;
    else
    {
        hanoi(x, z, y, size - 1);
        cout<<num++<<":"<<x<<"->"<<y<<endl;
        hanoi(z, y, x, size - 1);
    }
}
long jiecheng(int i )
{
    if (i == 1) {
        return i;
    }
    return i * jiecheng(i - 1);
}



class A
{
    int a;
public:
    A(){};
    A(int temp):a(temp){}
    A(A&temp){a = temp.a;}
    A& operator=(A& temp){a = temp.a; return *this;}
};

class Item_base {
    std::string isbn;
protected: //可以被派生类访问而禁止被其他用户访问
    double price;
public:
    Item_base(const std::string &book = "",
              double sales_price = 0.0):
    isbn(book),price(sales_price){}
    std::string book()const{return isbn;}
    virtual double net_price(std::size_t n)const{ return  n * price;};
    virtual ~Item_base(){}
};

class Bulk_Item : public Item_base
{
public:
    Bulk_Item(const string& book,
              double sales_price = 0.0,
              size_t qty = 0,
              double discount_rate = 0.0):Item_base(book,sales_price),
    discount(discount_rate),min_qty(qty){}
    double net_price(std::size_t n);
private:
    std::size_t min_qty;
    double discount;
};
double Bulk_Item::net_price(std::size_t n)
{
    if (n < min_qty) {
        return n * price;
    }
    else
    {
        return n * (1 - discount) * price;
    }
}
void print_total(ostream &os,
                 const Item_base &item,
                 size_t n)
{
    os<<"ISBN:"<<item.book()
    <<"\tnumber sold: "<<n<<"\ttotal price:"
    <<item.net_price(n)<<endl;
}

#pragma mark - 面试题2:单例模式
sem_t *mutex = sem_open("se", 1);  //加锁，避免多线程调用单例模式产生问题
class Singleton {
    Singleton(){num = 1;};
public:
    int num;
    static Singleton* instance;
    static Singleton* get_singleton() {
        if (instance == NULL) {
            sem_wait(::mutex);
            if (instance == NULL) {
                instance = new Singleton();
            }
            sem_post(::mutex);
        }
        return instance;
    }
};
Singleton *Singleton::instance = NULL;
#pragma mark - 面试题3:二维数组中的查找
bool Find_matrix(int *matrix,int column,int row,int value)
{
    if (matrix == NULL || column <= 0 || row <= 0) {
        return false;
    }
    int cur_row = 0;
    int cur_column = column  - 1;
    while (cur_row <= row - 1 && cur_column >= 0) {
        if (matrix[cur_row * column + cur_column] == value) {
            return true;
        }
        else if (matrix[cur_row * column + cur_column] > value)
            cur_column--;
        else
            cur_row++;
    }
    return false;
}
#pragma mark - 面试题4:替换空格
void ReplaceBlank(char string[],int length)
{
    if(string == NULL || length < 0)
        return;
    unsigned blank_count = 0;
    unsigned original_length = 0;
    int i = 0;
    while (string[i] != '\0') {
        original_length++;
        if (string[i] == ' ') {
            blank_count++;
        }
        i++;
    }
    int new_length = original_length + 2 * blank_count;
    //    if (!(string = (char *)realloc(string, new_length))) {
    //        return;
    //    }
    char *p_new_tail = string + new_length;
    char *p_old_tail = string + original_length;
    for (; p_old_tail >= string; --p_old_tail) {
        if (*p_old_tail != ' ') {
            *p_new_tail = *p_old_tail;
            p_new_tail--;
        }
        else
        {
            *p_old_tail++ = '%';
            *p_old_tail++= '2';
            *p_old_tail++ = '0';
        }
        
    }
}

#pragma mark - 链表
struct ListNode {
    int value;
    ListNode* nextNode;
    ListNode(int v = 0,ListNode* n = NULL):nextNode(n),value(v){}
};
void AddToTail(ListNode **list, int value)
{
    ListNode *node = new ListNode();
    node->value = value;
    if (list == NULL) {
        return;
    }
    if (*list == NULL) {
        *list = node;
        return;
    }
    ListNode *temp_node = *list;
    while (temp_node->nextNode!= NULL) {
        temp_node = temp_node->nextNode;
    }
    temp_node->nextNode = node;
}

void RemoveNode(ListNode **list,int value)
{
    if (list == NULL || *list == NULL) {
        return;
    }
    ListNode* nodeDeleted = NULL;
    if ((*list)->value == value) {
        nodeDeleted = *list;
        *list = (*list)->nextNode;
    }
    else{
        ListNode *tempNode = *list;
        while (tempNode->nextNode != NULL) {
            ListNode* preNode = tempNode;
            tempNode = tempNode->nextNode;
            if (tempNode->value == value) {
                preNode->nextNode = tempNode->nextNode;
            }
        }
        if (nodeDeleted) {
            free(nodeDeleted);
            nodeDeleted = NULL;
        }
    }
    
}

#pragma mark - 面试题5:从尾到头遍历链表

void printListReversingly_Iterator(ListNode* list)
{
    if (!list) {
        return;
    }
    stack<ListNode*> nodes;
    ListNode *node = list;
    while (node->nextNode != NULL) {
        nodes.push(node);
        node = node->nextNode;
    }
    nodes.push(node);
    while (!nodes.empty()) {
        cout<<nodes.top()->value<<endl;
        nodes.pop();
    }
    
}

void printListReversingly_Recursively(ListNode *list)
{
    if (list->nextNode == NULL) {
        cout<<list->value<<endl;
    }
    else
    {
        printListReversingly_Recursively(list->nextNode);
        cout<<list->value<<endl;
    }
}
//ListNode *test = new ListNode(2,new ListNode(3,new ListNode(4,new ListNode(5,new ListNode(6)))));
//printListReversingly_Iterator(test);
//printListReversingly_Recursively(test);

#pragma mark - 面试题6：重建二叉树

struct BinaryTreeNode{
    int value;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    BinaryTreeNode *parent;
    BinaryTreeNode(int v = 0,BinaryTreeNode *l = NULL,BinaryTreeNode *r = NULL):value(v),left(l),right(r){}
};

BinaryTreeNode *ConstructTree(int *preOrder,int *inOrder,int length)
{
    if (preOrder == NULL || inOrder == NULL || length < 0) {
        return NULL;
    }
    if (length == 0) {
        return NULL;
    }
    if (length == 1 && *preOrder == *inOrder) {
        return new BinaryTreeNode(*preOrder);
    }
    if (length == 1 && *preOrder != *inOrder) {
        throw exception();
        return NULL;
    }
    int root = *preOrder;
    int i = 0;
    for (; i < length; ++i) {
        if (*(inOrder + i) == root) {
            break;
        }
    }
    BinaryTreeNode *node = new BinaryTreeNode();
    node->value = *preOrder;
    node->left = ConstructTree(preOrder + 1, inOrder, i);
    node->right = ConstructTree(preOrder + 1 + i, inOrder + i + 1, length - 1 - i);
    return node;
}
void inOrder(BinaryTreeNode *tree)
{
    if (!tree) {
        return;
    }
    cout<<tree->value<<endl;
    inOrder(tree->left);
    inOrder(tree->right);
}


#pragma mark - 面试题7:两个栈实现一个队列/两个队列实现一个站

template <typename T>
class CQueue {
    stack<T> stack1;
    stack<T> stack2;
    
public:
    CQueue(){stack1 = stack<T>(); stack2 = stack<T>();};
    ~CQueue(){};
    void appendTail(const T& node);
    T deleteHead();
};

template<typename T> void CQueue<T>::appendTail(const T&node)
{
    stack2.push(node);        //往其中一个队列中加入元素
}

template<typename  T> T CQueue<T>::deleteHead()
{
    if (stack1.empty())       //如果出队列为空，则从入队列中把元素导入到出队列
    {
        if (stack2.empty()) {
            cout<<"Queue is empty";
            return NULL;
        }
        else {
            while (!stack2.empty()) {
                T temp = stack2.top();
                stack2.pop();
                stack1.push(temp);
            }
        }
    }
    
    T temp = stack1.top();
    stack1.pop();
    return temp;
}
//CQueue<int> test;
//for (int i = 0; i < 10; ++i) {
//    test.appendTail(i);
//    cout<<test.deleteHead()<<endl;
//    }
//    for (int i = 0; i < 9; ++i) {
//        cout<<test.deleteHead()<<endl;
//    }

#pragma mark - 面试题8:旋转数组的最小数字

int finMin(int *begin,int *end)
{
    
    if (begin == NULL || end == NULL) {
        return NULL;
    }
    int min = 0;
    for(int *temp = begin; temp <= end; temp++) {
        if (temp == begin) {
            min = *temp;
        }
        min = min < *temp ? min : *temp;
    }
    return min;
}
int Min(int* nums,int length)
{
    if (nums == NULL) {
        return NULL;
    }
    if(nums[0] < nums[length - 1])
        return nums[0];
    int begin = 0;
    int end = length - 1;
    while (begin < end - 1) {
        int middle = (begin + end) / 2;
        //        middle = (2 * middle == begin + end) ? middle : middle + 1;
        if (nums[begin] == nums[end] && nums[begin] == nums[middle]) {
            return finMin(nums + begin,nums + end);
        }
        if (nums[begin] <= nums[middle] && nums[middle] >= nums[end]) {
            begin = middle;
        }
        else if(nums[begin] >= nums[middle] && nums[middle] <= nums[end]){
            end = middle;
        }
    }
    return nums[begin + 1];
}

#pragma mark - 面试题9:斐波拉契数列
long long Fibonacci_Recursively(unsigned n)
{
    if (n <= 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    
    return Fibonacci_Recursively(n - 1) + Fibonacci_Recursively(n - 2);
}

long long Fibonacci_Iterating(unsigned n)
{
    if (n <= 0) {
        return 0;
    }
    int temp1 = 0;
    int temp2 = 1;
    int result = 1;
    while(n-- > 1) {
        result = temp1 + temp2;
        temp1 = temp2;
        temp2 = result;
    }
    return result;
}

#pragma mark - 面试题10:二进制中1的个数

int Numberof1(int n)
{
    int count = 0;
    int flag = 1;
    while (flag) {
        if (n & flag) {
            ++count;
        }
        flag <<= 1;
    }
    return count;
}

int Numberof1_(int n)
{
    int count = 0;
    while (n) {
        count++;
        n = (n - 1) & n;
    }
    return count;
}


#pragma mark - 面试题11:数值的整数次方
bool double_equal(double,double);
double powerWithUnsignedInt(double base,int exponent);
double Power(double base,int exponent)
{
    if (double_equal(base, 0.0)) {
        if (exponent == 0) {
            cout<<"Invalid Input";
        }
        return 0.0;
    }
    if (!double_equal(base, 0.0) && exponent == 0) {
        return 1.0;
    }
    int absExponent = exponent;
    if (exponent < 0) {
        absExponent = abs(exponent);
    }
    //    double result = 1.0;
    //    while (absExponent > 0) {
    //        result *= base;
    //        --absExponent;
    //    }
    double result = powerWithUnsignedInt(base, absExponent);
    return exponent > 0 ? result : (1.0 / result);
}
double powerWithUnsignedInt(double base,int exponent)    //高效算法，减少乘法运算次数，减少不必要的重复运算
{
    if (exponent ==  0) {
        return 1.0;
    }
    if (exponent == 1) {
        return base;
    }
    double temp = powerWithUnsignedInt(base,exponent>>1);
    return exponent & 0x1 ? temp * temp * base : temp * temp;
}
bool double_equal(double num1, double num2)   //判断两个浮点数是否相等
{
    if (abs(num1 - num2) < 1e-6) {
        return true;
    }
    else
        return false;
}

#pragma mark - 面试题12:打印1到最大的 n 位数
void Print1ToMaxOfDigitals_1(int n)  //不能处理大数溢出问题如输入 n = 100
{
    if (n <= 0) {
        cout<<"Invalid Input"<<endl;
        return;
    }
    int max = (int)pow(10, n) - 1;
    for (int i = 1; i <= max; ++i) {
        cout<<i<<" ";
    }
}

bool isMaxAfterIncrement(char* num)      // num 加1 迭代之后是否达到 Max 值
{
    //    cout<<num<<endl;
    int len = (int)strlen(num);
    bool over_bit = false;
    int i = len - 1;
    for (; i >= 0; --i) {
        if (i == len - 1) {
            if (num[i] == '9') {
                if (len == 1) {
                    return true;
                }
                num[i] = '0';
                over_bit = true;
            }
            else
                num[i]++;
        }
        else
        {
            if (!over_bit) {
                break;
            }
            if (i == 0 && num[i] == '9') {
                memset(num, '9', strlen(num) - 1);
                return true;
            }
            if (num[i] == '9') {
                num[i] = '0';
                over_bit = true;
            }
            else
            {
                num[i]++;
                over_bit = false;
            }
        }
    }
    return false;
}
void print_num(char* num)     //打印出 num
{
    if (num == NULL) {
        return ;
    }
    while (*num == '0' && *num != '\0')
        num++;
    cout<<num<<" ";
}
void Print1ToMaxOfDigitals_2(int n)       //能够处理大数
{
    if (n <= 0) {
        cout<<"Invalid Input";
        return;
    }
    char* num = new char[n + 1];
    memset(num, '0', n);
    num[n] = '\0';
    
    while (!isMaxAfterIncrement(num)) {
        print_num(num);
    }
    delete []num;
}



#pragma mark - 面试题13:在O(1)时间删除链表节点
void DeleteNode(ListNode **pListHead,ListNode *pToBeDeleted)
{
    if (pToBeDeleted->nextNode == NULL) //如果 pToBeDeleted 节点是链表的尾节点
    {
        if(pToBeDeleted == *pListHead)
        {
            pToBeDeleted = NULL;
            *pListHead = NULL;
            delete pToBeDeleted;
            return;
        }
        ListNode *tempNode = *pListHead;
        while (tempNode->nextNode != pToBeDeleted && tempNode->nextNode != NULL) {
            tempNode = tempNode->nextNode;
        }
        if (tempNode->nextNode == NULL) {
            cout<<"Invalid Input";
            return;
        }
        tempNode->nextNode = NULL;
        return;
    }
    ListNode *tempNode = pToBeDeleted->nextNode;
    pToBeDeleted->value = tempNode->value;
    pToBeDeleted->nextNode = tempNode->nextNode;
    delete tempNode;
    tempNode = NULL;
}

#pragma mark - 面试题14:调整数组顺序使奇数位于偶数之前

void ReorderOddEven(int* pData,unsigned int length)
{
    if (!pData || length <= 0) {
        cout<<"Invalid Input";
        return;
    }
    int* pBegin = pData;
    int* pEnd = pData + length - 1;
    while (pBegin < pEnd) {
        if(*pBegin & 0x1) {
            ++pBegin;
        }
        if (!(*pEnd & 0x1)) {
            --pEnd;
        }
        if (!(*pBegin & 0x1) && (*pEnd & 0x1) && pBegin < pEnd) {
            int temp = *pBegin;
            *pBegin = *pEnd;
            *pEnd = temp;
            --pEnd;
            ++pBegin;
        }
    }
}


#pragma mark - 面试题15:面试中倒数第 K 个节点

ListNode *FindKthToTail(ListNode *pListHead, unsigned int k)
{
    if (!pListHead || k <= 0) {
        cout<<"Invalid Input";
        return NULL;
    }
    ListNode *pLatter = pListHead;
    ListNode *pFommer = pListHead;
    int count = 1;
    while (pLatter->nextNode != NULL && count < k) {
        pLatter = pLatter->nextNode;
        count++;
    }
    if (count < k) {
        cout<<"Valid Input"<<endl;
    }
    while (pLatter->nextNode != NULL) {
        pLatter = pLatter->nextNode;
        pFommer = pFommer->nextNode;
    }
    return pFommer;
}


#pragma mark - 面试题16:翻转链表

ListNode *ReverseList(ListNode *pListHead)
{
    if (!pListHead) {
        cout<<"Invalid Input"<<endl;
        return NULL;
    }
    ListNode *pCurNode = pListHead;
    ListNode *pLatterNode = NULL;
    if (pCurNode->nextNode != NULL) {
        pLatterNode = pCurNode->nextNode;
    }
    else
        return pListHead;
    ListNode *pFormmerNode = NULL;
    while (pLatterNode != NULL) {         //当后一个节点不是 NULL 的时候
        pCurNode->nextNode = pFormmerNode;
        pFormmerNode = pCurNode;
        pCurNode = pLatterNode;
        pLatterNode = pLatterNode->nextNode;
    }
    pCurNode->nextNode = pFormmerNode;    //连接前一个节点
    return pCurNode;
}
//测试代码
//ListNode *test1 = new ListNode(1,new ListNode(2));
//ListNode *test = new ListNode(1,new ListNode(2,new ListNode(3,new ListNode(4,new ListNode(5,new ListNode(6,new ListNode(7)))))));
//ListNode *result = ReverseList(test1);
//while (result) {
//    cout<<result->value<<endl;
//    result = result->nextNode;
//    }

//
//ListNode *ReverseList_Recursively(ListNode *pListHead)
//{
//    if (pListHead->nextNode == NULL) {
//        return pListHead;
//    }
//}
//ListNode *ReverseList_function(ListNode *pListNode)
//{
//
//}


#pragma mark - 面试题17:合并两个链表

ListNode *Merge(ListNode *pListNode1,ListNode *pListNode2)
{
    if (pListNode1 == NULL) {
        return pListNode2;
    }
    else if(pListNode2 == NULL)
    {
        return pListNode1;
    }
    ListNode *result = pListNode1->value < pListNode2->value ? pListNode1 : pListNode2;
    if (pListNode1->value < pListNode2->value) {
        pListNode1 = pListNode1->nextNode;
    }
    else{
        pListNode2 = pListNode2->nextNode;
    }
    ListNode *curNode = result;
    while (pListNode1 != NULL && pListNode2 != NULL) {
        if (pListNode1->value <= pListNode2->value) {
            curNode->nextNode = pListNode1;
            pListNode1 = pListNode1->nextNode;
        }
        else
        {
            curNode->nextNode = pListNode2;
            pListNode2 = pListNode2->nextNode;
        }
        curNode = curNode->nextNode;
    }
    if (pListNode1 == NULL) {
        curNode->nextNode = pListNode2;
    }
    else if(pListNode2 == NULL){
        curNode->nextNode =pListNode1;
    }
    return result;
}

#pragma mark - 面试题18：树的子结构
bool HasSubTree2(BinaryTreeNode *pTree1,BinaryTreeNode *pTree2)
{
    //    if (!pTree1 && !pTree2) {
    //        return true;
    //    }
    if(pTree1 == NULL){
        return false;
    }
    if (pTree2 == NULL) {
        return true;
    }
    if (pTree2->value == pTree1->value) {
        return HasSubTree2(pTree1->left, pTree2->left) && HasSubTree2(pTree1->right, pTree2->right);
    }
    else{
        return false;
    }
}
bool HasSubtree(BinaryTreeNode *pTree1, BinaryTreeNode *pTree2)
{
    //    if (!pTree1 && !pTree2) {
    //        return true;
    //    }
    if (pTree1 == NULL) {
        return false;
    }
    if (pTree2 == NULL) {
        return false;
    }
    if (pTree1->value == pTree2->value) {
        if (HasSubTree2(pTree1->left,pTree2->left) && HasSubTree2(pTree1->right, pTree2->right)) {
            return true;
        }
    }
    else{
        return HasSubtree(pTree1->left, pTree2) || HasSubtree(pTree1->right,pTree2);
    }
    return false;
}



#pragma mark - 面试题19：二叉树的镜像

void Mirror_Recursively(BinaryTreeNode *TreeNode)
{
    if (!TreeNode) {
        return;
    }
    BinaryTreeNode *tempNode = TreeNode->left;
    TreeNode->left = TreeNode->right;
    TreeNode->right = tempNode;
    Mirror_Recursively(TreeNode->left);
    Mirror_Recursively(TreeNode->right);
}


#pragma  mark - 面试题20：顺时针打印数组
void PrintCycles(int** numbers,int column,int row)
{
    if (!numbers || column <= 0 || row <= 0) {
        return;
    }
    for (int i = 0; i < column; ++i) {
        cout<<*(*numbers + i)<<" "<<endl;
    }
    for (int i = 1; i < row; ++i) {
        cout<<*(*(numbers + i) + column - 1)<<" ";
    }
    for (int i = column - 2; i >= 0;--i ) {
        cout<<*(*(numbers + row - 1) + i)<<" ";
    }
    for (int i = row - 2; i >= 1; --i) {
        cout<<*(*(numbers + i))<<" ";
    }
}
void PrintMatrixClockwisely(int** numbers,int column,int row)
{
    if (!numbers || column <= 0 || row <= 0) {
        return;
    }
    int tag = 0;
    while (column > tag * 2 && row > tag * 2) {
        PrintCycles(numbers, column, row);
        tag++;
    }
}


#pragma mark - 面试题21：包含 min 函数的栈
//典型的用空间换取时间的做法

template <typename T>
class StackWithMin {
    stack<T> stackWithElement;
    stack<T> stackWithMin;
public:
    void pop();
    void push(const T &elem);
    T min();
};
template <typename T> void StackWithMin<T>::pop() {
    assert(!stackWithMin.empty() && !stackWithElement.empty());
    stackWithElement.pop();
    stackWithMin.pop();
}
template <typename T> void StackWithMin<T>::push(const T &elem) {
    stackWithElement.push(elem);
    if (stackWithMin.empty() || elem < stackWithMin.top()) {
        stackWithMin.push(elem);
    }
    else{
        stackWithMin.push(stackWithMin.top());
    }
}
template<typename T> T StackWithMin<T>::min()
{
    assert(!stackWithMin.empty());
    return stackWithMin.top();
}


#pragma mark - 面试题22：栈的压入、弹出序列

bool isOreder(const int* pushOrder,const int* popOrder,int length)
{
    if (pushOrder == NULL || popOrder == NULL) {
        return false;
    }
    stack<int> pushStack;
    int mark = 0;
    for (int i = 0; i < length;) {
        if (pushStack.empty() || pushStack.top() != popOrder[i]) {
            for (; mark < length;) {
                if (pushOrder[mark] != popOrder[i]) {
                    pushStack.push(pushOrder[mark]);
                    mark++;
                }
                else{
                    break;
                }
            }
            if (mark < length) {
                pushStack.push(pushOrder[mark]);
                mark++;
            }
            else
                return false;
        }
        else{
            pushStack.pop();
            ++i;
            //            ++mark;
        }
    }
    return true;
}
//int test1[] = {1,2,3,4,5,6,7,8};
//int test2[] = {4,5,3,2,1,8,7,6};
//cout<<isOreder(test1, test2, 8)<<endl;

#pragma mark - 面试题23：从上往下打印二叉树

void PrintTreeFromTop2Bottom(BinaryTreeNode *pTreeRoot)
{
    if (!pTreeRoot) {
        cout<<"Invalid Input"<<endl;
        return;
    }
    queue<BinaryTreeNode *> nodes = queue<BinaryTreeNode *>();
    nodes.push(pTreeRoot);
    while (!nodes.empty()){
        cout<<nodes.front()->value<<" ";
        if (nodes.front()->left)
            nodes.push(nodes.front()->left);
        if (nodes.front()->right)
            nodes.push(nodes.front()->right);
        nodes.pop();
    }
}

//BinaryTreeNode *test = new BinaryTreeNode(8,new BinaryTreeNode(6,new BinaryTreeNode(5),new BinaryTreeNode(7)),new BinaryTreeNode(10,new BinaryTreeNode(9),new BinaryTreeNode(11)));
//PrintTreeFromTop2Bottom(test);

#pragma mark - 面试题24：二叉搜索树的后续遍历序列

bool VerifySequenceOfBST(int sequence[],int length)
{
    if (sequence == NULL) {
        return false;
    }
    if (length <= 1) {
        return true;
    }
    
    
    
    int i = 0;
    while (sequence[i] < sequence[length - 1] && i <= length - 2) {
        i++;
    }
    for (int j = i; j < length - 1; ++j) {
        if (sequence[j] <= sequence[length - 1]) {
            return false;
        }
    }
    return VerifySequenceOfBST(sequence, i) && VerifySequenceOfBST(sequence, length - i - 1);
}


#pragma mark - 面试题25：二叉树中和为某一数值的路径
void help(BinaryTreeNode *pRootNode, queue<BinaryTreeNode *> Queue, int sum)
{
    if (!pRootNode) {
        return;
    }
    Queue.push(pRootNode);
    if (!pRootNode->left && !pRootNode->right) {
        int temp = 0;
        queue<BinaryTreeNode *> tempQueue = Queue;
        while (!tempQueue.empty()) {
            temp += tempQueue.front()->value;
            tempQueue.pop();
        }
        if (temp == sum) {
            while (!Queue.empty()) {
                cout<<Queue.front()->value<<"->";
                Queue.pop();
            }
            cout<<endl;
        }
    }
    if (pRootNode->left) {
        help(pRootNode->left, Queue, sum);
    }
    if (pRootNode->right) {
        help(pRootNode->right, Queue, sum);
    }
}

void PrintPath(BinaryTreeNode *pRootNode,int sum)
{
    queue<BinaryTreeNode *> Queue = queue<BinaryTreeNode *>();
    //    Queue.push(pRootNode);
    help(pRootNode,Queue,sum);
}

#pragma mark - 面试题26：复杂链表的复制
struct ComplexListNode
{
    int value;
    ComplexListNode *next;
    ComplexListNode *pSlibling;
    ComplexListNode(int i = 0,ComplexListNode *p1 = NULL,ComplexListNode *p2 = NULL):value(i),next(p1),pSlibling(p2){}
};

ComplexListNode *Copy(ComplexListNode *pComplexListNode)
{
    if (!pComplexListNode) {
        return NULL;
    }
    map<ComplexListNode *,ComplexListNode *> hashTable;
    ComplexListNode *tempNode = pComplexListNode;
    ComplexListNode *resultList = new ComplexListNode();
    ComplexListNode *tempResultNode = resultList;
    tempResultNode->value = tempNode->value;
    //    pComplexListNode = pComplexListNode->next;
    hashTable[tempNode] = resultList;
    tempNode = tempNode->next;
    while (tempNode) {
        tempResultNode->next =  new ComplexListNode(tempNode->value);
        tempResultNode = tempResultNode->next;
        hashTable[tempNode] = tempResultNode;
        tempNode = tempNode->next;
    }
    tempNode = pComplexListNode;
    tempResultNode = resultList;
    while (tempNode) {
        tempResultNode->pSlibling = hashTable[tempNode->pSlibling];
        tempResultNode = tempResultNode->next;
        tempNode = tempNode->next;
    }
    return resultList;
}
ComplexListNode *DCCopy(ComplexListNode *pComplexListNode)
{
    return NULL;
}

#pragma mark - 面试题27：排序二叉树转链表

ListNode *BinaryTree2List(BinaryTreeNode *pBinaryTreeRoot)
{
    if (!pBinaryTreeRoot) {
        return NULL;
    }
    if (pBinaryTreeRoot->left == NULL && pBinaryTreeRoot->right == NULL) {
        return new ListNode(pBinaryTreeRoot->value);
    }
    ListNode *tempNode = new ListNode(pBinaryTreeRoot->value);
    ListNode *tempNodeLeft = BinaryTree2List(pBinaryTreeRoot->left);
    ListNode *tempNodeRight = BinaryTree2List(pBinaryTreeRoot->right);
    //    tempNodeLeft->nextNode = tempNode;
    ListNode* temp = tempNodeLeft;
    while (temp->nextNode) {
        temp = temp->nextNode;
    }
    temp->nextNode = tempNode;
    tempNode->nextNode = tempNodeRight;
    return tempNodeLeft;
}

#pragma mark - 面试题27：二叉搜索树与双向链表

void convertNode(TreeNode* curNode,TreeNode** lastTreeNode)   //处理当前 node，将处理好的双向链表的最后一个 node 存到 lastTreeNode 里面
{
    if (curNode == NULL) {
        return;
    }
    if (curNode->left != NULL) {
        convertNode(curNode->left, lastTreeNode);
    }
    curNode->left = *lastTreeNode;
    if (*lastTreeNode != NULL) {
        (*lastTreeNode)->right = curNode;
    }
    *lastTreeNode = curNode;
    if (curNode->right != NULL) {
        convertNode(curNode->right,lastTreeNode);
    }
}

TreeNode* convert(TreeNode* root)
{
    if (root == NULL) {
        return NULL;
    }
    TreeNode* lastNode = NULL;
    convertNode(root, &lastNode);
    while (lastNode->left != NULL) {
        lastNode = lastNode->left;
    }
    return lastNode;
}
#pragma mark - 面试题28：字符串的排列

void helper(char* pStr,char* pStrBegin)
{
    if(*pStrBegin == '\0')
        cout<<pStr<<endl;
    for (int i  = 0; pStrBegin[i] != '\0'; ++i) {
        char temp = *(pStrBegin + i);
        *(pStrBegin + i) = *pStrBegin;
        *pStrBegin = temp;
        helper(pStr, pStrBegin + 1);
        temp = *(pStrBegin + i);
        *(pStrBegin + i) = *pStrBegin;
        *pStrBegin = temp;
    }
}
void Pemutation(char* str)
{
    if (!str) {
        return;
    }
    helper(str,str);
}




#pragma mark - 优化时间和空间效率

#pragma mark - 面试题29：数组中出现次数超过一半的数

//基于 Partition 函数的 O(n)算法
bool isMoreThanHalf(int* number,int length,int num)
{
    int sum_time = 0;
    for (int i = 0; i < length; ++i) {
        if (number[i] == num) {
            sum_time++;
        }
    }
    int half_time = length>>1;
    return sum_time > half_time ? true : false;
}
int partition(int* numbers,int length,int begin,int end)
{
    int prim = numbers[begin];
    int head = begin,tail = end;
    while (head < tail) {
        while (head < tail && numbers[tail] >= prim) {
            tail--;
        }
        while (head < tail && numbers[head] <= prim) {
            head++;
        }
        swap(numbers[head], numbers[tail]);
    }
    swap(numbers[begin], numbers[head]);
    return head;
}
int MoreThanhalf(int *number,int length)
{
    if (number == NULL || length <= 0) {
        return 0;
    }
    int middle = length>>1;
    int begin = 0,end = length - 1;
    int index_num = partition(number,length,begin,end);
    while (index_num != middle) {
        if (index_num < middle) {
            begin = index_num + 1;
        }
        else{
            end = middle - 1;
        }
        index_num = partition(number,length,begin,end);
    }
    if (isMoreThanHalf(number,length,number[index_num])) {
        return number[index_num];
    }
    return 0;
}


//根据数组特点找出 O(n)的算法

int MoreThanHalfNum(int* numbers,int length)
{
    if (numbers == NULL || length <= 0) {
        cout<<"Invalid input";
        return -1;
    }
    
    int temp = 0, temp_count = 0;
    for (int i = 0 ; i < length - 1; ++i) {
        if (temp_count == 0) {
            temp = numbers[i];
            temp_count++;
        }
        else{
            if (temp == numbers[i]) {
                temp_count++;
            }
            else{
                temp_count--;
            }
        }
    }
    if (!isMoreThanHalf(numbers, length, temp)) {
        cout<<"Invalid input"<<endl;
        return -1;
    }
    return temp;
}

#pragma mark - 面试题30：最小的 k 个数

void GetLeastestKnumbers(int* num,int length,int k)
{
    int left = 0,right = length - 1;
    int middle = partition(num,length,left,right);
    while (k - 1 != middle) {
        if (k - 1  > middle) {
            left = middle + 1;
        }
        else{
            right = middle + 1;
        }
        middle = partition(num,length,left,right);
    }
    for (int i = 0; i < k; ++i) {
        cout<<num[i]<<" ";
    }
}

#pragma mark - 面试题31：连续子数组的最大和


bool isInputValid = true;
int FindFreatestSumOfSubArrary(int* pNum,int length)
{
    if (pNum == NULL || length <= 0) {
        isInputValid = false;
        return 0;
    }
    int left = 0,right = 0;
    int tempSum = 0;
    int maxSum = 0;
    for (int i = 0; i < length; ++i) {
        if (tempSum < 0) {    //如果之前的 tempSum 小于0，则将当前的 tempSum 赋值为0，
            tempSum = 0;
        }
        tempSum += pNum[i];    //当前的值加上 tempSum
        if (tempSum > maxSum) { //如果当前的tempSum 大于之前存的 maxSum 的话更新 maxSum
            maxSum = tempSum;
        }
    }
    return maxSum;
}

#pragma mark - 5.3时间效率与空间效率的平衡




#pragma mark - 面试题34：第 N 个丑数
//时间复杂度较高的算法

bool isUgly(int num)
{
    while (num % 2 == 0) {
        num /= 2;
    }
    while (num % 3 == 0) {
        num /= 3;
    }
    while (num % 5 == 0) {
        num /= 5;
    }
    return (num == 1) ? true : false;
}
int getNthUglyNumber(int n)
{
    if (n <= 0) {
        return 0;
    }
    int sum = 1;
    int uglyFound = 0;
    int i = 1;
    while (uglyFound < n) {
        if (isUgly(i++)){
            sum++;
        }
    }
    return i;
}

//时间复杂度较低的算法
int Min(int a,int b,int c)
{
    int min_a_b = a < b ? a : b;
    return min_a_b < c ? min_a_b : c;
}
int getNthUglyNumber_1(int n)
{
    int* uglyNumberArray = new int[n];
    uglyNumberArray[0] = 1;
    int curUlgyNumberIndex = 0;
    int* pMultiple_2 = uglyNumberArray;
    int* pMultiple_3 = uglyNumberArray;
    int* pMultiple_5 = uglyNumberArray;
    while (curUlgyNumberIndex++ <= n - 1) {
        int nextUglyNumber = Min(*uglyNumberArray * 2,*uglyNumberArray * 3,*uglyNumberArray * 5);
        uglyNumberArray[nextUglyNumber] = nextUglyNumber;
        while (*pMultiple_2 * 2 <= nextUglyNumber) {
            pMultiple_2++;
        }
        while (*pMultiple_3 * 3 <= nextUglyNumber) {
            pMultiple_3++;
        }
        while (*pMultiple_5 * 5 <= nextUglyNumber) {
            pMultiple_5++;
        }
    }
    int result = uglyNumberArray[n - 1];
    delete [] uglyNumberArray;
    return result;
}
#pragma mark - 面试题35：第一个只出现一次的字符

char FirstNotRepeatChat(char* pString)
{
    if (pString == nullptr) {
        return '\0';
    }
    const int tableSize = 256;
    unsigned int hashTable[tableSize];
    for (int i = 0; i < tableSize; ++i) {
        hashTable[i] = 0;
    }
    char* pHashKey = pString;
    while (*pHashKey != '\0') {
        hashTable[*pHashKey]++;
        pHashKey++;
    }
    pHashKey =  pString;
    while (*pHashKey != '\0') {
        if (hashTable[*pHashKey] == 1) {
            return *pHashKey;
        }
        pHashKey++;
    }
    return '\0';
}

#pragma mark - 面试题36：数组中逆序对的个数

int InversePairCore(int* num, int* copy,int left,int right)
{
    if (left == right) {
        copy[left] = num[left];
        return 0;
    }
    int middle = (left + right)>>1;
    int count = 0;
    int left_count = InversePairCore(copy, num, left, left + middle);
    int right_count = InversePairCore(copy, num, left + middle + 1, right);
    int i = left,j = left + middle + 1;
    int index_num = 0;
    while (i <= left + middle && j <= right) {
        if (num[i] > num[j]) {
            copy[left + index_num] = num[j++];
            count++;
            j++;
        }
        else{
            copy[left + index_num] = num[i++];
            i++;
        }
        index_num++;
    }
    while (i < left + middle) {
        copy[left + index_num] = num[i++];
        index_num++;
    }
    while (j < right) {
        copy[left + index_num] = num[j++];
        index_num++;
    }
    count += (left + middle - i) * (right - left - middle);
    return left_count + right_count + count;
}
int InversePair(int* nums,int length)
{
    int *copy_1 = new int[length];
    int *copy_2 = new int[length];
    for (int i = 0; i < length; ++i) {
        copy_1[i] = nums[i];
        copy_2[i] = nums[i];
    }
    int result = InversePairCore(copy_1, copy_2, 0,length - 1);
    delete [] copy_2;
    delete [] copy_1;
    return result;
}

#pragma mark - 面试题37：两个链表的第一个公共节点


int lengthOfLinklist(ListNode* pHead)
{
    int len = 0;
    if (pHead == NULL) {
        return len;
    }
    while (pHead != NULL) {
        len++;
        pHead = pHead->nextNode;
    }
    return len;
}
ListNode* firstCommeNode(ListNode* pHead_1,ListNode* pHead_2)
{
    if (pHead_1 == NULL || pHead_2 == NULL) {
        return NULL;
    }
    
    int len_1 = lengthOfLinklist(pHead_1);
    int len_2 = lengthOfLinklist(pHead_2);
    if (len_1 > len_2) {
        int len = len_1 - len_2;
        while (len) {
            len--;
            pHead_1 = pHead_1->nextNode;
        }
    }
    else{
        int len = len_2 - len_1;
        while (len) {
            len--;
            pHead_2 = pHead_2->nextNode;
        }
    }
    while (pHead_1 != NULL && pHead_2 != NULL && pHead_1 != pHead_2) {
        pHead_2 = pHead_2->nextNode;
        pHead_1 = pHead_1->nextNode;
    }
    if (pHead_1 == pHead_2) {
        return pHead_1;
    }
    return NULL;
    
}

#pragma mark - 知识迁移能力



#pragma mark - 面试题38：数字在排序数组中出现的次数


int GetFirstK(int *data, int length, int k, int begin, int end)
{
    int pos = (begin + end) << 2;
    if(data[pos]  == k)
    {
        if (pos == 0 || data[pos - 1] != k) {
            return pos;
        }
        else
            end = pos - 1;
    }
    else if(data[pos] < k)
        begin = pos + 1;
    else
        end = pos - 1;
    return GetFirstK(data, length, k, begin, end);
    
}
int GetLastK(int *data, int length, int k, int begin, int end)
{
    int pos = (begin + end)>>1;
    if (data[pos] == k) {
        if (pos == length - 1 || data[pos + 1] != k) {
            return  pos;
        }
        else
            begin = pos +1;
    }
    else if(data[pos] < k)
        begin = pos + 1;
    else
        end = pos - 1;
    return GetFirstK(data, length, k, begin, end);
}

int GetNumberOfk(int *data, int length, int k)
{
    int number = 0;
    if (length > 0 && !data) {
        int first = GetFirstK(data, length, k, 0, length - 1);
        int last = GetLastK(data, length, k, 0, length - 1);
        if(first > -1 && last < length)
            number = last - first + 1;
    }
    return number;
}

#pragma mark - 面试题39：二叉树的深度



int TreeDepth(TreeNode* root)
{
    if (root == NULL) {
        return 0;
    }
    int leftDepth = TreeDepth(root->left);
    int rightDepth = TreeDepth(root->right);
    return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}

//判断是否是平衡二叉树

//NO_1 相当于二叉树的后续遍历
bool isBalanceTree(TreeNode* root)
{
    if (root == NULL) {
        return true;
    }
    if (root->left == NULL && root->right == NULL) {
        return true;
    }
    if (root->left == NULL  &&
        (root->right->left != NULL || root->right->right != NULL)) {
        return false;
    }
    if (root->right == NULL &&
        (root->left->left != NULL || root->left->right != NULL)) {
        return false;
    }
    return isBalanceTree(root->left) && isBalanceTree(root->right);
    
}
//NO_2
bool isBalanceTree_2(TreeNode* root)
{
    if (root == NULL) {
        return true;
    }
    int left_depth = TreeDepth(root->left);
    int right_depth = TreeDepth(root->right);
    int diff = left_depth - right_depth;
    if (diff >= 1 && diff <= -1) {
        return false;
    }
    return isBalanceTree(root->left) && isBalanceTree(root->right);
}

//NO_3 后续遍历二叉树
bool isBalanceTree(TreeNode* root ,int& depth)
{
    if (root == NULL) {
        depth = 0;
        return true;
    }
    int left,right;
    if (isBalanceTree(root->left,left) && isBalanceTree(root->right,right)) {
        int diff = left - right;
        if (diff <= 1 && diff >= -1) {
            depth = left > right ? left + 1 : right + 1;
            return true;
        }
    }
    return false;
}
bool isBalanceTree_3(TreeNode* root)
{
    if (root == NULL) {
        return false;
    }
    int d = 0;
    return isBalanceTree(root,d);
}


typedef struct multiTree
{
    int id;
    int weight;
    multiTree* parentNode;
    vector<multiTree *> childrenNode;
}MultiTree;


void printNode(MultiTree* nodes[],int length)
{
    static fstream FILE("nodes.txt");
    for (int i = 0; i < length; ++i) {
        MultiTree *temp = nodes[i];
        vector<multiTree *> nodes = temp->childrenNode;
        int sumWeight = 0;
        for (MultiTree *tree : nodes) {
            sumWeight += tree->weight;
        }
        sumWeight += temp->weight;
        FILE<<"id"<<temp->id<<","<<"parentId"<<temp->parentNode->id<<"weight"<<sumWeight<<endl;
    }
}
//shared_ptr<int> i(new int);

#pragma mark - 面试题40：数组中只出现一次的数字 又两个



//先将这个数组分为两个数组，每个数组中只有一个出现两次的数字
void numberApearOnce(vector<int> nums, int& num1, int& num2)
{
    num1 = 0,num2 = 0;
    int size = nums.size();
    int temp = 0;
    for (int i = 0; i < size; ++i) {
        temp ^= nums[i];
    }
    int i = 0;
    while (!(1 << i & temp)) {
        i++;
    }
    temp = 1 << i;
    vector<int> vec_1,vec_2;
    for (int i = 0 ; i < size; ++i) {
        if (nums[i] & temp) {
            vec_1.push_back(nums[i]);
        }
        else{
            vec_2.push_back(nums[i]);
        }
    }
    for (int i = 0; i < vec_1.size(); ++i) {
        num1 ^= vec_1[i];
    }
    for (int i = 0; i < vec_2.size(); ++i) {
        num2 ^= vec_2[i];
    }
    
}

#pragma mark - 面试题41：数组中和为 S 的两个数字
bool findNumbersWithSum(int nums[],int length,int sum,int* num_1,int* num_2)
{
    if (length <= 0 || num_1 == NULL || num_2 == NULL) {
        return false;
    }
    int begin = 0,end = length - 1;
    while (sum != nums[begin] + nums[end] && begin < end) {
        if (nums[begin] + nums[end] > sum) {
            end--;
        }
        else{
            begin++;
        }
    }
    if (begin != end) {
        *num_1 = nums[begin];
        *num_2 = nums[end];
        return true;
    }
    return false;
}


int sumContunuousNum(int begin,int end)
{
    int result = 0;
    for (int i = begin;i <= end; ++i) {
        result += i;
    }
    return result;
}

void findContinuousSum(int num)
{
    int head = 1;
    int tail = 2;
    while (head <= num>>1) {
        int sum = sumContunuousNum(head, tail);
        if (sum < num) {
            tail++;
        }
        else if(sum > num){
            head++;
        }
        else{
            for (int i = head; i <= tail; ++i) {
                cout<<i;
            }
            cout<<endl;
            head++;
        }
    }
}

#pragma mark - 面试题42：翻转单词顺序 VS 左旋转字符串

//翻转单词顺序
void reverse_str(char* pData,int head,int tail)
{
    while (head < tail) {
        char temp = pData[head];
        pData[head++] = pData[tail];
        pData[tail--] = temp;
    }
}
char* ReverseSentence(char* pData){
    if (pData == NULL) {
        return NULL;
    }
    int len = strlen(pData);
    char* result = (char*)malloc(len);
    int head = 0,tail = len - 1;
    //    while (head < tail) {
    //        char temp = pData[head];
    //        pData[head] = pData[tail];
    //        pData[tail] = temp;
    //    }
    for (int i = len - 1; i >= 0; --i) {
        result[i] = pData[len - i - 1];
    }
    int temp_begin,temp_end;
    for (int i = 0; i < len; i++) {
        if (result[i] == ' ') {
            continue;
        }
        if (i == 0 || (result[i - 1] == ' ' && result[i] != ' ')) {
            temp_begin = i;
        }
        if ((result[i] != ' ' && result[i + 1] == ' ') || (result[i] != ' ' && result[i + 1] == '\0')) {
            temp_end = i;
            reverse_str(result,temp_begin,temp_end);
        }
    }
    return result;
}


//左移字符串

char* LeftRotateString(char* pStr,int n)
{
    if (pStr == NULL || n < 0) {
        return NULL;
    }
    if (n == 0) {
        return pStr;
    }
    int len = strlen(pStr);
    char* result = (char*)malloc(len * sizeof(char));
    for (int i = 0; i < len; ++i) {
        result[i] = pStr[i];
    }
    reverse_str(result, 0, n - 1);
    reverse_str(result, n, len - 1);
    reverse_str(result,0, len - 1);
    return result;
}


#pragma mark - 面试题43：n 个骰子的点数

//方法一：回溯法，递归实现
int maxValue = 6;
void probability(int original,int current,int sum,int* p)
{
    if (current == 1) {
        p[sum - original]++;
    }
    else
    {
        for (int i = 1; i <= maxValue; ++i) {
            probability(original,current - 1,sum + i,p);
        }
    }
}
void probability(int number,int* probabilites)
{
    for (int i = 1; i <= maxValue; ++i) {
        probability(number,number,i,probabilites);
    }
}
void PrintProbability(int number)
{
    if (number < 1) {
        return;
    }
    int len =  number * maxValue - number + 1;
    int *p = (int *)malloc(len * sizeof(int));
    for (int i = 0; i < len; ++i) {
        p[i] = 0;
    }
    
    probability(number,p);
    double allPossibility = pow(6, number);
    for (int i = 0; i < len; ++i) {
        cout<<"点数："<<i + number<<"概率："<<p[i] / allPossibility<<endl;
    }
    delete [] p;
}

#pragma mark - 面试题44：扑克牌的顺子


#pragma mark - 面试题45：圆圈中最后剩下的数字


#pragma mark - 面试题46：求1 + 2 + 3 + 4......


#pragma mark - 面试题47：不用加减乘除做加法
int add(int num1,int num2)
{
    int sum = 0,carry = 0;
    do{
        sum = num1 ^ num2;
        carry = (num1 & num2)<<1;
        num1 = sum;
        num2 = carry;
    }
    while(carry != 0);
    return sum;
}

#pragma mark - 数组专项

#pragma mark -  面试题51:寻找数组中重复的数字

int duplicate(int numbers[],int length)   //用 hashtable 存放，空间复杂度为 O(n)
{
    map<int,int> hashMap;
    for (int i = 0;i < length; i++) {
        if (hashMap.count(numbers[i])) {
            return numbers[i];
        }
        else{
            hashMap.insert(make_pair(numbers[i], 1));
        }
    }
    return -1;
}


bool duplicate(int numbers[],int length,int *duplicatedNum){
    if (length <= 0 || numbers == NULL) {
        return false;
    }
    for (int i = 0; i < length; ++i) {
        while (i != numbers[i]) {
            if (numbers[i] == numbers[numbers[i]]) {
                *duplicatedNum = i;
                return true;
            }
            swap(numbers[i], numbers[numbers[i]]);
        }
        //        if (numbers[i] == i) {
        //            continue;
        //        }
        //        else if(numbers[numbers[i]] == numbers[i]){
        //            *duplicatedNum = numbers[i];
        //            return true;
        //        }
        //        else{
        //            swap(numbers[i], numbers[numbers[i]]);
        //        }
    }
    return false;
}

#pragma mark - 面试题52：构建乘积数组


void multiple(const vector<double>& array_1,vector<double>& arrary_2){
    vector<double> tempVec_1;
    vector<double> tempVec_2;
    tempVec_1.push_back(1.0);
    tempVec_2.push_back(1.0);
    double temp_1 = 1.0,temp_2 = 1.0;
    int size = array_1.size();
    for (int i = 0; i < array_1.size() - 1; ++i) {
        temp_1 *= array_1[i];
        temp_2 *= array_1[size - 1 - i];
        tempVec_1.push_back(temp_1);
        tempVec_2.push_back(temp_2);
    }
    temp_1 = 1.0;
    for (int i = 0; i < size; ++i) {
        arrary_2[i] = tempVec_1[i] * tempVec_2[size - 1 - i];
    }
}

void multipe_2(const vector<double>& arrary_1,vector<double>& array_2)
{
    if (arrary_1.size() == 0 || arrary_1.size() != array_2.size()) {
        return;
    }
    array_2[0] = 1.0;
    for (int i = 1 ; i < arrary_1.size(); ++i) {
        array_2[i] = array_2[i - 1] * arrary_1[i - 1];
    }
    double temp = 1.0;
    for (int i = arrary_1.size() - 2; i >= 0; --i) {
        temp *= arrary_1[i + 1];
        array_2[i] *= temp;
    }
}

#pragma mark - 字符串专项

#pragma mark - 面试题53：正则表达式

bool matchCore(char* str,char* pattern)
{
    if (*str == '\0' && *pattern == '\0') {
        return true;
    }
    if (*str != '\0' && *str == '\0') {
        return false;
    }
    if(*(pattern + 1) == '*')
    {
        if (*str == *pattern || (*pattern == '.' && *str != '\0')) {
            return matchCore(str + 1, pattern + 2) ||
            matchCore(str, pattern + 2)||
            matchCore(str + 1, pattern);
        }
        else
            return matchCore(str, pattern + 2);
    }
    if (*str == *pattern || (*pattern == '.' && *str != '\0')) {
        return matchCore(str + 1, pattern + 1);
    }
    else
        return false;
}
bool match(char* str,char* pattern)
{
    if (str == NULL || pattern == NULL) {
        return false;
    }
    return matchCore(str, pattern);
}
#pragma mark - 面试题54：表示数值的字符串


void scanNumber(char** pStr)
{
    while (**pStr != '\0' && **pStr <= '9' && **pStr >= 0) {
        (*pStr)++;
    }
}

bool isExponential(char** pStr)
{
    if (**pStr == '+' || **pStr == '-') {
        (*pStr)++;
    }
    if (**pStr == '\0') {
        return false;
    }
    scanNumber(pStr);
    return (**pStr == '\0') ? true : false;
}

bool isNumber(char* str)
{
    if (!str) {
        return NULL;
    }
    if (*str == '-' || *str == '+') {
        str++;
    }
    if (*str == '\0' || *str == '.') {
        return false;
    }
    bool numeric = true;
    scanNumber(&str);
    if (*str != '\0') {
        if (*str == '.') {
            ++str;
            scanNumber(&str);
            if (*str == 'E' || *str == 'e') {
                numeric = isExponential(&str);
            }
        }
        else if (*str == 'e' || *str == 'E'){
            numeric = isExponential(&str);
        }
        else
            numeric = false;
        
    }
    return numeric ? *str == '\0' : false;
    
    //    int len = strlen(str);
    //    for (int i = 0; i < len; ++i) {
    //        if (i == 0 && (str[i] == '-' || str[i] == '+')) {
    //            continue;
    //        }
    //        while (str[i] >= '0' && str[i] <= '9') {
    //            i++;
    //        }
    //        if (str[i]) {
    //            <#statements#>
    //        }
    //    }
}
#pragma mark - 面试题55：字符流中第一个不重复的数
char firstApearingOnce(char* str)
{
    int hashTable[256] = {-1};
    //    while (*str != '\0') {
    //        if (hashTable[*str] == -1) {
    //            hashTable[*str] = 1;
    //        }
    //        else
    //            hashTable[*str] = -2;
    //    }
    for (int i = 0; *(str + i) != '\0'; ++i) {
        if (hashTable[*(str + i)] == -1) {   //如果第一次出现，则将出现的下标保存在哈希表中
            hashTable[*(str + i)] = i;
        }
        else                                //如果不是第一次出现，则将哈希表的值改为2
            hashTable[*(str + i)] = -2;
    }
    for (int i = 0; i < 256; ++i) {         //遍历哈希表，出现的第一个不为-1和-2的值是第一个出现一次的字符
        
        if (hashTable[i] != -1 && hashTable[i] != -2) {
            return *(str + hashTable[i]);
        }
    }
    return -1;
}

#pragma mark - 链表专项
#pragma mark - 面试题56：链表中环的入口节点

ListNode* MeetingNode(ListNode *pHead)
{
    if (pHead == NULL) {
        return NULL;
    }
    ListNode* traveler_1 = pHead->nextNode;
    ListNode* traveler_2 = pHead->nextNode->nextNode;
    while (traveler_1 != traveler_2) {
        traveler_1 = traveler_1->nextNode;
        traveler_2 = traveler_2->nextNode->nextNode;
    }
    traveler_1 = traveler_1->nextNode;
    int circle_len = 0;
    while (traveler_1 != traveler_2) {
        traveler_1 = traveler_1->nextNode;
        circle_len++;
    }
    traveler_1 = pHead;
    traveler_2 = pHead;
    while (circle_len) {
        traveler_2 = traveler_2->nextNode;
        --circle_len;
    }
    while (traveler_1 != traveler_2) {
        traveler_2 = traveler_2->nextNode;
        traveler_1 = traveler_1->nextNode;
    }
    return traveler_1;
}


#pragma mark - 面试题57：删除链表中重复的节点

void deleteDuplicatedNode(ListNode* head)
{
    ListNode* node = head;
    while (node != nullptr && node->nextNode != nullptr) {
        if (node->nextNode->value == node->nextNode->value) {
            node->nextNode = node->nextNode->nextNode;
            continue;
        }
        node = node->nextNode;
    }
}
void deleteDuplicatedNode(ListNode** head)
{
    ListNode* pNode = *head;
    ListNode* preNode = nullptr;
    while (pNode) {
        ListNode* pNext = pNode->nextNode;
        bool needDelete = false;
        if (pNext != nullptr && pNode->value == pNext->value) {
            needDelete = true;
        }
        if(!needDelete)
        {
            preNode = pNode;
            pNode = pNode->nextNode;
        }
        else
        {
            int value = pNode->value;
            ListNode* pToDelete = pNode;
            while (pToDelete != nullptr && pToDelete->value == value) {
                pNext = pToDelete->nextNode;
                delete pToDelete;
                pToDelete = nullptr;
                pToDelete = pNext;
            }
            if (preNode == nullptr) {
                *head = pNext;
            }
            else
                preNode->nextNode = pNext;
            pNode = pNext;
        }
    }
}



#pragma mark - 专题：树


#pragma mark - 面试题58：二叉树的下一个节点

BinaryTreeNode* GetNextNode(BinaryTreeNode* node)
{
    if (node == nullptr) {
        return nullptr;
    }
    if (node->right) {
        BinaryTreeNode* result = node->right;
        while (result->left) {
            result = result->left;
        }
        return result;
    }
    if (node->right == nullptr && node->parent->left == node) {
        return node->parent;
    }
    while (node->parent) {
        if (node->parent->left == node) {
            return node->parent;
        }
        node = node->parent;
    }
    return nullptr;
}

#pragma mark - 面试题59:对称的二叉树

bool isSymmtrical(BinaryTreeNode* tree1,BinaryTreeNode* tree2)
{
    if (tree1 == nullptr && tree2 == nullptr) {
        return true;
    }
    if (tree1 == nullptr || tree2 == nullptr) {
        return false;
    }
    if (tree1->value != tree2->value) {
        return false;
    }
    return isSymmtrical(tree1->left,tree2->right) && isSymmtrical(tree1->right,tree2->left);
}
bool isSymmtrical(BinaryTreeNode* root)
{
    if (!root) {
        return false;
    }
    return isSymmtrical(root->left,root->right);
}

#pragma mark - 面试题60：把二叉树打印成多行

void print(BinaryTreeNode* root)
{
    queue<BinaryTreeNode*> Q;
    Q.push(root);
    int current_node_num = 1;
    int next_level_node_num = 0;
    while (!Q.empty()) {
        while (current_node_num--) {
            BinaryTreeNode* node = Q.front();
            cout<<node->value<<" ";
            Q.pop();
            if (node->left) {
                Q.push(node->left);
                next_level_node_num++;
            }
            if (node->right) {
                Q.push(node->right);
                next_level_node_num++;
            }
        }
        cout<<endl;
        current_node_num = next_level_node_num;
        next_level_node_num = 0;
    }
    
}

#pragma mark - 面试题61：按Z 字型打印二叉树
void printZigzag(BinaryTreeNode* root)        //用两个栈将每一层的节点存下来，交替采用左右/右左的子节点存储方式
{
    stack<BinaryTreeNode*>sk[2];
    int current = 0;
    sk[current].push(root);
    while (!sk[0].empty() || !sk[1].empty()) {
        BinaryTreeNode* node = sk[current].top();
        cout<<node->value<<" ";
        sk[current].pop();
        if (!current) {
            if (node->left) {
                sk[1 - current].push(node->left);
            }
            if (node->right) {
                sk[1 - current].push(node->right);
            }
        }
        else
        {
            if (node->right) {
                sk[1 - current].push(node->right);
            }
            if (node->left) {
                sk[1 - current].push(node->left);
            }
        }
        if(sk[current].empty())
        {
            current = 1 - current;
            cout<<endl;
        }
        
    }
    
}

#pragma mark - 面试题62：二叉树的序列化和反序列化

void Serialize(BinaryTreeNode* root,ostream& out)
{
    if (root) {
        out<<root->value<<" ";
        Serialize(root->left, out);
        Serialize(root->right, out);
    }
    else
        out<<"$ ";
}

void Reverse_Serialize(BinaryTreeNode** pRoot,istream& in)
{
    char c;
    if (in>>c && c >= '0' && c <= '9') {
        *pRoot = new BinaryTreeNode();
        (*pRoot)->left = nullptr;
        (*pRoot)->right = nullptr;
        (*pRoot)->value = c - '0';
        Reverse_Serialize(&((*pRoot)->left), in);
        Reverse_Serialize(&((*pRoot)->right), in);
    }
}


#pragma mark - 面试题63：二叉树第 K 个节点
BinaryTreeNode* KthNodeTraval(BinaryTreeNode* pNode,unsigned int& kth)
{
    BinaryTreeNode* taget = nullptr;
    if (pNode->left != nullptr) {
        taget = KthNodeTraval(pNode->left, kth);
    }
    if (taget == nullptr) {
        if (kth == 1) {
            taget = pNode;
        }
        kth--;
    }
    if (taget == nullptr && pNode->right != nullptr) {
        taget = KthNodeTraval(pNode->right, kth);
    }
    return taget;
}

BinaryTreeNode* KthNode(BinaryTreeNode* pRoot,unsigned int kth)
{
    if (pRoot == nullptr) {
        return nullptr;
    }
    return KthNodeTraval(pRoot, kth);
}


#pragma mark - 面试题64：数据流中的中位数


#pragma mark - 面试题65：滑动窗口的最大值


vector<int> maxInWindow(const vector<int>& num,unsigned int size)
{
    vector<int> maxInWindows;
    if (num.size() >= size && size >= 1) {
        deque<int> in;
        for (int i = 0; i < size; ++i) {
            while (!in.empty() && num[i] >= num[in.back()]) {
                in.pop_back();
            }
            in.push_back(i);
        }
        for (int i = size; i < num.size(); ++i) {
            maxInWindows.push_back(num[in.front()]);
            while (!in.empty() && num[i] >= num[in.back()]) {
                in.pop_back();
            }
            if (!in.empty() && in.front() < (int)(i - size)) {
                in.pop_front();
            }
            in.push_back(i);
        }
        maxInWindows.push_back(num[in.front()]);
    }
    return maxInWindows;
}

#pragma mark - 回溯法

#pragma mark - 面试题66：矩阵中的路径


bool hasPathCore(char* matrix,int rows,int cols,int curRow,int curCol,char* str,int& length,bool *visited)
{
    if (str[length] == '\0') {
        return true;
    }
    bool hasPath = false;
    if (curCol >= 0 && curCol < cols && curRow >= 0 && curRow < rows
        && !visited[cols * curRow + curCol] && matrix[cols * curRow + curCol] == str[length]) {
        length++;
        visited[cols * curRow + curCol] = true;
        hasPath = hasPathCore(matrix,rows,cols,curRow - 1,curCol,str,length,visited) ||
        hasPathCore(matrix,rows,cols,curRow,curCol - 1,str,length,visited) ||
        hasPathCore(matrix,rows,cols,curRow,curCol + 1,str,length,visited) ||
        hasPathCore(matrix,rows,cols,curRow + 1,curCol,str,length,visited);
    }
    if (!hasPath) {
        --length;
        visited[cols * curRow + curCol] = false;
    }
    return hasPath;
}

bool has_Path(char* matrix,int rows,int cols,char* str)
{
    if (matrix == NULL || str == NULL || rows <= 0 || cols <= 0) {
        return false;
    }
    bool *visited = new bool[rows * cols];
    int length = 0;
    memset(visited, false,rows * cols );
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (hasPathCore(matrix,rows,cols,i,j,str,length,visited)) {
                return true;
            }
        }
    }
    delete[] visited;
    return false;
}

#pragma mark - 面试题67：机器人的运动范围

bool check(int threshold,int rows,int cols,int curRow,int curCol,bool *visited)   //该节点是否能够被访问
{
    if (curRow >= rows || curRow < 0 || curCol >= cols || curCol < 0 || visited[curRow * cols + curCol]) {
        return false;
    }
    int sum = 0;
    while (curRow % 10) {
        sum += curRow % 10;
        curRow /= 10;
    }
    while (curCol % 10) {
        sum += curCol % 10;
        curCol /= 10;
    }
    if (sum > threshold) {
        return false;
    }
    return true;
}


int movingCountCore(int thershold,int rows,int cols,int curRow,int curCol,bool *visited)
{
    int count = 0;
    if (check(thershold,rows,cols, curRow, curCol,visited)) {
        count += 1;
        visited[curRow * cols + curCol] = true;
        count += movingCountCore(thershold, rows,cols, curRow, curCol - 1, visited);
        count += movingCountCore(thershold, rows,cols, curRow - 1, curCol, visited);
        count += movingCountCore(thershold, rows,cols, curRow + 1, curCol, visited);
        count += movingCountCore(thershold, rows,cols, curRow, curCol + 1, visited);
    }
    return count;
}
int movingCount(int thershold,int rows,int cols)
{
    bool *visited = new bool[rows * cols];
    for (int i = 0; i < rows * cols; ++i) {
        visited[i] = false;
    }
    return movingCountCore(thershold, rows, cols, 0, 0, visited);
}

#pragma mark - 剑指 offer
//int lcs(vector<int>& a,vector<int>& b)
//{
//    if (a.empty() || b.empty()) {
//        return 0;
//    }
//    if (a[a.size() - 1] == b[b.size() - 1]) {
//        vector<int>a1(a.begin(),a.end() - 1);
//        vector<int>b1(b.begin(),b.end() - 1);
//        return lcs(a1,b1) + 1;
//    }
//    else
//    {
//        vector<int>a1(a.begin(),a.end() - 1);
//        vector<int>b1(b.begin(),b.end() - 1);
//        return max(lcs(a1, b),lcs(a, b1));
//    }
//}

int lcs(vector<int>& a,vector<int>& b)
{
    size_t a_size = a.size() + 1;
    size_t b_size = b.size() + 1;
    int **nums = (int **)malloc(b_size* sizeof(int *));
    for (int i = 0; i < b_size; ++i) {
        *(nums + i) = (int *)malloc(a_size * sizeof(int));
    }
    
    for (int i = 0; i < b_size; ++i) {
        nums[i][0] = 0;
    }
    for (int i = 0; i < a_size; ++i) {
        nums[0][i] = 0;
    }
    for (int i = 1; i < a_size; ++i) {
        for (int j = 1; j < b_size; ++j) {
            if (a[i - 1] == b[j - 1]) {
                nums[i][j] = nums[i - 1][j - 1] + 1;
            }
            else if (nums[i - 1][j] >= nums[i][j - 1])
                nums[i][j] = nums[i - 1][j];
            else
                nums[i][j] = nums[i][j - 1];
        }
    }
    return nums[a_size - 1][b_size - 1];
}
void MaxHanoi()
{
    int NUM;
    cin>>NUM;
    multimap<int,int> weights;
    multimap<int,int> heights;
    for (int i = 0; i < NUM; i++) {
        int key;
        int weight;
        int height;
        cin>>key>>weight>>height;
        weights.insert(make_pair(weight,key));
        heights.insert(make_pair(height,key));
    }
    vector<int> a,b;
    for(pair<int, int>temp : weights)
    {
        a.push_back(temp.second);
    }
    for (pair<int, int>temp : heights) {
        b.push_back(temp.second);
    }
    for_each(a.begin(), a.end(), [](int c){cout<<c<<" ";});
    cout<<endl;
    for_each(b.begin(), b.end(), [](int c){cout<<c<<" ";});
    cout<<endl;
    cout<<lcs(a, b);
}






#pragma mark - 算法学习笔记

#pragma mark - 将二叉树转换成一个双向链表

void transform(TreeNode* root,TreeNode* & last)
{
    if (root == nullptr) {
        //        last = nullptr;
        return;
    }
    transform(root->left,last);
    if (last != nullptr) {
        last->right = root;
    }
    root->left = last;
    last = root;
    transform(root->right,last);
}


#pragma mark - 二叉树的直径（直径为左右子树的高度之和 + 1）
string str;
int mxDiameter = 0;
int findMaxDepth(TreeNode* root)
{
    if (root == nullptr) {
        return 0;
    }
    int leftDepth = findMaxDepth(root->left);
    int rightDepth = findMaxDepth(root->right);
    mxDiameter = max(mxDiameter, leftDepth + rightDepth + 1);   //计算当前最大的直径
    return max(leftDepth, rightDepth) + 1;    //当前子树的最大深度
}

#pragma mark - Main


class GrayCode {
public:
    vector<string> getGray(int n) {
        // write code here
        if(n < 1){
            return vector<string>();
        }
        else if(n == 1){
            string str_1("0");
            string str_2("1");
            vector<string> temp;
            temp.push_back(str_1);
            temp.push_back(str_2);
            return temp;
        }
        
        vector<string> temp = getGray(n - 1);
        int size = pow(2,n);
        vector<string> result(pow(2,n),string());
        for(int i = 0; i < temp.size();++i)
        {
            result[i] = string("0") + temp[i];
            result[size - 1 - i] = string("1") + temp[i];
        }
        
        return result;
    }
};
class Gift {
public:
    
    int partition(vector<int>& nums,int l,int r){
        int key = l;
        int pivot = nums[key];
        while(l < r){
            while(l < r && pivot <= nums[r]){
                r--;
            }
            while(l < r && pivot >= nums[l]){
                l++;
            }
            swap(nums[l],nums[r]);
        }
        swap(nums[key],nums[l]);
        return l;
    }
    int getValue(vector<int> gifts, int n) {
        // write code here
        int l = 0;
        int r = n - 1;
        int index_t = partition(gifts,l,r);
        while(l < r && index_t != n / 2){
            if(index_t < n>>1){
                l = index_t + 1;
            }
            else
                r = index_t - 1;
            index_t = partition(gifts, l, r);
        }
        
        
        int result = gifts[index_t];
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            if (result == gifts[i]) {
                sum++;
            }
        }
        if(sum > n>>1)
            return gifts[index_t];
        else
            return 0;
    }
};

void fun(){
    int r,x0,y0,x1,y1;
    while(cin>>r>>x0>>y0>>x1>>y1){
        float distance = sqrt(pow(abs(x1 - x0),2) + pow((y1 - y0),2));
        float onepace = 4.0 * r;
        int result = static_cast<int>(distance / onepace);
        if (result == distance / onepace) {
            cout<<result<<endl;
        }
        else
            cout<<result + 1<<endl;
    }
}

void fun_2(){
    int n = 0;
    while(cin>>n){
        vector<int> vec;
        for(int i = 0; i < n; ++i){
            int temp;
            cin>>temp;
            vec.push_back(temp);
        }
        vector<int> vec_1;
        vector<int> vec_2;
        for(int i = 0;i + 1 <= n; ++i){
            vec_1.push_back(vec[i + 1] - vec[i]);
            if(i + 2 <= n){
                vec_2.push_back(vec[i + 2] - vec[i]);
            }
        }
        int sum = 0;
        for(int i = 0; i < n - 1; ++i){
            sum = sum < vec_1[i] ? vec_1[i] : sum;
        }
        int min = 0;
        for(int i = 0; i < vec_2.size(); ++i){
            if(vec[i] <= sum){
                //cout<<sum<<endl;
                min = sum;
                break;
            }
            min = min > vec_2[i] ? vec_2[i] : min;
        }
        cout<<min<<endl;
    }
}

void fun_3(){
    int pp,n;
    while(cin>>pp>>n){
        int* p = new int[pp]();
        for (int i = 0; i < pp; ++i) {
            p[i] = 0;
        }
        vector<int> vec;
        for(int i = 0; i < n; ++i){
            int temp;
            cin>>temp;
            vec.push_back(temp);
        }
        int result = 0;
        int i = 0;
        for(; i < n; ++i){
            
            if(p[(vec[i] % pp) - 1] == 1){
                cout<<vec[i] % pp<<endl;
                result = i + 1;
                break;
            }
            else{
                p[vec[i] % pp  - 1] = 1;
            }
        }
        if (i == n) {
            cout<<"-1"<<endl;
        }
        else
            cout<<result<<endl;
    }
}

//void helper(const char* left,const char* right,bool& tag){
//    if (left >= right) {
//        return;
//    }
//    if (*left == *right) {
//        left++;
//        right--;
//    }
//    else if(tag){
//        helper(left, <#const char *right#>, <#bool &tag#>)
//    }
//}
void fun_4(){
    string str;
    while (cin>>str) {
        const char* cstr = str.c_str();
        bool tag = true;
        bool result = true;
        if (str.length() % 2) {
            int middle = str.length() / 2;
            int left = middle - 1;
            int right = middle;
            while (left >= 0 && right < str.length()) {
                if (cstr[left] == cstr[right]) {
                    left--;
                    right++;
                }
                else if (cstr[left] != cstr[right] && tag == true) {
                    right++;
                    tag = false;
                }
                else if(cstr[left] != cstr[right] && tag != true){
                    result = false;
                    break;
                }
            }
            left = middle;
            right = middle + 1;
            tag = true;
            bool result_1 = true;
            while (left >= 0 && right < str.length()) {
                if (cstr[left] == cstr[right]) {
                    left--;
                    right++;
                }
                else if (cstr[left] != cstr[right] && tag == true) {
                    left--;
                    tag = false;
                }
                else if(cstr[left] != cstr[right] && tag != true){
                    result_1 = false;
                    break;
                }
            }
            
            if (result || result_1) {
                cout<<"YES"<<endl;
            }
            else
                cout<<"NO"<<endl;
        }
        else{
            bool result_1 = true;
            bool result_2 = true;
            bool result_3 = true;
            int middle = str.length() / 2;
            int left = middle - 1;
            int right = middle;
            while (left >= 0 && right < str.length()) {
                if (cstr[left] != cstr[right]) {
                    result_1 = false;
                    break;
                }
            }
            left = middle - 1;
            right = middle + 1;
            tag = true;
            while (left >= 0 && right < str.length()) {
                if (cstr[left] == cstr[right]) {
                    left--;
                    right++;
                }
                else if (cstr[left] != cstr[right] && tag == true) {
                    left--;
                    tag = false;
                }
                else if(cstr[left] != cstr[right] && tag != true){
                    result_2 = false;
                    break;
                }
            }
            left = middle - 2;
            right = middle;
            tag = true;
            while (left >= 0 && right < str.length()) {
                if (cstr[left] == cstr[right]) {
                    left--;
                    right++;
                }
                else if (cstr[left] != cstr[right] && tag == true) {
                    right++;
                    tag = false;
                }
                else if(cstr[left] != cstr[right] && tag != true){
                    result_3 = false;
                    break;
                }
            }
            
            if (result_1 || result_2 || result_3) {
                cout<<"YES"<<endl;
            }
            else
                cout<<"NO"<<endl;
            
        }
    }
}


struct user{
    int id;
    set<int> answerUser;
    user(int i):id(i){answerUser = set<int>();}
};

void fun_cheat()
{
    int n = 0;
    while (cin>>n) {
        map<int,set<int>> Users;
        for (int i = 0 ; i < n; ++i) {
            int id;
            int answerNum;
            cin>>id>>answerNum;
            Users.insert(make_pair(id, set<int>()));
            for (int i = 0; i < answerNum; ++i) {
                int temp = 0;
                cin>>temp;
                Users[id].insert(temp);
            }
        }
        
    }
}


void fun_max_product(){
    int m,n;
    while (cin>>m>>n) {
        int** matrix = (int**)malloc(sizeof(int*) * m);
        for (int i = 0; i < n; ++i) {
            matrix[i] = (int*)malloc(sizeof(int) * n);
        }
        int *row = (int*)malloc(sizeof(int) * m);
        for (int i = 0; i < m; ++i) {
            int sum = 1;
            for (int j = 0; j < n; ++j) {
                int temp = 0;
                cin>>temp;
                sum *= temp;
                matrix[i][j] = temp;
            }
            row[i] = sum;
        }
        
        int *col = (int*)malloc(sizeof(int) * n);
        for (int i = 0; i < n; ++i) {
            int sum = 1;
            for (int j = 0; j < m; ++j) {
                sum *= matrix[j][i];
            }
            col[i] = sum;
        }
        
        for (int i = 0; i < m; ++i) {
            cout<<row[i]<<" ";
        }
        cout<<endl;
        for (int i = 0; i < n ; ++i) {
            cout<<col[i]<<" ";
        }
        cout<<endl;
        int max = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (max < row[i] * col[j] / (matrix[i][j] * matrix[i][j])) {
                    max = row[i] * col[j] / (matrix[i][j] * matrix[i][j]);
                }
            }
        }
        cout<<max<<endl;
    }
}



int lps(const char* seq,int l,int r){
    if (l == r) {
        return 1;
    }
    if (l > r) {
        return 0;
    }
    if (seq[l] == seq[r]) {
        return lps(seq, l + 1, r - 1) + 2;
    }
    else{
        return max(lps(seq, l + 1, r), lps(seq, l, r - 1));
    }
}


int lpsDP(const char* str,int n){
    int** dp = new int*[n];
    for (int i = 0; i < n; ++i) {
        dp[i] = new int[n];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                dp[i][j] = 1;
            }
            else
                dp[i][j] = 0;
        }
    }
    
    for (int i = 1 ; i < n; ++i) {
        for (int j = 0; j + i < n; ++j) {
            if (str[j] == str[j + i]) {
                dp[j][i + j] = dp[j + 1][ j + i - 1] + 2;
            }
            else{
                dp[j][i + j] = max(dp[j + 1][j + i], dp[j][i + j - 1]);
            }
        }
    }
    int temp = dp[0][n - 1];
    for (int i = 0; i < n; ++i) {
        delete []dp[i];
    }
    delete []dp;
    return temp;
}
using namespace placeholders;


void bS(){
    int i = 1;
    char* p = (char*)&i;
    cout<<(int)*p<<endl;
}

vector<string> splitKeyWord(string sql){
    const char* ch = sql.c_str();
    int str_index = 0;
    vector<string> result;
    for (int i = 0; i < sql.size(); ++i) {
        if (i != 0 && *(ch + i) == ' ') {
            string temp(ch + str_index,ch + i);
            result.push_back(temp);
            str_index = i + 1;
        }
    }
    return result;
}

vector<double> BatchQueryExecutionTime(const vector<string>&sqls, const vector<double>&times, const vector<string>&keywords) {
    // your code
    
    map<string,set<int>> keyWordMap;
    for (int i = 0; i < sqls.size(); ++i) {
        string temp = sqls[i];
        vector<string> temp_vec= splitKeyWord(temp);
        for (int j = 0; j < temp_vec.size(); ++j) {
            keyWordMap[temp_vec[j]].insert(i);
        }
    }
    
    vector<double> result;
    for (int i = 0; i < keywords.size(); ++i) {
        string temp = keywords[i];
        set<int> tempSet = keyWordMap.at(temp);
        double sum = 0.0;
        for (set<int>::iterator ite = tempSet.begin(); ite != tempSet.end(); ++ite) {
            sum += times.at(*ite);
        }
        result.push_back(sum / tempSet.size());
    }
    return result;
}






bool chkLegal(string A) {
    // write code here
    const char* cStr = A.c_str();
    stack<char> sk;
    
    for (int i = 0; i < strlen(cStr); ++i) {
        char tempChar = *(cStr + i);
        if (tempChar == '{' || tempChar == '(' || tempChar == '[') {
            sk.push(tempChar);
        }
        else if (tempChar == '}') {
            if (!sk.empty() && sk.top() == '{')
                sk.pop();
            else
                return false;
        }
        else if (tempChar == ')'){
            if (!sk.empty() && sk.top() == '(') {
                sk.pop();
            }
            else
                return false;
        }
        else if (tempChar == ']'){
            if (!sk.empty() && sk.top() == '[') {
                sk.pop();
            }
            else
                return false;
        }
    }
    return sk.empty() ? true : false;
}

bool chkLegal1(string A) {
    // write code here
    const char* cStr = A.c_str();
    stack<char> sk;
    char c[] = {'(','[','{','}',']',')'};
    int num[6] = {0};
    for (int i = 0; i < strlen(cStr); ++i) {
        char tempChar = *(cStr + i);
        
        for(int j = 0; j < 6; ++j) {
            if (c[j] == tempChar) {
                num[j]++;
            }
        }
    }
    bool result = true;
    for (int i = 0; i < 3; ++i) {
        if (num[i] != num[5 - i]) {
            result = false;
            break;
        }
    }
    return result;
}


#pragma mark - 6.16


void removeNode(ListNode** pHead,int val){
    if (pHead == NULL && *pHead == NULL) {
        return;
    }
    ListNode* head = *pHead;
    if (head->value == val) {
        *pHead = head->nextNode;
        delete head;
    }else{
        while (head->nextNode != NULL && head->nextNode->value != val) {
            head = head->nextNode;
        }
        ListNode* tempNode = head->nextNode;
        if(tempNode != NULL){
            head->nextNode = tempNode->nextNode;
            delete tempNode;
        }
    }
    
}


//面试题5：逆序打印链表


void reversePrintLinklist(ListNode* head){
    stack<int> sk;
    while (head != NULL) {
        sk.push(head->value);
        head = head->nextNode;
    }
    while (!sk.empty()) {
        cout<<sk.top()<<" ";
        sk.pop();
    }
}
void reversePrintLinklistRecursively(ListNode* head){
    if (head == NULL) {
        return;
    }
    if (head->nextNode == NULL) {
        cout<<head->value<<" ";
    }else{
        reversePrintLinklistRecursively(head->nextNode);
        cout<<head->value<<" ";
    }
}

int main(int argc, const char * argv[])
{
    string s;
    //    s.append(<#const value_type *__s#>, <#size_type __n#>)
    vector<int> vec;
    
    //    fun_max_product();
    //    bS();
    //    string str;
    //    cin>>str;
    //    cout<<lpsDP(str.c_str(), str.length())<<endl;
}
