//
// Created by Rainy-Heights on 2024/7/23.
//
#include <ostream>
#include "../cunion.h"
class Arrow{
public:
    int aim_pos;
    double possibility;

    Arrow(int aimPos, double possibility) : aim_pos(aimPos), possibility(possibility) {

    }

    int getAimPos() const {
        return aim_pos;
    }

    void setAimPos(int aimPos) {
        aim_pos = aimPos;
    }

    double getPossibility() const {
        return possibility;
    }

    void setPossibility(double possibility) {
        Arrow::possibility = possibility;
    }

    friend ostream &operator<<(ostream &os, const Arrow &arrow) {
        os << "aim_pos: " << arrow.aim_pos << " possibility: " << arrow.possibility;
        return os;
    }
};


//int main(){
//    vector<vector<string>> doubleVector;//二维向量组
//    map<string,int> indexMap;//下标Map
//    pair<int,int> pairs;//数对
//    indexMap.insert({"eat",0});
//    doubleVector.push_back({"eat","ate","school"});
//    doubleVector.push_back({"be","a","tough","man"});
//
//    doubleVector[indexMap.find("eat")->second].emplace_back("XuLiWei");
//
//    vector<string > chars = doubleVector[0];
//    for(const string& s:chars){
//        cout<<s<<" ";
//    }
//}
