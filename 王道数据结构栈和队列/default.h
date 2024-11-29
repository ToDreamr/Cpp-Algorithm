//
// Created by 春江花朝秋月夜 on 2024/4/9.
//

#ifndef CARL_CODE_DEFAULT_H
#define CARL_CODE_DEFAULT_H

#include <iostream>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define ElementType int
#define MAXLEN 255
typedef int Status;

using namespace std;

//单链表：
typedef struct LNode {
    ElementType data; //数据域
    LNode *next;//指针域

    explicit LNode(int x) : data(x),next(nullptr){};
} LNode,*LinkList;

//树
typedef struct Tree{
    ElementType data;
    Tree *left;
    Tree *right;
    explicit Tree(int x) : data(x),left(nullptr),right(nullptr){};
}*TNode;

//串
typedef struct SString
{
    char[MAXLEN];
    int length;
}SString;

//栈Stack
typedef struct SQtack
{
    ElementType data[MAXLEN];
    int top;//栈顶指针 
}SqStack;

bool PushStack(SqStack &S,ElementType x){
    if (S.top==MAXLEN-1)
    {
        return false;
    }
    S.data[++S.top]=x;
    return true;
}
bool GetTop(SqStack &S,ElementType &x){
    if (S.top==-1)
    {
        return false;
    }
    x=S.data[S.top];
    return true;
}
bool Pop(SqStack &S,ElementType &x){
    if (S.top==-1)
    {
        return false;
    }
    x=S.data[S.top--];
    return true;
}

#endif //CARL_CODE_DEFAULT_H
