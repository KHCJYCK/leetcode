/*
 * @lc app=leetcode.cn id=1109 lang=cpp
 *
 * [1109] 航班预订统计
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
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ret(n, 0);
        Difference df(ret);
        for(auto booking : bookings){
            df.update(booking[0] - 1, booking[1] - 1, booking[2]);
        }
        return df.result();
    }
};
// @lc code=end

