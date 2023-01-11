/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
#include <queue>
using namespace std;
class Solution {
public:
    int minDepth(TreeNode* root) {
        return BFS(root);
    }   
    int BFS(TreeNode* root){
        if(root == nullptr)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        int depth = 1;
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                TreeNode* node = q.front();
                if(node->left == nullptr && node->right == nullptr)
                    return depth;
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
                q.pop();
            }
            depth++;
        }
        return depth;
    }
};
// @lc code=end

