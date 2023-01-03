/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
 */

// @lc code=start
#include <queue>
#include <vector>
using namespace std;


// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };



class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy_head = new ListNode(), *p = dummy_head;
        auto my_cmp = [](ListNode* lhs, ListNode* rhs){
            return lhs->val > rhs->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(my_cmp)>q(my_cmp);
        for(auto list : lists){
            if(list){
                q.emplace(list);
            }
        }
        while(!q.empty()){
            ListNode* ptop = q.top();
            p->next = ptop;
            q.pop();
            if(ptop->next){
                q.emplace(ptop->next);
            }
            p = p->next;
        }
        p->next = nullptr;
        return dummy_head->next;
    }
};
// @lc code=end

