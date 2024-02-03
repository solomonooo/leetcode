/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr, *cur = nullptr;
        int extra = 0;
        while (l1 != nullptr || l2 != nullptr || extra > 0) {
            int a = l1 ? l1->val : 0;
            int b = l2 ? l2->val : 0;
            int tmp = a + b + extra;
            if (!head) {
                head = cur = new ListNode(tmp % 10);
            }else{
                cur = cur->next = new ListNode(tmp % 10);
            }
            extra = tmp / 10;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        return head;
    }
};
// @lc code=end

