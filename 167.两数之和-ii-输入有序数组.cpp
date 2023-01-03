/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int len = numbers.size(), left = 0, right = len - 1;
        while(left < right){
            int sum = numbers[left] + numbers[right];
            if(sum == target)
                return  {left + 1, right + 1};
            if(sum < target)
                left++;
            else
                right--;
        }
        return {}; 
    }
};
// @lc code=end

