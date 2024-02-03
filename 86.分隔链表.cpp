/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
    ListNode* partition(ListNode* head, int x) {
        ListNode dummy1, dummy2;
        auto *node1 = &dummy1, *node2 = &dummy2, *cur = head;
        while (cur) {
            if (cur->val < x) {
                node1 = node1->next = cur;
            }else{
                node2 = node2->next = cur;
            }
            cur = cur->next;
        }
        node1->next = dummy2.next;
        node2->next = nullptr;
        return dummy1.next;
    }
};
// @lc code=end

