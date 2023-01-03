/*
 * @lc app=leetcode.cn id=315 lang=cpp
 *
 * [315] 计算右侧小于当前元素的个数
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> count;
    vector<pair<int, int>> temp;
    void merge(vector<pair<int, int>>& nums, int left, int mid, int right){
        for(int i = left; i <= right; i++){
            temp[i] = nums[i];
        }
        int lhs = left, rhs = mid + 1;
        for(int i = left; i <= right; i++){
            if(lhs == mid + 1 || (rhs <= right && temp[lhs].first > temp[rhs].first)){
                //右半区间放入数组
                nums[i] = temp[rhs++];                
            }
            else{
                //左半区间放入数组
                nums[i] = temp[lhs++];
                count[nums[i].second] += rhs - mid - 1;
            }
        }
    }
    void mergeSort(vector<pair<int, int>>& nums, int left, int right){
        if(left == right)
            return;
        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        merge(nums, left, mid, right);
        return;
    }


    vector<int> countSmaller(vector<int>& nums) {
        int len = nums.size();
        vector<pair<int, int>> Pair(len);
        for(int i = 0; i < len; i++){
            Pair[i] = {nums[i], i};
        }
        temp.resize(len);
        count.resize(len);
        mergeSort(Pair, 0, len - 1);
        return count;
    }
};
// @lc code=end

