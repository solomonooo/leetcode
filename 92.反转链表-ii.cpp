/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m == n) return head;
        ListNode dummy(0, head);
        auto* mptr = &dummy;    //指向m前一个node
        for(int i = 1; i < m; i++){
            mptr = mptr->next;
        }
        auto* nptr = mptr->next; //指向left也就是m的位置
        for(int i = m; i< n; i++){  //每次遍历nptr都在移动
            auto* tmp = nptr->next;
            nptr->next = tmp->next;
            tmp->next = mptr->next;
            mptr->next = tmp;
        }
        return dummy.next;
    }
};
// @lc code=end

