/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0, fast = 0, len = nums.size();
        for(; fast < len; fast++){
            if(nums[fast] != val)
                nums[slow++] = nums[fast];
        }
        return slow;
    }
    void moveZeroes(vector<int>& nums) {
        int index = removeElement(nums, 0);
        for(int i = index; i < nums.size(); i++)
            nums[i] = 0;
    }
};
// @lc code=end

