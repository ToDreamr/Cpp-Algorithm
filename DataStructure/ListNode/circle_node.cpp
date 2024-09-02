//
// Created by 春江花朝秋月夜 on 2024/3/23.
//
#include "../../cunion.h"
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode * dummyHead=new ListNode();
        dummyHead->next=head;
        ListNode *fast=dummyHead->next;
        ListNode *slow=dummyHead->next;
        while (fast!= nullptr&& fast->next!= nullptr){
            fast=fast->next->next;
            slow=slow->next;
            if (fast==slow){
                ListNode *pos=fast;
                ListNode *run=head;
                while (run!=pos){
                    pos=pos->next;
                    run=run->next;
                }
                return run;
            }
        }
        return nullptr;
    }
};