/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并 K 个升序链表
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
    struct Greater
    {
        bool operator()(const ListNode* p1, const ListNode* p2) {
            return p1->val > p2->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy;
        ListNode* cur = &dummy;
        priority_queue<ListNode*, vector<ListNode*>, Greater> pq;
        for (auto& v : lists) {
            if (v) pq.push(v);
        } 
        while (!pq.empty()) {
            ListNode* tmp = pq.top();
            pq.pop();
            cur = cur->next = tmp;
            if (tmp->next) pq.push(tmp->next);
        }
        return dummy.next;
    }
};
// @lc code=end

