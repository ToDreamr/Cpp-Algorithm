//
// Created by 春江花朝秋月夜 on 2024/3/29.
//
#include "../../cunion.h"

//使用快慢指针来移除字符串里面不符合要求的字符串
//保留单词之间的空格

//首个空格处理

class Solution {
public:
    string reverseWords(string s) {
        int len=s.size();
        //定义快慢指针
        int slowIndex=0;
        int fastIndex=0;
        //去除前面的空格
        while (s.size()>0&&fastIndex<s.size()&&s[fastIndex]!=' '){
            fastIndex++;
        }
        //处理空格
        for (; fastIndex < len; ++fastIndex) {
            if (fastIndex-1>0&&s[fastIndex-1]==s[slowIndex]&&s[slowIndex]==' '){
                continue;
            }else{
                s[slowIndex++]=s[fastIndex];
            }
        }
        if (slowIndex-1>0&&s[slowIndex-1]==' '){
            s.resize(slowIndex-1);
        }else{
            s.resize(slowIndex);
        }
        return s;
    }
};