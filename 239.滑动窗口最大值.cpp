/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
#include <vector>
#include <queue>
#include <list>
#include <deque>
using namespace std;

class Solution {
public:
    class MonotonicQueue{
    private:
        deque<int> q;
    public:
        MonotonicQueue(){}
        void push_back(int value){
            while(!q.empty() && q.back() < value)
                q.pop_back();
            q.push_back(value);
        }
        void pop_front(int value){
            if(q.front() == value)
                q.pop_front();
        }
        int max_element(){
            return q.front();
        }
    };
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MonotonicQueue q;
        int len = nums.size();
        vector<int> res;
        for(int i = 0; i < len; i++){
            if(i < k){
                q.push_back(nums[i]);
                continue;
            }
            res.push_back(q.max_element());
            q.push_back(nums[i]);
            q.pop_front(nums[i - k]);
        }
        res.push_back(q.max_element());
        return res;       
    }
};
// @lc code=end

