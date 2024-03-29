//
// Created by 春江花朝秋月夜 on 2024/3/28.
//
#include "../cunion.h"
class Solution {
public:
    string reverseStrII(string s, int k) {
        //计数2k->翻转前面k个
        //剩余字符少于2k-》翻转前k个
        int len=s.size();
        int i=0;
        while(i<s.size()){
            //只需要判断i+k的位置是不是超出范围即可！！，妙啊
            if((i+k)<=s.size())
            {
                //reverse 函数只需要调用
                reverse(s.begin()+i,s.begin()+i+k);
            }else{
                reverse(s.begin()+i,s.end());
            }
            i+=2*k;
        }
        return s;
    }
    void reverseStrI(vector<char> &s){
        int len=s.size();
        int i=0;
        int j=len-1;
        while (i<j&&i!=j){
            swap(i,j);
        }
    }
};