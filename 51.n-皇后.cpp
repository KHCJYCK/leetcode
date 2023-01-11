/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> board;
    vector<vector<string>> res;

    vector<vector<string>> solveNQueens(int n) {
        board.resize(n, string(n, '.'));
        backtrack(0);
        return res;
    }
    //n为行数
    void backtrack(int row){
        if(row == board.size())
            res.push_back(board);
        for(int col = 0; col < board.size(); col++){
            if(!is_valid(row, col))
                continue;
            board[row][col] = 'Q';
            backtrack(row + 1);
            board[row][col] = '.';
        }
    }
    bool is_valid(int row, int col){
        for(int i = 0; i < row; i++){
            //判断所在列是否合法
            if(board[i][col] == 'Q')
                return false;
        }
        //左上
        int i = row, j = col;
        while(--i >= 0 && --j >= 0){
            if(board[i][j] == 'Q')
                return false;
        }
        //右上
        i = row, j = col;
        while(--i >= 0 && ++j < board.size()){
            if(board[i][j] == 'Q')
                return false;
        }
        return true;
    }
};
// @lc code=end

