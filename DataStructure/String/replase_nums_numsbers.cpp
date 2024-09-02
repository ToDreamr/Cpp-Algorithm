////
//// Created by 春江花朝秋月夜 on 2024/3/28.
////
//#include "bits/stdc++.h"
//using namespace std;
//
//int main(){
//    String s;
//    //a1bc2hh->anumberbcnumberhh
//    while(cin>>s){
//        int count=0;//统计数字的个数
//        //遍历字符串，用字符串数组的方法来进行遍历
//        int oldSize=s.size();
//        std::vector<char>tmp ;
//        unordered_set<int> index;
//        for (int i = 0; i < s.size(); i++) {
//            /* code */
//            if(s[i]>='0'&&s[i]<='9'){
//                count++;
//                index.insert(i);
//            }
//            //从后面进行插入
//            if(s[i]>='a'&&s[i]<='z'){
//                tmp.push_back(s[i]);
//            }
//        }
//        //需要输出count*number,额外申请6*count空间
//        s.resize(oldSize+5*count);
//        //此时之前的数字还没有完成替换，需要进行替换操作
//        int newSize=s.size();
//        for (int i = newSize - 1, j = oldSize - 1; j < i; i--, j--) {
//            if (s[j] > '9' || s[j] < '0') {
//                s[i] = s[j];//将原来的字母放到后面去，这地方没理解
//            } else {
//                s[i] = 'r';
//                s[i - 1] = 'e';
//                s[i - 2] = 'b';
//                s[i - 3] = 'm';
//                s[i - 4] = 'u';
//                s[i - 5] = 'n';
//                i -= 5;
//            }
//        }
//        cout<<s<<endl;
//    }
//}

#include "algorithm"
#include "iostream"
#include "vector"

using namespace std;

int main() {
    vector<int> nums;
    int number;
    int index = 0;
    while (cin >> number) {
        nums[index++] = number;//处理输入的数
    }
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == nums[i - 1] && i > 0) continue;
        int left = i + 1;
        int right = nums.size() - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum > 0) {
                right--;
            } else if (sum < 0) {
                left++;
            } else {
                res.push_back({nums[i], nums[left], nums[right]});
                while (right > left && nums[right] == nums[right - 1]) {
                    right++;
                }
                while (right > left && nums[left] == nums[left + 1]) {
                    left++;
                }
                right--;
                left++;
            }
        }
    }
    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[0].size(); ++j) {
            cout << res[i][j] << endl;
        }
    }
}
