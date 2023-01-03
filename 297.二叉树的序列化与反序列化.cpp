/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Codec {
public:
    vector<string> nodes;
    string res;
    const char SEP = ',';
    const char NUL = '#';
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        traverse(root);
        return res;
    }
    void traverse(TreeNode* root){
        if(root == nullptr){
            res += NUL;
            res += SEP;
            return;
        }
        int val = root->val;
        res += to_string(val);
        res += SEP;
        traverse(root->left);
        traverse(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        string str = "";
        for(int i = 0; i < data.size(); i++){
            if(isdigit(data[i]) || data[i] == NUL || data[i] == '-'){
                str += data[i];
            }
            else if(data[i] == SEP){
                nodes.push_back(str);
                str = "";
            }
        }
        int index = 0;
        return build(index);
    }
    TreeNode* build(int& index){
        if(index == nodes.size())
            return nullptr;
        if(nodes[index] == "#")
            return nullptr;
        int val = atoi(nodes[index].c_str());
        TreeNode* root = new TreeNode(val);
        root->left = build(++index);
        root->right = build(++index);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

