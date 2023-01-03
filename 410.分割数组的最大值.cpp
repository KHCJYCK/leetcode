/*
 * @lc app=leetcode.cn id=410 lang=cpp
 *
 * [410] 分割数组的最大值
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int f(vector<int>& nums, int target){
        int day = 0, sum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(sum + nums[i] > target){
                sum = 0;
                day++;
            }
            sum += nums[i];
        }
        return sum == 0 ? day : day + 1;
    }
    int splitArray(vector<int>& nums, int k) {
        int left = 0, right = 0;
        for(auto num : nums){
            left = max(num, left);
            right += num;
        }
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(f(nums, mid) > k)
                left = mid + 1;
            else
                right = mid - 1;  
        }
        return left;
    }
};
// @lc code=end

