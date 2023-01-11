/*
 * @lc app=leetcode.cn id=1254 lang=cpp
 *
 * [1254] 统计封闭岛屿的数目
 */

// @lc code=start

#include <vector>
using namespace std;
class Solution {
public:
    int row, col;
    int closedIsland(vector<vector<int>>& grid) {
        row = grid.size();
        if(row == 0)
            return 0;
        col = grid[0].size();
        int res = 0;
        for(int i = 0; i < row; i++){
            dfs(grid, i, 0);
            dfs(grid, i, col - 1);
        }
        for(int i = 0; i < col; i++){
            dfs(grid, 0, i);
            dfs(grid, row - 1, i);
        }

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 0){
                    res++;
                    dfs(grid, i, j - 1);
                    dfs(grid, i , j + 1);
                    dfs(grid, i - 1, j);
                    dfs(grid, i + 1, j);
                }
            }
        }
        return res;
    }
    void dfs(vector<vector<int>>& grid, int i, int j){
        if(i < 0 || j < 0 || i >= row || j >= col || grid[i][j] == 1)
            return;
        grid[i][j] = 1;
        dfs(grid, i, j - 1);
        dfs(grid, i , j + 1);
        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
    }
};
// @lc code=end

