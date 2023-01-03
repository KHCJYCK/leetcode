/*
 * @lc app=leetcode.cn id=870 lang=cpp
 *
 * [870] 优势洗牌
 */

// @lc code=start
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int len = nums2.size();
        vector<int> res(len);
        sort(nums1.begin(), nums1.end());
        auto fun = [](pair<int, int>& lhs, pair<int, int>& rhs){
            return lhs.first < rhs.first;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(fun)>q(fun);
        for(int i = 0; i < nums2.size(); i++){
            q.push({nums2[i], i});
        }
        int left = 0, right = len - 1;
        while(right >= left){
            int val = q.top().first;
            int index = q.top().second;
            if(nums1[right] > val){
                res[index] = nums1[right--];
            }
            else{
                res[index] = nums1[left++];
            }
            q.pop();
        }
        return res;
    }
};
// @lc code=end

