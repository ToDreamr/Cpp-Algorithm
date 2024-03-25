//
// Created by 春江花朝秋月夜 on 2024/3/21.
//
//删除链表的倒数第n个节点
#include "../cunion.h"

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *dummyHead = new ListNode(0, head);
        int len = 0;
        ListNode *node = dummyHead->next;
        while (node) {
            len++;
            node = node->next;
        }
        ListNode *travelNode = dummyHead->next;
        //因为是通过倒数来实现计数，所以索引从1开始
        for (int i = 1; i < len - i + 1; ++i) {
            travelNode = travelNode->next;
        }
        travelNode->next = travelNode->next->next;
        return dummyHead->next;
    }
    //使用双指针来解决这个问题！！！
    ListNode* removeNthFromEndWithDouble(ListNode* head, int n) {
        ListNode *dummyHead=new ListNode(0);
        dummyHead->next=head;//虚拟头节点

        ListNode *fast=dummyHead;
        ListNode *slow=dummyHead;

        //fast向前移动n步
        while (fast!= NULL&&n--){
            fast=fast->next;
        }
        fast = fast->next; // fast再提前走一步，因为需要让slow指向删除节点的上一个节点
        while (fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next=slow->next->next;
        return dummyHead->next;
    }
};

/** 采用虚拟头节点来解决的方法：
* ListNode *removeNthFromEnd(ListNode *head, int n) {
        //使用双指针来解决这个问题！！！
        ListNode *dummyHead = new ListNode(0, head);
        int len = 0;
        ListNode *node = dummyHead->next;
        while (node) {
            len++;
            node = node->next;
        }
        ListNode *travelNode = dummyHead->next;
        //因为是通过倒数来实现计数，所以索引从1开始
        for (int i = 1; i < len - i + 1; ++i) {
            travelNode = travelNode->next;
        }
        travelNode->next = travelNode->next->next;
        return dummyHead->next;
    }
*/