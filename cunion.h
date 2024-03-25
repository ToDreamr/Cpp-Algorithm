#ifndef CARL_CODE_UNION_H
#define CARL_CODE_UNION_H

#include <iostream>
#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_set>//无序哈希表
//#include "multiset" //底层实现为哈希表，std::set 和std::multiset 的底层实现是红黑树，红黑树是一种平衡二叉搜索树，所以key值是有序的
//#include <map>
#include <unordered_map>
using namespace std;

//链表ADT
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {} //使用冒号的初始化列表仍然是一种更常用和推荐的方式来初始化成员变量
    explicit ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    void initNode(ListNode *listNode,int len,vector<int> v){
        ListNode *head=listNode;
        int index=0;
        while (index<len){
            head->next=new ListNode;
            head->val=v[index];
            head=head->next;
            index++;
        }
    }
};
//树ADT
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
#endif //CARL_CODE_UNION_H
//
// Created by Rainy-Heights on 2024/3/19.
//
//$USER_NAME