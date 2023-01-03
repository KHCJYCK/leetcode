/*
 * @lc app=leetcode.cn id=224 lang=cpp
 *
 * [224] 基本计算器
 */

// @lc code=start
#include <string>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
int calculate(string s) {
    vector<int> stk;
    char preSign = '+';
    int num = 0;
    int n = s.length();
    for (int i = 0; i < n; ++i) {
        if (isdigit(s[i])) {
            num = num * 10 + int(s[i] - '0');
        }
        else if(s[i] == '('){
            num = calculate(s.substr(i + 1, s.size() - i - 1));
            int left = 0;
            for(int j = i + 1; j < n; j++){
                if(s[j] == '(')
                    left++;
                if(s[j] == ')'){
                    if(left == 0){
                        i = j;
                        break;
                    }
                    left--;
                }
            }
        }
        else if(s[i] == ')'){
            break;
        }
        else if (!isdigit(s[i]) && s[i] != ' ' || i == n - 1) {
            switch (preSign) {
                case '+':
                    stk.push_back(num);
                    break;
                case '-':
                    stk.push_back(-num);
                    break;
            }
            preSign = s[i];
            num = 0;
        }
    }
    stk.push_back(preSign == '+' ? num : -num);
    return accumulate(stk.begin(), stk.end(), 0);
}
};
// @lc code=end

