#include "default.h"

void Del_X_L(LinkList &L, ElementType x)
{
    LNode *p = L->next;
    LNode *pre = L;
    LNode *q;

    while (p != nullptr)
    {
        if (p->data == x)
        {
            q = p;
            p = p->next;
            pre->next = p;
            free(q);
        }
        else
        {
            pre = q;
            p = p->next;
        }
    }
}
/**
 * 删除最小元素节点
 */
void Del_Min_List(LinkList &L)
{
    int val = 0;
    LNode *p = L->next;
    LNode *pre = L;
    LNode *q;

    while (p != nullptr)
    {
        if (p->data >= val)
        {
            val = p->data;
            q = p;
        }
        pre = p;
        p = p->next;
    }
    pre->next = q->next;
    free(q);
}

/**
 * 反转链表
 */
LinkList Reverse_Node(LinkList &L)
{
    LNode *pre;
    LNode *p = L->next;
    LNode *r = p->next;

    while (r!=nullptr)
    {
        pre = p;
        p = r;
        r = r->next;
        p->next=pre;
    }
    L->next = p;
    return L;
}