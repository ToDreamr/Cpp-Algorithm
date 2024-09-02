//
// Created by 春江花朝秋月夜 on 2024/4/15.
//

#ifndef CARL_CODE_MY_SORT_H
#define CARL_CODE_MY_SORT_H
#include "iostream"
#include "vector"
using namespace std;
//待排序的记录
#define MAXSIZE 20
typedef int KeyType;
typedef int InfoType;
typedef struct RedType{
    KeyType  key;//关键字的值
    InfoType otherInfo;//其他信息
}RedType;

typedef struct SqList{
    RedType r[MAXSIZE];
    int length;
}SqList;
#endif //CARL_CODE_MY_SORT_H
