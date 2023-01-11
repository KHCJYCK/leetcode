/*
 * @lc app=leetcode.cn id=797 lang=cpp
 *
 * [797] 所有可能的路径
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        traverse(graph, 0, path);
        return res;
    }
    void traverse(vector<vector<int>>& graph, int n, vector<int>& path){
        path.push_back(n);
        if(n == graph.size() - 1){
            res.push_back(path);
            path.pop_back();
            return;
        }
        for(auto num : graph[n]){
            traverse(graph, num, path);
        }
        path.pop_back();
    }
};
// @lc code=end

