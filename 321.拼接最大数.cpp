/*
 * @lc app=leetcode.cn id=321 lang=cpp
 *
 * [321] 拼接最大数
 */

// @lc code=start
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> merge(vector<int>& nums1, vector<int>& nums2){
        int len1= nums1.size(), len2 = nums2.size();
        int left = 0, right = 0;
        vector<int> res(len1 + len2);
        for(int i = 0; i < res.size(); i++){
            if(left < len1 && right < len2){
                if(nums1[left] > nums2[right]){
                    res[i] = nums1[left++];
                } 
                else if(nums1[left] > nums2[right]){
                    res[i] = nums2[right++];
                }
                else{
                    int temp1 = left, temp2 = right;
                    while(temp1 < len1 && temp2 < len2 && nums1[temp1++] == nums2[temp2++]){}
                    if(temp1 == len1 || temp2 == len2)
                        res[i] = nums1[left++];
                    else{
                        res[i] = (nums1[temp1] > nums2[temp2] ? nums1[left++] : nums2[right++]);
                    }
                }
            }
            else if(left == len1){
                res[i] = nums2[right++];
            }
            else{
                res[i] = nums1[left++];
            }
        }
        return res;
    }
    vector<int> MaxSubSequence(vector<int>& nums, int k){
        int len = nums.size(), del = len - k;
        vector<int> stk;
        for(auto num : nums){
            while(!stk.empty() && stk.back() < num && del > 0){
                stk.pop_back();
                del--;
            }
            stk.push_back(num);
        }
        while(del--){
            stk.pop_back();
        }
        return stk;
    }
    int get_number(vector<int>& nums){
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            res = res * 10 + nums[i];
        }
        return res;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> res;
        int max_num = INT_MIN;
        int len1 = nums1.size(), len2 = nums2.size();
        for(int i = 0; i <= min(k, len1); i++){
            int j = k - i;
            if(j > nums2.size())
                continue;
            vector<int> sub1 = MaxSubSequence(nums1, i);
            vector<int> sub2 = MaxSubSequence(nums2, j);
            vector<int> mer = merge(sub1, sub2);
            if(get_number(mer) > max_num){
                res = mer;
                max_num = get_number(mer);
            }
        }
        return res;
    }
};
// @lc code=end

