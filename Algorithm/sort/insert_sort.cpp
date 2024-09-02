//
// Created by 春江花朝秋月夜 on 2024/4/15.
//
#include <sstream>
#include "my_sort.h"
#include "../../cunion.h"

//直接插入排序
class direct_insert {
public:
    static void insert_sort(vector<int> nums) {
        int i, j = 0;
        for (i = 2; i <= nums.size(); ++i)
            if (nums[i] < nums[i - 1]) {
                int tmp = nums[i];
                for (j = i - 1; tmp < nums[j]; --j)
                    nums[j + 1] = nums[j];
                nums[j + 1] = tmp;
            }
    }

    //直接插入排序
    static void InsertSort(SqList &L) {
        int i, j;
        //对顺序表做直接插入排序算法，时间复杂度O(n^2)
        for (i = 2; i <= L.length; ++i) {
            //对关键字进行比较,小于有序表前驱的插入有序表
            if (L.r[i].key < L.r[i - 1].key) {
                L.r[0] = L.r[i];//插入记录暂存到哨兵中
                //从后往前寻找可以插入的位置
                for (j = i - 1; L.r[0].key < L.r[j].key; --j) {
                    L.r[j + 1] = L.r[j];
                }
                L.r[j + 1] = L.r[0];
            }
        }
    }

    //折半插入排序
    //变化是查找插入的位置 使用了 二分查找
    static void BInsertSort(SqList &L) {
        for (int i = 2; i <= L.length; ++i) {
            L.r[0] = L.r[i];//存储哨兵
            int left = 1;
            int right = i - 1;
            while (left < right) {
                int mid = (right - left) / 2;
                if (L.r[mid].key > L.r[0].key) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            for (int j = i - 1; j >= right + 1; --j) {
                L.r[j + 1] = L.r[j];
                L.r[right + 1] = L.r[0];
            }
        }
    }
};
