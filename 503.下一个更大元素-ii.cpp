/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */

// @lc code=start
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int len = nums.size();
        vector<int> res(len);
        stack<int> st;
        for(int i = 2 * len - 1; i >= 0; i--){
            while(!st.empty() && nums[i % len] >= st.top())
                st.pop();
            res[i % len] = st.empty() ? -1 : st.top();
            st.push(nums[i % len]);
        }
        return res;
    }
};
// @lc code=end

