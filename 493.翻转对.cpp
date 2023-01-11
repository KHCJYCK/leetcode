/*
 * @lc app=leetcode.cn id=493 lang=cpp
 *
 * [493] 翻转对
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int count = 0;
    vector<int> temp;
    int reversePairs(vector<int>& nums) {
        temp.resize(nums.size());
        sort(nums, 0, nums.size() - 1);
        return count;
    }
    void sort(vector<int>& nums, int left, int right){
        if(left == right)
            return;
        int mid = left + (right - left) / 2;
        sort(nums, left, mid);
        sort(nums, mid + 1, right);
        merge(nums, left, mid, right);
    }
    void merge(vector<int>& nums, int left, int mid, int right){
        for(int i = left; i <= right; i++){
            temp[i] = nums[i];
        }
        int end = mid + 1;
        for(int i = left; i <= mid; i++){
            while(end <= right && (long long)temp[i] > 2 * (long long)temp[end])
                end++;
            count += (end - mid - 1);
        }

        int lhs = left, rhs = mid + 1;
        for(int i = left; i <= right; i++){
            if(rhs == right + 1)
                nums[i] = temp[lhs++];
            else if(lhs == mid + 1)
                nums[i] = temp[rhs++];
            else if(temp[lhs] <= temp[rhs])
                nums[i] = temp[lhs++];
            else
                nums[i] = temp[rhs++];
        }
        return;
    }
};
// @lc code=end

