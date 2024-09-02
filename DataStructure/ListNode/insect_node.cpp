//
// Created by 春江花朝秋月夜 on 2024/3/23.
//
#include "../../cunion.h"

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *A = headA;
        ListNode *B = headB;
        int lenA = len(A);
        int lenB = len(B);
        ListNode *curA = headA;
        ListNode *curB = headB;
        if (lenA > lenB) {
            int diff = lenA - lenB;
            return findInsect(curA,curB,diff);
        } else if (lenB > lenA) {
            int diff = lenB - lenA;
            return findInsect(curB,curA,diff);
        } else if (lenA == lenB) {
            return findInsect(curA,curB,0);
        }
        return nullptr;
    }

    ListNode *findInsect(ListNode *left,ListNode *right,int diff){
        while (diff--){
            left=left->next;
        }
        if (left!=right){
            while (left!= nullptr){
                if (left==right){
                    return left;
                }
                left=left->next;
                right=right->next;
            }
        } else{
            return left;
        }
        return nullptr;
    }
    int len(ListNode *node) {
        int len = 0;
        while (node != nullptr) {
            node = node->next;
            len++;
        }
        return len;
    }
};