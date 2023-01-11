/*
 * @lc app=leetcode.cn id=990 lang=cpp
 *
 * [990] 等式方程的可满足性
 */

// @lc code=start
#include <vector>
#include <string>
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
    bool equationsPossible(vector<string>& equations) {
        UF uf(26);
        for(auto equation : equations){
            if(equation[1] == '=')
                uf.connect(equation[0] - 'a', equation[3] - 'a');
        }
        for(auto equation : equations){
            if(equation[1] == '!'){
                if(uf.is_connected(equation[0] - 'a', equation[3] - 'a'))
                    return false;
            }               
        }
        return true;
    }
};
// @lc code=end

