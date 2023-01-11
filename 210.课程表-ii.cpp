/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> res;
    vector<bool> visited;
    vector<bool> path;
    bool has_cycle = false;
    vector<vector<int>> build_graph(int numCourses, vector<vector<int>>& prerequisites){
        vector<vector<int>> graph(numCourses);
        for(auto item : prerequisites){
            int pre = item[1], next = item[0];
            graph[pre].push_back(next);
        }
        return graph;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        visited.resize(numCourses);
        path.resize(numCourses);
        vector<vector<int>> graph = build_graph(numCourses, prerequisites);
        for(int i = 0; i < graph.size(); i++){
            traverse(graph, i);
        }
        if(has_cycle)
            return {};
        reverse(res.begin(), res.end());
        return res;
    }
    void traverse(vector<vector<int>>& graph, int n){
        if(path[n])
            has_cycle = true;
        if(visited[n] || has_cycle)
            return;
        visited[n] = true;
        path[n] = true;
        for(auto item : graph[n]){
            traverse(graph, item);
        }
        res.push_back(n);
        path[n] = false;
    }
};
// @lc code=end

