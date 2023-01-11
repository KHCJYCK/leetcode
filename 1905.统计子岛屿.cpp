/*
 * @lc app=leetcode.cn id=1905 lang=cpp
 *
 * [1905] 统计子岛屿
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int row, col;
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        row = grid1.size();
        if(row == 0)
            return 0;
        col = grid1[0].size();
        int res = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid1[i][j] == 0 && grid2[i][j] == 1)
                    dfs(grid2, i, j);
            }
        }
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid2[i][j] == 1){
                    res++;
                    dfs(grid2, i, j - 1);
                    dfs(grid2, i , j + 1);
                    dfs(grid2, i - 1, j);
                    dfs(grid2, i + 1, j);
                }
            }
        }
        return res;
    }
    void dfs(vector<vector<int>>& grid, int i, int j){
        if(i < 0 || j < 0 || i >= row || j >= col || grid[i][j] == 0)
            return;
        grid[i][j] = 0;
        dfs(grid, i, j - 1);
        dfs(grid, i , j + 1);
        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
    }
};
// @lc code=end

