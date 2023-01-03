/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

// @lc code=start
#include <string>
#include <unordered_map>
using namespace std;


class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> need, window;
        int left = 0, right = 0, len = s2.size(), valid = 0;
        for(auto ch : s1)
            need[ch]++;
        while(right < len){
            char ch = s2[right];
            right++;
            if(need.count(ch)){
                window[ch]++;
                if(need[ch] == window[ch])
                    valid++;
            }
            while(valid == need.size()){
                int len = right - left;
                if(len == s1.size())
                    return true;
                char d = s2[left];
                if(need.count(d)){
                    if(--window[d] < need[d])
                        valid--;
                }
                left++;
            }
        }
        return false;
    }
};
// @lc code=end

