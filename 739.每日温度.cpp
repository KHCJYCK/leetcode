/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int len = temperatures.size();
        stack<int> st;
        vector<int> res(len);
        for(int i = len - 1; i >= 0; i--){
            while(!st.empty() && temperatures[i] >= temperatures[st.top()])
                st.pop();
            res[i] = st.empty() ? 0 : st.top() - i;
            st.push(i);
        }
        return res;
    }
};
// @lc code=end

