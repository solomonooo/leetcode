/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) return head;
        ListNode dummy(0, head);
        for (ListNode *p1 = &dummy, *p2 = &dummy; p2 !=nullptr; p2 = p1) {
            for (int i = 0; i < k && p2; i++) {
                p2 = p2->next;
            }
            if (!p2) break; //find the end
            auto *cur1 = p1->next, *cur2 = p1->next->next;
            cur1->next = p2->next;
            p1->next = p2;
            p1 = cur1;
            while (cur1 != p2) {
                auto* tmp = cur2;
                cur2 = cur2->next;
                tmp->next = cur1;
                cur1 = tmp;   
            }

        }
        return dummy.next;
    }
};
// @lc code=end

