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


#endif //CARL_CODE_DEFAULT_H
