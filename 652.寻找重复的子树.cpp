/*
 * @lc app=leetcode.cn id=652 lang=cpp
 *
 * [652] 寻找重复的子树
 */

// @lc code=start
#include <vector>
#include <unordered_map>
#include <string>
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
    unordered_map<string, int> map;
    vector<TreeNode*> res;
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        traverse(root);
        return res;
    }

    string traverse(TreeNode* root){
        if(root == nullptr)
            return "#";
        string left = traverse(root->left);
        string right = traverse(root->right);
        string sub_tree = left + "," + to_string(root->val) + "," + right + ",";
        if(map.find(sub_tree) != map.end() && map[sub_tree] == 1){
            res.push_back(root);
            map[sub_tree]++;
        }
        else
            map.insert({sub_tree, 1});
        return sub_tree;
    }

};
// @lc code=end

