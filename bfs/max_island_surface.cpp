//
// Created by 春江花朝秋月夜 on 2024/4/4.
//

//class Solution {
//    public int maxAreaOfIsland(int[][] grid) {
//        int row=grid.length;
//        int col=grid[0].length;
//        int sum=0;
//        for(int i=0;i<row;i++){
//            for(int j=0;j<col;j++){
//                sum=Math.max(bfs(grid,i,j),sum);
//            }
//        }
//        return sum;
//    }
//    //对当前坐标进行优先搜索
//    public int bfs(int [][]grid,int row,int col){
//        if(row<0||row>=grid.length||col<0||col>=grid[0].length||grid[row][col]!=1){
//            return 0;
//        }
//        grid[row][col]=0;
//        return 1+bfs(grid,row-1,col)+bfs(grid,row,col+1)+bfs(grid,row+1,col)+bfs(grid,row,col-1);
//    }
//}
#include "../cunion.h"
class Solution {
public:
    int bfs(vector<vector<int>> &grid, int row, int col) {
        //越界情况：
        if(row<0||row>=grid.size()||col<0||col>=grid[0].size()||grid[row][col]!=1){
            return 0;
        }
        grid[row][col]=0;
        return 1+bfs(grid,row-1,col)+bfs(grid,row,col+1)+bfs(grid,row+1,col)+bfs(grid,row,col-1);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        int maxSurface=0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                maxSurface= max(bfs(grid,i,j),maxSurface);
            }
        }
        return maxSurface;
    }
};