/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
 */

// @lc code=start


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
    int sum{INT_MIN};
    int maxPathSum(TreeNode* root) {
        traverse(root);
        return sum;
    }
    int traverse(TreeNode* root){
        if(root == nullptr)
            return 0;
        int res = 0;
        int left_sum = max(0, traverse(root->left));
        int right_sum = max(0, traverse(root->right));
        sum = max(sum, left_sum + right_sum + root->val);
        return root->val + max(left_sum, right_sum);
    }
};
// @lc code=end

