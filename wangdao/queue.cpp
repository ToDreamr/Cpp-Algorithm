//
// Created by 春江花朝秋月夜 on 2024/4/9.
//
#include "default.h"
#define MaxSize 100

typedef struct {
    ElemType data[MaxSize];
    int front;//指向队头元素
    int rear;//指向队尾元素的后一个位置
    //辅助变量⬇️
    int size;//队列的当前长度,队满条件：size==MaxSize
    int tag;//插入=1;删除=0;队满条件：tag==1&&(Q.rear==Q.front)
} SqQueue;
//队头，队尾，空队列 FIFO
//队列中的元素个数：(rear+MaxSize-front)%MaxSize
//顺序实现：
void InitQueue(SqQueue &Q){
    Q.front=Q.rear=Q.size=0;
}

bool QueueEmpty(SqQueue Q){
    //如果没有size变量，将会牺牲一个元素空间
    if (Q.rear==Q.front){
        return true;
    }
    return false;
}

bool EnQueue(SqQueue &Q,ElemType e){
    if ((Q.rear+1)%MaxSize==Q.front){
        return false;//队列已满
    }
    Q.data[Q.rear]=e;
    Q.rear=(Q.rear+1)%MaxSize;
    return true;
}
bool DeQueue(SqQueue &Q,ElemType e){
    if (!QueueEmpty(Q)){
        e=Q.data[Q.front];
        Q.front=(Q.front+1)%MaxSize;
        return true;
    }
    return false;
}
ElemType GetTop(SqQueue &Q){
    if (!QueueEmpty(Q)){
        return Q.data[Q.front];
    }
    return false;
}

//队列的链式存储：
typedef struct {
    LinkNode *front,*rear;//队列的队头和队尾指针
} LinkQueue;

bool isEmpty(LinkQueue &Q){
    if ((Q.front==Q.rear)||Q.front==NULL){
     return true;
    }
    return false;
}
void InitQueue(LinkQueue &Q){
    //需要为队头和队尾声明空间
    //Q.front=Q.rear= (LinkNode*)malloc(sizeof (LinkNode))
    Q.front=Q.rear=new LinkNode ;
    Q.front=Q.rear=NULL;
}
void EnQueue(LinkQueue &Q,ElemType e){
    LNode s=new LinkNode;
    s->data=e;
    s->next=NULL;
    Q.rear->next=s;
    Q.rear=s;
}
bool Dequeue(LinkQueue &Q,ElemType &tmp){
    if (isEmpty(Q)){
        return false;
    }
    LNode s=Q.front->next;
    tmp=s->data;
    Q.front->next=s->next;
    if (Q.rear==s){
        Q.rear=Q.front;//最后一次出队
    }
    delete(s);
    return true;
}