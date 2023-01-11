/*
 * @lc app=leetcode.cn id=886 lang=cpp
 *
 * [886] 可能的二分法
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    vector<bool> visited;
    vector<bool> color;
    bool is_bipartite = true;
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
    vector<vector<int>> build_graph(int n, vector<vector<int>>& dislikes){
        vector<vector<int>> graph(n);
        for(auto dislike : dislikes){
            auto lhs = dislike[0], rhs = dislike[1];
            graph[lhs - 1].push_back(rhs - 1);
            graph[rhs - 1].push_back(lhs - 1);
        }
        return graph;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph = build_graph(n, dislikes);
        visited.resize(n, false);
        color.resize(n, false);
        for(int i = 0; i < n; i++){
            if(visited[i] == false)
                traverse(graph, i);
        }
        return is_bipartite;
    }
};
// @lc code=end

