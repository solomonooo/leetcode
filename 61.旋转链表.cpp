/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        int n = 1;
        auto* cur = head;
        while(cur->next) {
            cur = cur->next;
            n++;
        }
        int add = n-k%n;
        if (add == n) return head;
        cur->next = head;
        while(add > 0) {
            cur = cur->next;
            add--;
        }
        auto* ret = cur->next;
        cur->next = nullptr;
        return ret;
    }
};
// @lc code=end

