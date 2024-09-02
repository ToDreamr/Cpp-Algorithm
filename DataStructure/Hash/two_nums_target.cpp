//
// Created by 春江花朝秋月夜 on 2024/3/24.
//
#include "../../cunion.h"
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;//k：元素，v：下标
        for (int i = 0; i < nums.size(); ++i){
            if (map.find(target-nums[i])!=map.end()){
                return {map.find(target-nums[i])->second,i};
            }
            map.insert(pair<int,int>(nums[i], i));
        }
        return {};
    }
};