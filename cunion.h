#ifndef CARL_CODE_UNION_H
#define CARL_CODE_UNION_H
/**
 * 全局数据结构头文件，包含链表、二叉树、多叉树、队列的定义
 * <hr/>
 * Created by Rainy-Heights on 2024/3/19.
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_set>//无序哈希表
//#include "multiset" //底层实现为哈希表，std::set 和std::multiset 的底层实现是红黑树，红黑树是一种平衡二叉搜索树，所以key值是有序的
#include <map>
#include <stack>
#include <unordered_map>
#include <algorithm> //排序函数
#include <cmath>

#define maxsize 10
using namespace std;
typedef int ElementType;

typedef struct SqlList {
    ElementType data[maxsize];
    ElementType length;
} LinerList;

/**
 * 队列(顺序队列)
 */
struct SQueue {
    int front;
    int rear;
    ElementType *data;
};

/**
 *  串定义
 */
typedef struct {
    char ch[maxsize];
    int length;
}SString;

/**
 *
 */

struct QNode{
    int data;
    QNode *next;
};
struct NQueue{
    QNode *front;
    QNode *rear;
};

/**
 * 单链表ADT
 */
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {} //使用冒号的初始化列表仍然是一种更常用和推荐的方式来初始化成员变量
    explicit ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * 双向链表
 */
struct DList{
    int val;
    DList *next;
    DList * prior;

    DList() : val(0),next(nullptr),prior(nullptr){};
    DList(int val, DList *next, DList *prior) : val(val), next(next), prior(prior) {}
};

//树ADT
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

//N叉树ADT
class Node {
public:
    int val{};
    vector<Node *> children;

    Node() = default;

    explicit Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};

#endif
