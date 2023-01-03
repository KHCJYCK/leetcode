/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    // ListNode* reverseList(ListNode* head) {
    //     ListNode* prev = nullptr, *cur = head;
    //     while(cur != nullptr){
    //         ListNode* front = cur->next;
    //         cur->next = prev;
    //         prev = cur;
    //         cur = front;
    //     }
    //     return prev;
    // }
    ListNode* reverseList(ListNode* head) {
        ListNode* dummy_head = new ListNode(0, head), *cur = head;
        while(cur && cur->next){
            ListNode* next = cur->next;
            cur->next = next->next;
            next->next = dummy_head->next;
            dummy_head->next = next;
        }
        return dummy_head->next;
    }
    // ListNode* reverseList(ListNode* head) {
    //     if(head== nullptr || head->next == nullptr)
    //         return head;
    //     ListNode* last = reverseList(head->next);
    //     head->next->next = head;
    //     head->next = nullptr;
    //     return last;
    // }
};
// @lc code=end

