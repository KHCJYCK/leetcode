/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int lower_bound(vector<int>& nums, int target){
        int len = nums.size(), left = 0, right = len - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] >= target)
                right = mid - 1;
            else
                left = mid + 1; 
        }
        return left;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return {-1, -1};
        int left = lower_bound(nums, target);
        int right = lower_bound(nums, target + 1) - 1;
        if(left < nums.size() && nums[left] == target)
            return {left, right};
        return {-1,-1};
    }
};
// @lc code=end

