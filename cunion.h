#ifndef CARL_CODE_UNION_H
#define CARL_CODE_UNION_H

#include <iostream>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

//链表ADT
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    void initNode(ListNode *listNode,int len){
        ListNode *head=listNode;
        int index=0;
        while (index<len){
            head->next=new ListNode;
            head->val=0;
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