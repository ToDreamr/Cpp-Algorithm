//
// Created by Rainy-Heights on 2024/10/12.
//
#include "iostream"
#include "vector"
#include "numeric"
#include "algorithm"

using namespace std;

int max_sum(vector<int> arr) {
    int n = arr.size();
    int max_sum = accumulate(arr.begin(), arr.end(), 0);
    int cur_sum = max_sum;
    for (int i = 0; i < n - 1; ++i) {
        vector<int> midArr = arr;
        if (midArr[i] < 0 && midArr[i + 1] > 0) {
            midArr[i] = -midArr[i];//反转
        } else if (midArr[i] > 0 && midArr[i + 1] < 0) {
            midArr[i + 1] = -midArr[i + 1];
        } else if ((midArr[i] < 0 && midArr[i + 1] < 0)) {
            midArr[i] = -midArr[i];//反转
            midArr[i + 1] = -midArr[i + 1];
        } else {
            continue;
        }
        int mid_sum = accumulate(midArr.begin(), midArr.end(), 0);
        if (mid_sum > cur_sum) {
            cur_sum = mid_sum;
            if (cur_sum > max_sum) {
                max_sum = cur_sum;
            }
        }
    }
    return max_sum;
}

void perform(vector<int> &neckLace, int a, int b, int op) {
    auto it = find(neckLace.begin(), neckLace.end(), a);
    if (it != neckLace.end()) {
        neckLace.erase(it);
        if (op == 0) {
            neckLace.insert(neckLace.begin() + (find(neckLace.begin(), neckLace.end(), b) - neckLace.begin()), a);
        } else {
            neckLace.insert(neckLace.begin() + (find(neckLace.begin(), neckLace.end(), b) - neckLace.begin() + 1), a);
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << max_sum(arr) << endl;
}