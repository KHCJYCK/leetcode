/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size(), fast = 0, slow = 0;
        for(; fast < len; fast++){
            if(nums[fast] > nums[slow])
                nums[++slow] = nums[fast];
        }
        return slow + 1;
    }
};
// @lc code=end

