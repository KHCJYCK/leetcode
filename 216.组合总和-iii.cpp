/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> res;
    vector<int> trace;
    int target, k;
    vector<vector<int>> combinationSum3(int k, int n) {
        this->target = n;
        this->k = k;
        int times = 0, sum = 0;
        backtrack(sum, times, 1);
        return res;
    }   
    void backtrack(int& sum, int& times, int n){
        if(sum == target && times == k){
            res.push_back(trace);
            return;
        }
        if(sum > target || times > k)
            return;
        for(int i = n; i < 10; i++){
            trace.push_back(i);
            sum += i;
            times += 1;
            backtrack(sum, times, i + 1);
            trace.pop_back();
            times -= 1;
            sum -= i;
        }
    }
};
// @lc code=end

