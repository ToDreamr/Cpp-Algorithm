//
// Created by 春江花朝秋月夜 on 2024/4/9.
//

#ifndef CARL_CODE_DEFAULT_H
#define CARL_CODE_DEFAULT_H

#include "iostream"
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define ElemType int
typedef int Status;

using namespace std;

//单链表：
typedef struct LinkNode {
    ElemType data; //数据域
    struct LinkNode *next;//指针域
} *LNode,LinkNode;
#endif //CARL_CODE_DEFAULT_H
