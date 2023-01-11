/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int index;
    int findKthLargest(vector<int>& nums, int k) {
        index = nums.size() - k;
        shuffle(nums);
        sort(nums, 0, nums.size() - 1);
        return nums[index];
    }
    void sort(vector<int>& nums, int low, int high){
        if(low >= high)
            return;
        int p = partition(nums, low, high);
        if(p == index){
            index = p;
            return;
        }
        if(p < index)
            sort(nums, p + 1, high);
        else
            sort(nums, low, p - 1);
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
            swap(nums[i], nums[r]);
        }
    }
};
// @lc code=end

