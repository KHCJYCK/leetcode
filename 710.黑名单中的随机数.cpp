/*
 * @lc app=leetcode.cn id=710 lang=cpp
 *
 * [710] 黑名单中的随机数
 */

// @lc code=start
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
unordered_map<int, int> black2wihte;
int bound;
public:
    Solution(int n, vector<int>& blacklist) {
        unordered_set<int> s;
        int m = blacklist.size();
        bound = n - m;
        for(auto black : blacklist){
            if(black >= bound)
                s.insert(black);
        }
        int w = bound;
        for(auto black : blacklist){
            if(black < bound){
                while(s.find(w) != s.end())
                    w++;
                black2wihte[black] =w++;
            }
        }
    }
    int pick() {
        int index = rand() % bound;
        return (black2wihte.find(index) == black2wihte.end()) ? index : black2wihte[index];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */
// @lc code=end

