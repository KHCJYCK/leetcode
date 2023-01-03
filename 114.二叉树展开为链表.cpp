/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
    void flatten(TreeNode* root) {
        if(root == nullptr)
            return;
        flatten(root->left);
        flatten(root->right);
        TreeNode* right = root->right;
        root->right = root->left;
        root->left = nullptr;
        TreeNode* temp = root;
        while(temp->right){
            temp = temp->right;
        }
        temp->right = right;
    }
};
// @lc code=end

