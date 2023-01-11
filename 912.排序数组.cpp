/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    //归并排序
    // vector<int> temp;
    // vector<int> sortArray(vector<int>& nums) {
    //     temp.resize(nums.size());
    //     sort(nums, 0, nums.size() - 1);
    //     return nums;
    // }
    // void sort(vector<int>& nums, int left, int right){
    //     if(left == right)
    //         return;
    //     int mid = left + (right - left) / 2;
    //     sort(nums, left, mid);
    //     sort(nums, mid + 1, right);
    //     merge(nums, left, mid, right);
    // }
    // void merge(vector<int>& nums, int left, int mid, int right){
    //     for(int i = left; i <= right; i++){
    //         temp[i] = nums[i];
    //     }
    //     int lhs = left, rhs = mid + 1;
    //     for(int i = left; i <= right; i++){
    //         if(rhs == right + 1)
    //             nums[i] = temp[lhs++];
    //         else if(lhs == mid + 1)
    //             nums[i] = temp[rhs++];
    //         else if(temp[lhs] <= temp[rhs])
    //             nums[i] = temp[lhs++];
    //         else
    //             nums[i] = temp[rhs++];
    //     }
    //     return;
    // }
    //快速排序
    vector<int> sortArray(vector<int>& nums) {
        sort(nums, 0, nums.size() - 1);
        return nums;
    }
    void sort(vector<int>& nums, int low, int high){
        if(low >= high)
            return;
        int p = partition(nums, low, high);
        sort(nums, low, p - 1);
        sort(nums, p + 1, high);
    }
    int partition(vector<int>& nums, int low, int high){
        int pivot = nums[low];
        int i = low + 1, j = high;
        while(i <= j){
            while(i <= j && nums[i] <= pivot)
                i++;
            while(i <= j && nums[j] > pivot)
                j--;
            if(i > j)
                break;
            swap(nums[i], nums[j]);
        }
        swap(nums[low], nums[j]);
        return j;
    }
    void shuffle(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0 ; i < n; i++) {
            // 生成 [i, n - 1] 的随机数
            int r = i + (rand() % (n - i));
            swap(nums, i, r);
        }
    }
};
// @lc code=end

