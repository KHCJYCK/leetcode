/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    //dp
    string longestPalindrome(string s) {
        int len = s.size();
        if (len < 2) {
            return s;
        }
        int max_index = INT_MIN, max_len = INT_MIN;
        vector<vector<bool>> dp(len, vector<bool>(len, false));
        for(int l = 1; l <= len; l++){
            for(int i = 0; i < len - l + 1; i++){
                int j = i + l -1;
                if(l < 3){
                    dp[i][j] = (s[i] == s[j]);
                }
                else{
                    dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];
                }
                if (dp[i][j] && l > max_len) {
                    max_len = l;
                    max_index = i;
                }
            }
        }
        return s.substr(max_index, max_len);
    }
    //中心扩展
    // string palindrome(string& s, int left, int right){
    //     while(left >= 0 && right < s.size() && s[left] == s[right]){
    //         left--;
    //         right++;
    //     }
    //     return s.substr(left + 1, right - left - 1);
    // }
    // string longestPalindrome(string s) {
    //     string res = "";
    //     for (int i = 0; i < s.size(); i++) {
    //     // 以 s[i] 为中⼼的最⻓回⽂⼦串
    //     string s1 = palindrome(s, i, i);
    //     // 以 s[i] 和 s[i+1] 为中⼼的最⻓回⽂⼦串
    //     string s2 = palindrome(s, i, i + 1);
    //     // res = longest(res, s1, s2)
    //     res = res.size() > s1.size() ? res : s1;
    //     res = res.size() > s2.size() ? res : s2;
    //     }
    //     return res;
    // }
};
// @lc code=end

