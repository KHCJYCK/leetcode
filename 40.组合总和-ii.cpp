/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> trace;
    int target;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
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
            if(i > n && candidates[i] == candidates[i - 1])
                continue;
            trace.push_back(candidates[i]);
            sum += candidates[i];
            backtrack(candidates, sum, i + 1);
            trace.pop_back();
            sum -= candidates[i];
        }
    }
};
// @lc code=end

