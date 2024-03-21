#include "../cunion.h"

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int num = 1;
        //注意这里是全闭区间
        vector<vector<int>> matrix(n, vector<int>(n));
        int left = 0, right = n - 1, top = 0, bottom = n - 1;
        while (left <= right && top <= bottom) {
            //从左往右
            for (int column = left; column <= right; ++column) {
                matrix[top][column] = num;
                num++;
            }
            for (int row = top + 1; row <= bottom; ++row) {
                matrix[row][right] = num;
                num++;
            }
            //从右往左
            if (left < right && top < bottom) {
                for (int column = right - 1; column > left; --column) {
                    matrix[bottom][column] = num;
                    num++;
                }
                for (int row = bottom; row > top; --row) {
                    matrix[row][left] = num;
                    num++;
                }
            }
            left++;
            right--;
            top++;
            bottom--;
        }
        return matrix;
    }
};

int main() {
    Solution *solution;
    vector<vector<int>> vo = solution->generateMatrix(4);
    for (int i = 0; i < vo.size(); ++i) {
        for (int j = 0; j < vo[i].size(); ++j) {
            printf("%d ", vo[i][j]);
        }
        cout << endl;
    }
}