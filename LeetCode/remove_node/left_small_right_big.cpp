//
// Created by 春江花朝秋月夜 on 2024/4/11.
//
#include "iostream"
#include "vector"
#include "cmath"
using namespace std;
class Solution{
public:
    vector<int> findTargetNum(vector<int> nums) {
        vector<int> leftMax;
        vector<int> rightMin;
        leftMax[1]=nums[0];
        rightMin[nums.size()-2]=nums[nums.size()-1];
        vector<int> res;
        for (int i = 2,j=nums.size()-3; i < nums.size() - 2; ++i,j--) {
            leftMax[i]= max(leftMax[i-1],nums[i-1]);
            rightMin[j]= min(rightMin[j+1],nums[j+1]);
        }
        for (int i = 1; i < nums.size()-1; ++i) {
            if (leftMax[i]<=nums[i]&&nums[i]<=rightMin[i]){
                res.push_back(nums[i]);
            }
        }
        return res;
    }
};

int main(){
    auto *solution=new Solution();
    vector<int> test={1,2,3,9,5,6,10,11,13,15,17};
    vector<int> out=solution->findTargetNum(test);
    cout<<"sdsd"<<endl;
    for (int i = 0; i < out.size(); ++i) {
        cout<<out[i]<<" ";
    }
}