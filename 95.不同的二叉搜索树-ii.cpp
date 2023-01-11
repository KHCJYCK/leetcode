/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
 */

// @lc code=start
#include <vector>
using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return build(1, n);
    }

    vector<TreeNode*> build(int low, int high){
        vector<TreeNode*> res;
        if(low >high){
            res.push_back(nullptr);
            return res;
        }
        for(int i = low; i <= high; i++){
            vector<TreeNode*> left = build(low, i - 1);
            vector<TreeNode*> right = build(i + 1, high);
            for(auto lhs : left){
                for(auto rhs : right){
                    auto root = new TreeNode(i);
                    root->left = lhs;
                    root->right = rhs;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};
// @lc code=end

