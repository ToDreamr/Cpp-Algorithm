//
// Created by 春江花朝秋月夜 on 2024/3/21.
//
#include "../cunion.h"
class Solution {
public:
    //输入：head = [1,2,3,4]
    //输出：[2,1,4,3]
    ListNode* swapPairs(ListNode* head) {
        ListNode *pre=new ListNode(0);
        pre->next=head;
        ListNode *cur=pre;
        ListNode *tmp=cur;
        ListNode *tmp1=cur;
        while (cur->next != nullptr && cur->next->next != nullptr){
            tmp=cur->next->next;
            tmp1=tmp->next;
            tmp->next=cur->next;
            cur->next=tmp1;
            cur=tmp1;
        }
        return pre->next;
    }
};