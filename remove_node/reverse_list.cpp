#include "../cunion.h"

class Solution {
public:
    //翻转链表
    //输入：head = [1,2,3,4,5]
    //输出：[5,4,3,2,1]

    //双指针法
    ListNode *reverseList(ListNode *head) {
        ListNode *cur = head;
        ListNode *pre = NULL;
        ListNode *tmp = cur;//保存变量
        while (cur) {
            tmp = cur->next;//保存原来的下一个指向
            cur->next = pre;//将下一个指向改为pre
            pre = cur;//修改pre往前移动一格
            cur = tmp;//修改cur往前移动一格
        }
        return pre;
    }

    //递归法
    ListNode *reverse(ListNode *cur,ListNode *pre){
        if(cur == NULL) return pre;
        ListNode *tmp= NULL;
        tmp=cur->next;
        cur->next=pre;
        return reverse(tmp,cur);
    }
};