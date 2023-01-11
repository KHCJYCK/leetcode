/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> trace;
    vector<bool> used;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        used.resize(nums.size(), false);
        backtrack(nums);
        return res;
    }
    void backtrack(vector<int>& nums){
        if(trace.size() == nums.size()){
            res.push_back(trace);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(used[i] || (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]))
                continue;
            used[i] = true;
            trace.push_back(nums[i]);
            backtrack(nums);
            used[i] = false;
            trace.pop_back();
        }
    }
};
// @lc code=end

