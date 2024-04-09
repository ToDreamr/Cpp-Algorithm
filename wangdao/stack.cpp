//
// Created by 春江花朝秋月夜 on 2024/4/9.
//
//LIFO
#include "default.h"
#define MaxSize 10

typedef struct {
    ElemType data[MaxSize];
    int top;
} SqStack;

bool InitSqStack(SqStack &s){
    s.top=0;
    return OK;
}
//顺序栈的大小不可改变
bool Push(SqStack &S, ElemType x) {
    if (S.top == MaxSize - 1) {
        return false;
    }
    S.top = S.top + 1;//指针先加一
    S.data[S.top] = x;
    return true;
}

bool Pop(SqStack &S, ElemType &x) {
    if (S.top == -1) {
        return false;
    }
    x = S.data[S.top];//栈顶指针
    S.top = S.top - 1; //逻辑上删除了原来的元素，实际的数据还残留在内存之中
    //注意S.top--是先使用其值再减一，--S.top相反
    return true;
}
//共享栈：栈的指针top具有多个，栈满的条件 为top0+1=top1

//链栈
Status InitLiStack(LNode &S) {
    S = NULL;
    return OK;
}

Status Push(LinkNode *S, ElemType x) {
    //生成新的节点
    LNode p = new LinkNode;
    p->data = x;
    p->next = S;
    S = p;
    return OK;
}

Status Pop(LinkNode *S, ElemType x) {
    if (S == NULL) return ERROR;
    LinkNode *res = S;
    x = res->data;
    res = res->next;
    delete res;
    return OK;
}
//取出元素
ElemType GetTop(LinkNode *S) {
    if (S != NULL) {
        return S->data;
    }
    return ERROR;
}