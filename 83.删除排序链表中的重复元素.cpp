/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
 */

// @lc code=start


// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr)
            return nullptr;
        ListNode* fast = head, *slow = head;
        while(fast != nullptr){
            if(fast ->val != slow->val){
                slow->next = fast;
                slow = fast;
            }
            fast = fast->next;
        }
        slow->next = nullptr;
        return head;
    }
};
// @lc code=end

