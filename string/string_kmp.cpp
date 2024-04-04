//
// Created by 春江花朝秋月夜 on 2024/4/2.
//
#include "string"
#include "iostream"
#include "vector"
#include <cmath>

using namespace std;

//kmp算法来解决字符串字串匹配问题

//KMP的经典思想就是:当出现字符串不匹配时，可以记录一部分之前已经匹配的文本内容，利用这些信息避免从头再去做匹配。

//重点：如何通过next数组来记录之前匹配过的文本内容

//前缀表：next数组作为前缀表，用于回退，记录了模式串和主文本串 不匹配时应该从哪里开始重新匹配。
