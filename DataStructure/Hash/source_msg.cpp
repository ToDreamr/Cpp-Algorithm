//
// Created by 春江花朝秋月夜 on 2024/3/25.
//

//赎金信件
#include "../../cunion.h"
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        //遍历杂志，记录杂志字母及其次数
        int res[26]={0};
        if (magazine.size()>ransomNote.size()){
            return false;
        }
        for (char i : magazine) {
            res[i-'a']++;
        }
        for (int i = 0; i < ransomNote.size(); ++i) {
            if (ransomNote[i]==res[i]){
                res[i-'a']--;
            }
            if (res[i-'a']<0){
                return false;
            }
        }
        return true;
    }
};