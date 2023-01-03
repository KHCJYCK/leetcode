/*
 * @lc app=leetcode.cn id=1541 lang=cpp
 *
 * [1541] 平衡括号字符串的最少插入次数
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        int left = 0, need = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                left++;
            }
            else{
                if(i + 1 < s.size() && s[i + 1] == ')'){
                    left--;
                    i = i + 1;
                }
                else{
                    need++;
                    left--;
                }
                if(left == -1){
                    left = 0;
                    need++;
                }
            }
        }
        return left * 2 + need;
    }
};
// @lc code=end

