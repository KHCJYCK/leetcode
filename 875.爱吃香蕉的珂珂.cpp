/*
 * @lc app=leetcode.cn id=875 lang=cpp
 *
 * [875] 爱吃香蕉的珂珂
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    long long f(vector<int>& piles, int x) {
        long long hours = 0;
        for (int i = 0; i < piles.size(); i++) {
            hours += piles[i] / x;
            if (piles[i] % x > 0) {
                hours++;
            }
        }
        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = 1000000000;

        while(left <= right){
            int mid = left + (right - left) / 2;
            if(f(piles, mid) > h)
                left = mid + 1;
            else{
                right = mid - 1; 
            }
        }
        return left;
    }
};
// @lc code=end

