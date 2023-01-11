/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
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
    int k, rank, res;
    int kthSmallest(TreeNode* root, int k) {
        this->k = k;
        this->rank = 0;
        traverse(root);
        return res;
    }
    void traverse(TreeNode* root){
        if(root == nullptr)
            return;
        traverse(root->left);
        rank++;
        if(rank == k){
            res = root->val;
            return;
        }
        traverse(root->right);
        return;
    }
};
// @lc code=end

