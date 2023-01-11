/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> trace;
    int target;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        this->target = target;
        int sum = 0;
        backtrack(candidates, sum, 0);
        return res;
    }
    void backtrack(vector<int>& candidates, int& sum, int n){
        if(sum == target){
            res.push_back(trace);
            return;
        }
        if(sum > target)
            return;
        for(int i = n; i < candidates.size(); i++){
            trace.push_back(candidates[i]);
            sum += candidates[i];
            backtrack(candidates, sum, i);
            trace.pop_back();
            sum -= candidates[i];
        }
    }
};
// @lc code=end

