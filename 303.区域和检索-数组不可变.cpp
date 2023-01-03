/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */

// @lc code=start
#include <vector>
using namespace std;

class NumArray {
private:
    vector<int> preSum;
public:
    NumArray(vector<int>& nums) {
        int len = nums.size();
        preSum.resize(len + 1, 0);
        for(int i = 1; i < len + 1; i++){
            preSum[i] = nums[i - 1] + preSum[i - 1];
        }
    }
    
    int sumRange(int left, int right) {
        return preSum[right + 1] - preSum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end

