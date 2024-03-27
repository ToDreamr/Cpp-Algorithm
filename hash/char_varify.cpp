//
// Created by 春江花朝秋月夜 on 2024/3/24.
//
#include "../cunion.h"

//判断字符串给定区间相等：
/**
* 一个字串（比较长）
 * i，j两个变量，长度k
 * i->i+k 和 j->j+k 的子串内容是否相等
*/
//c++自带的哈希表可能调用了古老的代码，使用自己实现的哈希表可以解决更加实际的问题
class Solution{
public:
    bool equals(string s,int i,int j,int k){
        vector<char> sChar;
        if (i==j){
            return true;
        }
        for (int l = 0; l < s.size(); ++l) {
            sChar.push_back(s.at(l));
        }
        unordered_set<char> set;
        if (i<j){
            for (int l = i; l < k; ++l) {
                set.insert(sChar.at(l));
                set.insert(sChar.at(l+j-i));
            }
        } else{
            for (int l = j; l < k; ++l) {
                set.insert(sChar.at(l));
                set.insert(sChar.at(l+i-j));
            }
        }
        if (set.size()!=k){
            return false;
        }
        return true;
    }
};


//int main(){
//    Solution *solution;
//    string check="stu stu kku stu stu";
//    cout<<solution->equals(check,0,11,1)<<endl;
//}