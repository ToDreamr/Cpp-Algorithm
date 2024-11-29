#include "default.h"
#include "queue.h"

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

    while (r != nullptr)
    {
        pre = p;
        p = r;
        r = r->next;
        p->next = pre;
    }
    L->next = p;
    return L;
}

/**
 * 归并链表
 */
LinkList Union(LinkList &left, LinkList &right)
{
    LinkList *p = left->next;
    LinkList *q = right->next;
    LinkList *res = new LNode(0);
    LinkList *cur = res;

    while (p != nullptr && q != nullptr)
    {
        int p_val = p->data;
        int q_val = q->data;
        if (p_val == q_val)
        {
            LinkList *mid = new LinkList(p_val);
            cur->next = mid;
            cur = cur->next;
        }
    }
    return res;
}

/**
 * 串的模式匹配-暴力法
 */
int Index(SString S, SString T)
{
    int i = 1, j = 1;
    while (i <= S.length && j < T.length)
    {
        if (S.ch[i] == T.ch[j])
        {
            ++i;
            ++j;
        }
        else
        {
            i = i - j + 2;
            j = 1; // 指针退回重新匹配
        }
    }
    if (j > T.length)
    {
        return i - T.length;
    }
    return 0;
}

/**
 * 首先需要找到next数组
 */
void Get_Next(SString T, int next[])
{
    int i = 1, j = 0;
    next[1] = 0;
    while (i < T.length)
    {
        if (j == 0 || T.ch[i] == T.ch[j])
        {
            ++i;
            ++j;
            next[i] == j;
        }
        else
        {
            j = next[j];
        }
    }
}
/**
 * 串模式匹配-KMP算法
 */
int Index_KMP(SString S, SString T, int next[])
{
    int i = 1, j = 1;
    while (i <= S.length && j <= T.length)
    {
        if (j == 0 || S.ch[i] == T.ch[j])
        {
            ++i;
            ++j;
        }
        else
        {
            j = next[j];
        }
    }
    if (j > T.length)
    {
        return i - T.length;
    }
    return 0;
}

/**
 * 树的层序遍历
 */
void LevelOrder(Tree T){
    SqQueue Q = malloc(sizeof(SqQueue));
    InitQueue(Q);
}