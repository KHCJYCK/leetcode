/*
 * @lc app=leetcode.cn id=1094 lang=cpp
 *
 * [1094] 拼车
 */

#include <vector>
using namespace std;


// @lc code=start
class Difference{
private:
    vector<int> diff;
public:
    Difference(vector<int>& nums){
        int len = nums.size();
        diff.resize(len);
        diff[0] = nums[0];
        for(int i = 1; i < len; i++){
            diff[i] = nums[i] - nums[i - 1];
        }
    }
    void update(int left, int right, int val){
        diff[left] += val;
        if(right + 1 < diff.size())
            diff[right + 1] -= val;
    }

    vector<int> result(){
        vector<int> res(diff.size());
        res[0] = diff[0];
        for(int i = 1; i < diff.size(); i++){
            res[i] = res[i - 1] + diff[i];
        }
        return res;
    }
};
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> ret(1001, 0);
        Difference df(ret);
        for(auto trip : trips){
            df.update(trip[1], trip[2] - 1, trip[0]);
        }
        vector<int> res = df.result();
        for(auto num : res){
            if (num > capacity)
                return false;
        }
        return true;
    }
};
// @lc code=end

