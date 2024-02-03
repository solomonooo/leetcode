/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    //找到倒数nth不难
    //需要注意的是，要删除这个node，需要找到nth前面那个node
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* p = head;
        ListNode* prev = &dummy;
        int cur = 0;
        while(p){
            if(cur >= n){
                prev = prev->next;
            }
            p = p->next;
            cur++;
        }
        if(prev->next)
            prev->next = prev->next->next;
        return dummy.next;
    }
};
// @lc code=end

