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
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        while (left<=right){
            int mid = left + (right-left)/2;
            if (nums[mid] < target){
                left = mid+1;
            } else if (nums[mid] > target){
                right = mid;
            } else{
                return mid;
            }
        }
        return -1;
    }
};

int main(){
    Solution *solution;
    vector<int> vector = {-1,0,3,5,9,12};
    printf("%d",solution->search(vector,9));
}