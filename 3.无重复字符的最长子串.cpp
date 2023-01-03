/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
#include <string>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0, len = s.size(), max_len = 0;
        unordered_map<char, int> window;
        while(right < len){
            char ch = s[right];
            right++;
            window[ch]++;
            while(window[ch] > 1){
                char d = s[left];
                window[d]--;
                left++;
            }
            max_len = max(max_len, right - left);
        }
        return max_len;
    }
};
// @lc code=end

