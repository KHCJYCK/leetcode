/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int row, col;
    int numIslands(vector<vector<char>>& grid) {
        row = grid.size();
        if(row == 0)
            return 0;
        col = grid[0].size();
        int res = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == '1'){
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
    void dfs(vector<vector<char>>& grid, int i, int j){
        if(i < 0 || j < 0 || i >= row || j >= col || grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        dfs(grid, i, j - 1);
        dfs(grid, i , j + 1);
        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
    }
};
// @lc code=end

