/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
 */

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };


class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy_head1 = new ListNode();
        ListNode* dummy_head2 = new ListNode();
        ListNode* p1 = dummy_head1, *p2 = dummy_head2;
        while(head){
            if(head->val < x){
                p1->next = head;
                p1 = p1->next;
            }
            else{
                p2->next = head;
                p2 = p2->next;
            }
            head = head->next;
        }
        p1->next = nullptr;
        p2->next = nullptr;
        p1->next = dummy_head2->next;
        return dummy_head1->next;
    }
};
// @lc code=end

