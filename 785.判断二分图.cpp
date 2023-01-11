/*
 * @lc app=leetcode.cn id=785 lang=cpp
 *
 * [785] 判断二分图
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> visited;
    vector<bool> color;
    bool is_bipartite = true;
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        visited.resize(n, false);
        color.resize(n, false);
        for(int i = 0; i < n; i++){
            if(visited[i] == false)
                traverse(graph, i);
        }
        return is_bipartite;
    }
    void traverse(vector<vector<int>>& graph, int n){
        if(is_bipartite == false)
            return;
        visited[n] = true;
        for(auto item : graph[n]){
            if(!visited[item]){
                color[item] = !color[n];
                traverse(graph, item);
            }
            else{
                if(color[item] == color[n]){
                    is_bipartite = false;
                    return;
                }
            }
        }
    }
};
// @lc code=end

