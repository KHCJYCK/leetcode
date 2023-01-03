/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
    int diameter{0};
    int diameterOfBinaryTree(TreeNode* root) {
        maxDepth(root);
        return diameter;
    }
    int maxDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;
        int left_height = maxDepth(root->left);
        int right_height = maxDepth(root->right);
        diameter = max(diameter, left_height + right_height);
        return max(left_height, right_height) + 1;
    }
};
// @lc code=end

