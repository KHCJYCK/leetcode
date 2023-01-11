#include <vector>
#include <queue>
#include <algorithm>
#include <cstdint>
#include <algorithm>
#include <unordered_map>
#include <numeric>
#include <functional>
using namespace std;

vector<string> nodes;
string res;
const char SEP = ',';
const char NUL = '#';
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 根据数组构造二叉树
TreeNode* construct_binary_tree(const vector<int>& vec) {
    vector<TreeNode*> vecTree (vec.size(), NULL);
    TreeNode* root = NULL;
    for (int i = 0; i < vec.size(); i++) {
        TreeNode* node = NULL;
        if (vec[i] != -1) node = new TreeNode(vec[i]); // 用 -1 表示null
        vecTree[i] = node;
        if (i == 0) root = node;
    }    
    for (int i = 0; i * 2 + 1 < vec.size(); i++) {
        if (vecTree[i] != NULL) {
            // 线性存储转连式存储关键逻辑
            vecTree[i]->left = vecTree[i * 2 + 1];
            if(i * 2 + 2 < vec.size())
            vecTree[i]->right = vecTree[i * 2 + 2];
        }
    }
    return root;
}
class UF{
public:
    vector<int> parents;
    int count;
    UF(int n){
        count = n;
        parents.resize(n);
        for(int i = 0; i < n; i++)
            parents[i] = i;
    }
    void connect(int p, int q){
        int rootp = find(p);
        int rootq = find(q);
        if(rootp == rootq)
            return;
        parents[rootp] = rootq;
        count--;
    }
    int find(int p){
        if(parents[p] != p)
            parents[p] = find(parents[p]);
        return parents[p];
    }
    bool is_connected(int p, int q){
        int rootp = find(p);
        int rootq = find(q);
        return rootp == rootq;
    }
    int get_count(){
        return count;
    }
};



int main(){
    vector<vector<int>> points{{0,0},{2,2},{3,10},{5,2},{7,0}};
    sort(points.begin(), points.end(),[](auto lhs, auto rhs){
        return lhs[1] < rhs[1];
    });
    return 0;
}