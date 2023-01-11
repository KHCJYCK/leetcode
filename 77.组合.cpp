/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> trace;
    int _k, _n;
    vector<vector<int>> combine(int n, int k) {
        _k = k;
        _n = n;
        backtrack(1);
        return res;
    }
    void backtrack(int n){
        if(trace.size() == _k)
            res.push_back(trace);
        for(int i = n; i <= _n; i++){
            trace.push_back(i);
            backtrack(i + 1);
            trace.pop_back();
        }
    }
};
// @lc code=end

