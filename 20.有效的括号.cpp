/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    char leftof(char ch){
        if(ch == ')')
            return '(';
        else if(ch == ']')
            return '[';
        else
            return '{';
    }
    bool isValid(string s) {
        stack<char> st;
        for(auto ch : s){
            if(ch == '(' || ch == '[' || ch == '{')
                st.push(ch);
            else{
                if(!st.empty() && leftof(ch) == st.top())
                    st.pop();
                else
                    return false;
            }
        }
        return st.empty();
    }
};
// @lc code=end

