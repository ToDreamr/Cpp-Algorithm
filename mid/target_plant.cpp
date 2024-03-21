//
// Created by Rainy-Heights on 2024/3/19.
//
#include "../cunion.h"
class Solution {
public:
    bool findTargetIn2DPlants(vector<vector<int>>& plants, int target) {
        if (plants.size()==0){
            return false;
        }
        int len=plants.size();
        int row=plants[0].size()-1;
        int column=0;
        while (column<len&&row>=0){
            if (plants[column][row]>target){
                row--;
            } else if (plants[column][row]<target){
                column++;
            } else{
                return true;
            }
        }
        return false;
    }
};

int main(){
    Solution *solution;
    vector<vector<int>> v(0);
    cout<<solution->findTargetIn2DPlants(v,0)<<endl;
}