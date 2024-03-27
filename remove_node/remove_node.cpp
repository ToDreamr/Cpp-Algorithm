//
// Created by Rainy-Heights on 2024/3/20.
//
#include "../cunion.h"

/**
 * Definition for singly-linked list.
 */

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummyHead=new ListNode(0);//创建虚拟头节点
        dummyHead->next=head;//虚拟头节点的下一个节点指向头节点
        ListNode *cur=dummyHead;//当前节点,用于遍历,为了能够删除头节点，需要知道头结点的上一个节点也就是dummyHead
        //删除一般节点
        while (cur!= NULL&&cur->next!= NULL){
            if (cur->next->val==val){
                cur->next=cur->next->next;
            } else{
                cur=cur->next;
            }
        }
        head=dummyHead->next;
        delete(dummyHead);
        //删除头节点，使用虚拟节点
        return head;//返回头节点即可
    }
};
//int main(){
//    ListNode *node=new ListNode(0);
//    ListNode *head=node;
//    vector<int> v={1,2,6,3,4,5,6};
//    for (int i = 0; i < 7; ++i) {
//        head->val=v[i];
//        cout<<v[i]<<" ";
//        head->next=new ListNode;
//        head=head->next;
//    }
//    cout<<endl;
////    head->initNode(head,8);
//    Solution *solution;
//    ListNode *res=solution->removeElements(node,6);
//    while (res->next!= NULL){
//        cout<<res->val<<" ";
//        res=res->next;
//    }
//    cout<<endl;
//}