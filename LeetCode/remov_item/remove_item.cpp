//
// Created by Rainy-Heights on 2024/3/19.
//
#include "../../cunion.h"

class Solution {
public:
    int removeElement(vector<int> &nums, int val) {
        //定义快慢指针
        int fast = 0;//获取新元素
        int slow = 0;//获取更改位置
        for (fast = 0; fast < nums.size(); fast++) {
            if (nums[fast] != val) {
                nums[slow++] = nums[fast];
            }
        }
        return slow;
    }
};

int main() {
    Solution *solution;
    vector<int> vector;
    vector.push_back(3);
    vector.push_back(2);
    vector.push_back(2);
    vector.push_back(3);

    solution->removeElement(vector, 3);
    for (int i = 0; i < vector.size(); ++i) {
        cout << *vector.data() << endl;
    }
}