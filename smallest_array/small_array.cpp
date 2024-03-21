//
// Created by Rainy-Heights on 2024/3/19.
//
#include <iostream>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int right = nums.size();
        if(right == 0){
            return 0;
        }
        int ans = INT_MAX;
//        vector<int> sums(right+1,0);//要多一个长度，前缀和
        int *sums = (int *)malloc(sizeof(int) * (right + 1));
        //计算前缀和
        for(int i =1; i<=right; i++){
            sums[i] = sums[i-1]+nums[i-1];//太妙了，这样就可以计算前缀和了
        }
        //二分法
        for(int i = 1;i <= right; i++){
            int mid = target+sums[i-1];
            int bound = lower_bounds(sums, 1, right, mid);
            if(bound != -1){
                ans=min(ans,(bound - ( i - 1 )));
            }
        }
        return ans ==  INT_MAX ? 0 : ans;
    }
    int lower_bounds(int *array, int l, int r, int q) {
        if (array[r] < q) return -1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (array[mid] >= q) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};

int main(){
    vector<int> nums={2,3,1,2,4,3};
//    vector<int> nums={1,1,1,1,1,1,1};
    Solution *solution;
    printf("%d",solution->minSubArrayLen(7,nums));
}