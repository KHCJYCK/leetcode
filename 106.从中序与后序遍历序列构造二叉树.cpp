/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode* build(vector<int>& postorder, int p_left, int p_right, vector<int>& inorder, int i_left, int i_right) {
        if(p_left > p_right)
            return nullptr;
        TreeNode* root = new TreeNode(postorder[p_right]);
        int index = i_left;
        for(int i = i_left; i <= i_right; i++){
            if(inorder[i] == postorder[p_right]){
                index = i;
                break;
            }
        }
        int l_size = index - i_left;
        int r_size = i_right - index;
        root->left = build(postorder, p_left, p_left + l_size - 1, inorder, i_left, index - 1);
        root->right = build(postorder, p_left + l_size, p_right - 1, inorder, index + 1, i_right);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};
// @lc code=end

