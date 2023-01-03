/*
 * @lc app=leetcode.cn id=1081 lang=cpp
 *
 * [1081] 不同字符的最小子序列
 */

// @lc code=start
class Solution {
public:
    string smallestSubsequence(string s) {
        string res = "";
        vector<int> freq(26, 0);
        vector<bool> contain(26, false);
        for(auto ch : s)
            freq[ch - 'a']++;
        for(auto ch : s){
            if(!contain[ch - 'a']){
                while(!res.empty() && ch < res.back() && freq[res.back() - 'a'] > 0){
                    contain[res.back() - 'a'] = false;
                    res.pop_back();
                }
                res.push_back(ch);
                contain[ch - 'a'] = true;
            }
            freq[ch - 'a']--;
        }
        return res;
    }
};
// @lc code=end

