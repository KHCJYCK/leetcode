/*
 * @lc app=leetcode.cn id=1373 lang=cpp
 *
 * [1373] 二叉搜索子树的最大键值和
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
    int max_sum = 0;
    int maxSumBST(TreeNode* root) {
        traverse(root);
        return max_sum;
    }
    //是不是BST，当前树max，当前树min，sum
    vector<int> traverse(TreeNode* root){
        if(root == nullptr)
            return {1, INT_MIN, INT_MAX, 0};
        vector<int> res(4,0);
        vector<int> left = traverse(root->left);
        vector<int> right = traverse(root->right);
        if(left[0] == 1 && right[0] == 1 && 
            root->val > left[1] && root->val < right[2]){
            res[0] = 1;
            res[1] = max(right[1], root->val);
            res[2] = min(left[2], root->val);
            res[3] = root->val + left[3] + right[3];
            max_sum = max(max_sum, res[3]);
        }
        return res;
    }
};
// @lc code=end

