/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
    ListNode* successor;
    ListNode* reverseN(ListNode* head, int N){
        if(N == 1){
            successor = head->next;
            return head;
        }
        ListNode* ret = reverseN(head->next, N - 1);
        head->next->next = head;
        head->next = successor;
        return ret;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy_head = new ListNode(0, head), *prev = dummy_head;
        int len = right - left;
        while(--left)
            prev = prev->next;
        ListNode* cur = prev->next;
        prev->next = reverseN(cur, len + 1);
        return dummy_head->next;
    }

    // ListNode* reverseBetween(ListNode* head, int left, int right) {
    //     ListNode* dummy_head = new ListNode(0, head), *prev = dummy_head;
    //     int len = right - left;
    //     while(--left)
    //         prev = prev->next;
    //     ListNode* cur = prev->next;
    //     while(len--){
    //         ListNode* next = cur->next;
    //         cur->next = next->next;
    //         next->next = prev->next;
    //         prev->next = next;
    //     }
    //     return dummy_head->next;
    // }
};
// @lc code=end

