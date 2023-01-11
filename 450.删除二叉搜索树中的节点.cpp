/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr)
            return nullptr;
        if(root->val == key){
            if(root->left == nullptr)
                return root->right;
            if(root->right == nullptr)
                return root->left;
            TreeNode* min_node = get_min(root->right);
            root->right = deleteNode(root->right, min_node->val);
            min_node->left = root->left;
            min_node->right = root->right;
            root = min_node;
        }
        else if(root->val < key)
            root->right = deleteNode(root->right, key);
        else if(root->val > key)
            root->left = deleteNode(root->left, key);
        return root;
    }
    TreeNode* get_min(TreeNode* root){
        if(root->left)
            return get_min(root->left);
        return root;
    }
};
// @lc code=end

