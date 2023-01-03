/*
 * @lc app=leetcode.cn id=889 lang=cpp
 *
 * [889] 根据前序和后序遍历构造二叉树
 */

// @lc code=start
#include <vector>
#include <unordered_map>
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
private:
    unordered_map<int, int> val2index;
public:
    TreeNode* build(vector<int>& preorder, int pre_left, int pre_right, vector<int>& postorder, int pos_left, int pos_right){
        if(pre_left > pre_right)
            return nullptr;
        if(pre_left == pre_right)
            return new TreeNode(preorder[pre_left]);
        int val = preorder[pre_left];
        int left_val = preorder[pre_left + 1];
        int index = val2index[left_val];
        int left_size = index - pos_left + 1;
        int right_size = pos_right  - index - 1;
        TreeNode* root = new TreeNode(val);
        root->left = build(preorder, pre_left + 1, pre_left + left_size, postorder, pos_left, index);
        root->right = build(preorder, pre_left + left_size + 1, pre_right, postorder, index + 1, pos_right - 1);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        for(int i = 0; i < postorder.size(); i++){
            val2index.insert({postorder[i], i});
        }
        return build(preorder, 0, preorder.size() - 1, postorder, 0, postorder.size() - 1);        
    }
};
// @lc code=end

