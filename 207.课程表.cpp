/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    bool has_cycle = false;
    vector<bool> is_visited;
    vector<bool> on_path;
    vector<vector<int>> build_graph(int numCourses, vector<vector<int>>& prerequisites){
        vector<vector<int>> graph(numCourses);
        for(auto item : prerequisites){
            int pre = item[1], next = item[0];
            graph[pre].push_back(next);
        }
        return graph;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph = build_graph(numCourses,prerequisites);
        is_visited.resize(numCourses, false);
        on_path.resize(numCourses, false);
        for(int i = 0; i < graph.size(); i++){
            traverse(graph, i);
        }
        return !has_cycle;
    }
    void traverse(vector<vector<int>>& graph, int n){
        if(on_path[n])
            has_cycle = true;
        if(is_visited[n] || has_cycle)
            return;
        is_visited[n] = true;
        on_path[n] = true;
        for(auto num : graph[n])
            traverse(graph, num);
        on_path[n] = false;
        return;
    }
};
// @lc code=end

