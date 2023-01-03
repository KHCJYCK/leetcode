/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;
        int left = 0, right = 0, len = s.size(), valid = 0, min_len = INT_MAX, min_index = 0;
        for(auto ch : t)
            need[ch]++;
        while(right < len){
            char ch = s[right];
            if(need.count(ch)){
                window[ch]++;
                if(window[ch] == need[ch])
                    valid++;
            }
            right++;
            while(valid == need.size()){
                int len = right - left;
                if(len < min_len){
                    min_len = len;
                    min_index = left;
                }
                char ch = s[left];
                if(need.count(ch)){
                    window[ch]--;
                    if(window[ch] < need[ch])
                        valid--;
                }
                left++;
            }
        }
        return (min_len == INT_MAX) ? "":s.substr(min_index, min_len);
    }
};
// @lc code=end

