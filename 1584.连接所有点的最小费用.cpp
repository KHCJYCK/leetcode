/*
 * @lc app=leetcode.cn id=1584 lang=cpp
 *
 * [1584] 连接所有点的最小费用
 */

// @lc code=start
#include <vector>
using namespace std;
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
class Solution {
public:
    struct edge{
        int i;
        int j;
        int weight;
    };
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<edge> graph;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int x1 = points[i][0], x2 = points[j][0];
                int y1 = points[i][1], y2 = points[j][1];
                graph.push_back({i, j, abs(x1 - x2) + abs(y1 - y2)});
            }
        }
        sort(graph.begin(),graph.end(), [](edge lhs, edge rhs){
            return lhs.weight < rhs.weight;
        });
        int mst = 0;
        UF uf(n);
        for(auto edge : graph){
            int u = edge.i, v = edge.j;
            if(uf.is_connected(u, v))
                continue;
            mst += edge.weight;
            uf.connect(u, v);
        }
        return mst;
    }
};
// @lc code=end

