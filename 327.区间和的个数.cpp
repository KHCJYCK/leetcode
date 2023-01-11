/*
 * @lc app=leetcode.cn id=327 lang=cpp
 *
 * [327] 区间和的个数
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    long long lower, upper, count = 0;
    vector<long long> temp;
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long long> preSum(nums.size() + 1, 0);
        temp.resize(nums.size() + 1);
        this->lower = lower;
        this->upper = upper; 
        for(int i = 1; i < preSum.size(); i++){
            preSum[i] = preSum[i - 1] + nums[i - 1];
        }
        sort(preSum, 0, preSum.size() - 1);
        return count;
    }
    void sort(vector<long long>& nums, int left, int right){
        if(left == right)
            return;
        int mid = left + (right - left) / 2;
        sort(nums, left, mid);
        sort(nums, mid + 1, right);
        merge(nums, left, mid, right);
    }
    void merge(vector<long long>& nums, int left, int mid, int right){
        for(int i = left; i <= right; i++){
            temp[i] = nums[i];
        }
        int start = mid + 1, end = mid + 1;
        for(int i = left; i <= mid; i++){
            while(start <= right && temp[start] - temp[i] < lower)
                start++;          
            while(end <= right && temp[end] - temp[i] <= upper)
                end++;
            count += end - start;
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

