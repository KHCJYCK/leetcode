/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> getNextGrenter(vector<int>& nums){
        int len = nums.size();
        stack<int> st;
        vector<int> res(len);
        for(int i = len - 1; i >= 0; i--){
            while(!st.empty() && nums[i] >= st.top()){
                st.pop();
            }
            res[i] = st.empty() ? -1 : st.top();
            st.push(nums[i]);
        }
        return res;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map;
        vector<int> res(nums1.size());
        vector<int> greater = getNextGrenter(nums2);
        for(int i = 0; i < nums2.size(); i++){
            map[nums2[i]] = greater[i];
        }
        for(int i = 0; i < nums1.size(); i++){
            res[i] = map[nums1[i]];
        }
        return res;
    }
};
// @lc code=end

