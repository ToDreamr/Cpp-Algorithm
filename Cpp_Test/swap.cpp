//
// Created by 春江花朝秋月夜 on 2024/3/21.
//
#include "../cunion.h"

template <class T>
class Solution{
private:
public:
    Solution()= default;
    void swap(T &a,T &b){
      T tmp=a;
      cout<<tmp<<endl;
      cout<<&a<<endl;
      auto p=&a;
      cout<<*p<<endl;
      cout<<p<<endl;
      a=b;
      b=tmp;
    }
    void swapWithAddr(int *a,int *b){
        int tmp=*a;
        *a=*b;
        *b=tmp;
    }
};

//int main(){
//    auto *solution=new Solution<int >();
//    int x=10;
//    int y=20;
//    solution->swap(x,y);
//    cout<<x<<" "<<y<<endl;
//    solution->swapWithAddr(&x,&y);
//    cout<<x<<" "<<y<<endl;
//    cout<<sizeof (int)<<endl;
//}