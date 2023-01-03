/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start


// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };

class Solution {
public:
    // ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    //     int len1 = 0, len2 = 0;
    //     ListNode* p1 = headA, *p2 = headB;
    //     while(p1){
    //         len1++;
    //         p1 = p1->next;
    //     }
    //     while(p2){
    //         len2++;
    //         p2 = p2->next;
    //     }
    //     p1 = headA;
    //     p2 = headB;
    //     if(len1 > len2){
    //         int len = len1 - len2;
    //         while(len--){
    //             p1 = p1->next;
    //         }
    //     }
    //     else{
    //         int len = len2 - len1;
    //         while(len--){
    //             p2 = p2->next;
    //         }
    //     }
    //     while(p1 ||p2){
    //         if(p1 == p2)
    //             return p1;
    //         p1 = p1->next;
    //         p2 = p2->next;
    //     }
    //     return nullptr;
    // }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p1 = headA, *p2 = headB;
        while(p1 != p2){
            p1 = p1 ? p1->next : headB;
            p2 = p2 ? p2->next : headA;
        }
        return p1;
    }
};
// @lc code=end

