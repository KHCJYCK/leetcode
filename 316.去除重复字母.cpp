/*
 * @lc app=leetcode.cn id=316 lang=cpp
 *
 * [316] 去除重复字母
 */

// @lc code=start
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
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

