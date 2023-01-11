/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> res;
    vector<int> trace;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtrack(nums, 0);
        return res;
    }
    void backtrack(vector<int>& nums, int n){
        res.push_back(trace);
        for(int i = n; i < nums.size(); i++){
            if(i > n && nums[i] == nums[i - 1])
                continue;
            trace.push_back(nums[i]);
            backtrack(nums, i + 1);
            trace.pop_back();
        }
    }
};
// @lc code=end

