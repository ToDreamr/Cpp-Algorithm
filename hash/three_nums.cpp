//
// Created by 春江花朝秋月夜 on 2024/3/25.
//
#include "../cunion.h"
#include "bits/stdc++.h"
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        //排序
        sort(nums.begin(),nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[0]>0){
                break;
            }
            unordered_set<int> set;
            //去重
            if (i>0&&nums[i-1]==nums[i]){
                    continue;
            }
            for (int j = i+1; j <nums.size(); ++j){
                int target=0-(nums[i]+nums[j]);
                if (set.find(target)!=set.end()){
                    res.push_back(vector<int>{nums[i],nums[j],target});
                } else{
                    res.push_back(vector<int>{nums[j]});
                }
            }
        }
        return res;
    }
};