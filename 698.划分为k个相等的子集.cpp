/*
 * @lc app=leetcode.cn id=698 lang=cpp
 *
 * [698] 划分为k个相等的子集
 */

// @lc code=start
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> k_sum;
    int target;
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if(nums.size() < k)
            return false;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % k != 0)
            return false;
        target = sum / k;
        k_sum.resize(k); 
        sort(nums.begin(), nums.end(), [](auto lhs, auto rhs){
            return lhs > rhs;
        });
        return backtrack(nums, 0);
    }
    bool backtrack(vector<int>& nums, int n){
        if(n == nums.size())
            return true;
        for(int i = 0; i < k_sum.size(); i++){
            //unordered_set<int> s; 
            if(k_sum[i] + nums[n] > target || (i > 0 && k_sum[i] == k_sum[i - 1]))
                continue;
            // if(k_sum[i] + nums[n] > target || s.find(k_sum[i]) != s.end())
            //      continue;
            // s.insert(k_sum[i]);
            k_sum[i] += nums[n];
            if(backtrack(nums, n + 1))
                return true;
            k_sum[i] -= nums[n];
        }
        return false;
    }
};
// @lc code=end

