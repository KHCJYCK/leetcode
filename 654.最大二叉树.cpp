/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
    pair<int, int> get_element_index(vector<int>& nums, int left, int right){
        int index = left;
        int max_element = nums[left];
        for(int i = left + 1; i <= right; i++){
            if(nums[i] > max_element){
                index = i;
                max_element = nums[i];
            }
        }
        return {index, max_element};
    }
    TreeNode* construct(vector<int>& nums, int left, int right){
        if(left > right)
            return nullptr;
        auto element = get_element_index(nums, left, right);
        TreeNode* root = new TreeNode(element.second);
        root->left = construct(nums, left, element.first - 1);
        root->right = construct(nums, element.first + 1, right);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return construct(nums, 0, nums.size() - 1);
    }
};
// @lc code=end

