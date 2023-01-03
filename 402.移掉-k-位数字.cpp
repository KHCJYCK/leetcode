/*
 * @lc app=leetcode.cn id=402 lang=cpp
 *
 * [402] 移掉 K 位数字
 */

// @lc code=start
#include <vector>
#include <deque>
#include <string>
using namespace std;

class Solution
{
public:
    class MonotonicQueue
    {
    private:
        deque<char> q;  
    public:
        int max_pop;
        MonotonicQueue(int k) : max_pop(k){}
        void push_back(int value)
        {
            while (!q.empty() && q.back() > value && max_pop > 0){
                q.pop_back();
                max_pop--;
            }
            q.push_back(value);
        }
        void pop_front(int value)
        {
            q.pop_front();
        }
        string res(void){
            string ret;
            while(max_pop--)
                q.pop_back();
            while(!q.empty() && q.front() == '0')
                q.pop_front();
            for(auto iter = q.begin(); iter != q.end(); iter++){
                ret += *iter;
            }
            return (ret.size() == 0) ? "0" : ret;
        }
    };
    string removeKdigits(string num, int k)
    {
        MonotonicQueue q(k);
        for (int i = 0; i < num.size(); i++){
            q.push_back(num[i]);
        }
        return q.res();
    }
};
// @lc code=end
