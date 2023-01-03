/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
#include <vector>
using namespace std;

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
};
// @lc code=end

