//  构建堆排序的算法
// Created by Rainy-Heights on 2024/12/13.
//
#include "my_sort.h"
//堆调整.
void HeadAdjust(ElemType A[],int k,int len){
    A[0]=A[k];//A[0]暂存子树的根节点
    for (int i = 2*k; i <= len ; i*=2) {
        if (i<len&&A[i]<A[i+1]){
            i++;
        }
        if (A[0]>A[i]){
            break;
        } else{
            A[k]=A[i];
            k=i;
        }
    }
    A[k]=A[0];
}
void buildMaxHeap(ElemType A[], int len) {
    for (int i = len / 2; i > 0; --i) {
        HeadAdjust(A,i,len);
    }
}
void swap(ElemType A,ElemType B){
    int tmp=B;
    B=A;
    A=tmp;
}
void HeapSort(ElemType A[],int len){
    buildMaxHeap(A,len);
    for (int i = len; i > 1 ; --i) {
        swap(A[i],A[1]);
        HeadAdjust(A,1,i-1);
    }
}
int main(){
    ElemType A[]={1,3,2,1,2,3,45,3,4,67,8,2};
    HeapSort(A,10);
    for (int i = 0; i < 10; ++i) {
        printf("%d ",A[i]);
    }
}