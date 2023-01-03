/*
 * @lc app=leetcode.cn id=1011 lang=cpp
 *
 * [1011] 在 D 天内送达包裹的能力
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int f(vector<int>& weights, int weight){
        int day = 0, sum = 0;
        for(int i = 0; i < weights.size(); i++){
            if(sum + weights[i] > weight){
                sum = 0;
                day++;
            }
            sum += weights[i];
        }
        return sum == 0 ? day : day + 1;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int left = INT_MIN, right = 0;
        for(auto weight : weights){
            left = max(left, weight);
            right += weight;
        }
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(f(weights, mid) > days)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }
};
// @lc code=end

