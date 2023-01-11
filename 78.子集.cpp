/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> trace;
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums, 0);
        return res;
    }
    void backtrack(vector<int>& nums, int n){
        res.push_back(trace);
        for(int i = n; i < nums.size(); i++){
            trace.push_back(nums[i]);
            backtrack(nums, i + 1);
            trace.pop_back();
        }
    }
};
// @lc code=end

