/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int row, col;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        row = grid.size();
        if(row == 0)
            return 0;
        col = grid[0].size();
        int max_area = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 1){
                    max_area = max(max_area, dfs(grid, i, j));
                }
            }
        }
        return max_area;
    }
    int dfs(vector<vector<int>>& grid, int i, int j){
        if(i < 0 || j < 0 || i >= row || j >= col || grid[i][j] == 0)
            return 0;
        grid[i][j] = 0;
        return 1 + dfs(grid, i, j - 1) + dfs(grid, i , j + 1) + 
        dfs(grid, i - 1, j) + dfs(grid, i + 1, j);
    }
};
// @lc code=end

