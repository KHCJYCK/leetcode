/*
 * @lc app=leetcode.cn id=921 lang=cpp
 *
 * [921] 使括号有效的最少添加
 */

// @lc code=start
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    // int minAddToMakeValid(string s) {
    //     stack<char> st;
    //     int need = 0;
    //     for(auto ch : s){
    //         if(ch == '(')
    //             st.push(ch);
    //         else{
    //             if(st.empty())
    //                 need++;
    //             else
    //                 st.pop();
    //         }
    //     }
    //     return st.size() + need;
    // }    
    int minAddToMakeValid(string s) {
        int left = 0, right = 0;
        for(auto ch : s){
            if(ch == '(')
                left++;
            else{
                left--;
                if(left == -1){
                    left = 0;
                    right++;
                }
            }
        }
        return left + right;
    }
};
// @lc code=end

