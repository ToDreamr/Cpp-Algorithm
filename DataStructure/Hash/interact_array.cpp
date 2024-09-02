//
// Created by 春江花朝秋月夜 on 2024/3/24.
//
#include "../../cunion.h"
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(0);
        if (nums1.size()==0||nums2.size()==0){
            return res;
        }
        unordered_set<int> setp;
        unordered_set<int> setq;
        for (int i = 0; i < nums1.size(); ++i) {
            setp.insert(nums1[i]);
        }
        //在前面的数组中出现过
        for (int i = 0; i < nums2.size(); ++i) {
            if (setp.find(nums2[i]) != setp.end()) {
                setq.insert(nums2[i]);
            }
        }
        return vector<int>(setq.begin(),setq.end());
    }
};