/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> memo;
    int numTrees(int n) {
        memo.resize(n + 1);
        for(int i = 0; i <= n; i++){
            memo[i].resize(n + 1);
        }
        return build(1, n);
    }

    int build(int low, int high){
        int res = 0;
        if(low > high){
            return 1;
        }
        if(memo[low][high] != 0)
            return memo[low][high];
        for(int i = low; i <= high; i++){
            int left = build(low, i - 1);
            int right = build(i + 1, high);
            res += left * right;
        }
        memo[low][high] = res;
        return res;
    }
};
// @lc code=end

