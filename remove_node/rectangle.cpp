//
// Created by 春江花朝秋月夜 on 2024/3/26.
//
//#include<iostream>
//using namespace std;
//
//int main(){
//    char ch;
//    int n;
//
//    while (cin >> ch >> n) {
//        //处理特殊情况
//        if (ch == '@')  break;
//        if (n == 1) {
//            cout << ch << endl << endl;
//            continue;
//        }
//
//        //处理第一行
//        for (int j = 0; j < n - 1; j++)  cout << " ";
//        cout << ch << endl;
//
//        //处理 2 ~ n - 1 行
//        for (int i = 2; i < n; i++) {
//            //前导空格
//            for (int j = 0; j < n - i; j++)  cout << " ";
//            //左端字符
//            cout << ch;
//            //中间空格
//            for (int j = 0; j < 2 * (i - 1) - 1; j++)   cout << " ";
//            //右端字符
//            cout << ch << endl;
//        }
//
//        //处理最后一行
//        for (int j = 0; j < 2 * n - 1; j++) cout << ch;
//        cout << endl << endl;
//    }
//
//    return 0;
//}