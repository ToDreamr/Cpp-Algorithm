//
// Created by 春江花朝秋月夜 on 2024/4/9.
//
#include "../wangdao/default.h"
class Solution{
    //答题：
    /**
     * 分配一个用于标记的数组compare[n],记录A中所有的1-n的正整数
     * @param nums
     * @param n
     * @return
     */
    //算法实现
  int real_2018(int nums[],int n) {
      int i,*compare;
      compare= (int *)malloc(sizeof (int )*n);
      for (int j = 0; j < n; ++j) {
          compare[i]=0;
      }
      for(i=0;i<n;i++){
          if (nums[i]<0)continue;
          if (nums[i]>0&&nums[i]<=n){
              compare[nums[i]-1]=1;
          }
      }
      for (i=0;i<n;i++){
          if (compare[i]==0)
              break;
      }
      return i+1;
  }
};