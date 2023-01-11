/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> trace;
    vector<bool> is_contain;
    void backtrack(vector<int>& nums){
        if(trace.size() == nums.size())
            res.push_back(trace);
        for(int i = 0; i < nums.size(); i++){
            if(is_contain[i])
                continue;
            trace.push_back(nums[i]);
            is_contain[i] = true;
            backtrack(nums);
            trace.pop_back();
            is_contain[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        is_contain.resize(nums.size(), false);
        backtrack(nums);
        return res;
    }
};
// @lc code=end

