/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode dummy(0, head);
        auto* new_head = dummy.next;
        if (new_head) {
            auto* cur = new_head->next;
            new_head->next = nullptr;

            while (cur) {
                auto* next = cur->next;
                cur->next = new_head;
                new_head = cur;
                cur = next;
            }
        }
        dummy.next = new_head;
        return dummy.next;
    }
};
// @lc code=end

