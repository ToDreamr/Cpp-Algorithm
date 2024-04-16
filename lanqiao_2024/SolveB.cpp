////
//// Created by 春江花朝秋月夜 on 2024/4/14.
////
//#include "head.h"
//#include "unordered_set"
//#include "vector"
//class SolveB{
//public:
//    long like_feBo(int num){
//        int k=num;
//        vector<long> number;
//        while(k>0){
//            number.push_back(k%10);
//            k/=10;
//        }
//        vector<long> res(number.size());
//        int index=0;
//        for (int i = number.size()-1; i >=0; --i) {
//            res[index++]=number[i];
//        }
//        unordered_set<long> set;
//        for (int i = 3; i < 100; ++i) {
//            long curNum=res[i-3]+ res[i-2]+res[i-1];
//            res.push_back(curNum);
//            set.insert(curNum);
//            if (curNum==num){
//                return curNum;
//            }
//        }
//        return -1;
//    }
//};
//int main(){
//    //第n个数等于第n-2+第n-1
//    SolveB *solveB;
//    vector<long> maxNum;
//    for (int i = 0; i < 100; ++i) {
//        long feBoVector=solveB->like_feBo(i);
//        maxNum.push_back(feBoVector);
//    }
//    int target=0;
//    for (int i = 1; i < maxNum.size()-1; ++i) {
//        if (maxNum[i]>maxNum[i-1]){
//            target=maxNum[i];
//        } else{
//            target=maxNum[i-1];
//        }
//    }
////    long target=solveB->like_feBo(197);
////    cout<<target<<endl;
//}
