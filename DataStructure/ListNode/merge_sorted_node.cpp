//
// Created by 春江花朝秋月夜 on 2024/4/3.
//
#include "../../cunion.h"

//输入：l1 = [1,2,4], l2 = [1,3,4]
//输出：[1,1,2,3,4,4]
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        if (list1 == nullptr) {
            return list2;
        }
        if (list2 == nullptr) {
            return list1;
        }
        ListNode *dummyHead = new ListNode();
        ListNode *res = dummyHead;
        while (list1 != NULL || list2 != NULL) {
            if (list1 != NULL && list2 != NULL) {
                if (list1->val > list2->val) {
                    res->next = list2;
                    list2 = list2->next;
                } else {
                    res->next = list1;
                    list1 = list1->next;
                }
            } else if (list1 == NULL) {
                res->next = list2;
                list2 = list2->next;
            } else {
                res->next = list1;
                list1 = list1->next;
            }
            res = res->next;
        }
        return dummyHead->next;
    }
};