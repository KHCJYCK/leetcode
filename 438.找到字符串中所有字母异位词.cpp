/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        unordered_map<char, int> need, window;
        int left = 0, right = 0, len = s.size(), valid = 0;
        for(auto ch : p)
            need[ch]++;
        while(right < len){
            char ch = s[right];
            right++;
            if(need.count(ch)){
                window[ch]++;
                if(need[ch] == window[ch])
                    valid++;
            }
            while(valid == need.size()){
                int len = right - left;
                if(len == p.size()){
                    res.emplace_back(left);
                }
                char d = s[left];
                if(need.count(d)){
                    if(--window[d] < need[d])
                        valid--;
                }
                left++;
            }
        }
        return res;
    }
};
// @lc code=end

