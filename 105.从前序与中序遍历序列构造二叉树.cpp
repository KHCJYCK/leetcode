/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode* build(vector<int>& preorder, int p_left, int p_right, vector<int>& inorder, int i_left, int i_right) {
        if(p_left > p_right)
            return nullptr;
        TreeNode* root = new TreeNode(preorder[p_left]);
        int index = i_left;
        for(int i = i_left; i <= i_right; i++){
            if(inorder[i] == preorder[p_left]){
                index = i;
                break;
            }
        }
        int l_size = index - i_left;
        int r_size = i_right - index;
        root->left = build(preorder, p_left + 1, p_left + l_size, inorder, i_left, index - 1);
        root->right = build(preorder, p_left + l_size + 1, p_right, inorder, index + 1, i_right);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};
// @lc code=end

