//
// Created by 春江花朝秋月夜 on 2024/3/24.
//
//LCR 最大公共字串，使用动态规划去解决此类问题

//给定两个字符串 text1 和 text2，返回这两个字符串的最长 公共子序列 的长度。如果不存在 公共子序列 ，返回 0 。
//
//一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。
//
//例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。
//两个字符串的 公共子序列 是这两个字符串所共同拥有的子序列。

//输入：text1 = "abc", text2 = "abc"
//输出：3
//解释：最长公共子序列是 "abc" ，它的长度为 3 。

//输入：text1 = "abcde", text2 = "ace"
//输出：3
//解释：最长公共子序列是 "ace" ，它的长度为 3 。

#include "../cunion.h"
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1=text1.size();
        int len2=text2.size();

        vector<char> vec;
        if (len1>len2){
            for (int i = 0; i < len2; ++i) {
                if (text1.at(i)==text2.at(i)){
                    vec.push_back(text1.at(i));
                } else{
                    compare(text1,text2,i,len1);
                }
            }
        }
        return vec.size();
    }
    vector<char> compare(string s1,string s2,int l,int r){
        vector<char> res;

        for (int i = l; i < r ; ++i) {
            if (s1.at(i)==s2.at(i)){
                res.push_back(s1.at(i));
            } else{
              return  compare(s1.replace(0,i,""),s2.replace(0,i,""),l+1,r);
            }
        }
        return res;
    }
};