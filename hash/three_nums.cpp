//
// Created by 春江花朝秋月夜 on 2024/3/25.
//
#include "../cunion.h"

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> res;
        //排序
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[0] > 0) {
                break;
            }
            unordered_set<int> set;
            //去重
            if (i > 0 && nums[i - 1] == nums[i]) {
                continue;
            }
            for (int j = i + 1; j < nums.size(); ++j) {
                int target = 0 - (nums[i] + nums[j]);
                if (set.find(target) != set.end()) {
                    res.push_back(vector<int>{nums[i], nums[j], target});
                } else {
                    res.push_back(vector<int>{nums[j]});
                }
            }
        }
        return res;
    };

    int threeSumClosest(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int closestNum = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < len; ++i) {
            int j = i + 1;
            int k = len - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target) {
                    return target;//刚好相等，直接返回目标元素
                }
                if (abs(target - sum) < abs(target - closestNum)) {
                    closestNum = sum;
                }
                if (sum > target) {
                    k--;
                } else {
                    j++;
                }
            }
        }
        return closestNum;
    }
};

/**
 * 给你一个长度为 n 的整数数组 nums 和 一个目标值 target。请你从 nums 中选出三个整数，使它们的和与 target 最接近。

    返回这三个数的和。

    假定每组输入只存在恰好一个解。



    示例 1：

    输入：nums = [-1,2,1,-4], target = 1
    输出：2
    解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。
 */

/** 最接近的三数之和：
* class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int best=Integer.MAX_VALUE;
        int n=nums.length;//数组长度
        for(int i=0;i<n;i++){
            int j=i+1,k=n-1;
            //二分
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum==target) return target;//刚好相等，直接返回目标元素
                if(Math.abs(target-sum)<Math.abs(best-target)){
                    best=sum;
                }else if(sum>target){
                    k--;
                }else{
                    j++;
                }
            }
        }
        return best;
    }
}
*/