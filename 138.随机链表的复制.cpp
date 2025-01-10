/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 随机链表的复制
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node dummy(0);
        unordered_map<Node*, Node*> dict;
        Node *old = head, *newone = &dummy;
        while (old) {
            auto* cur = new Node(old->val);
            dict.emplace(old, cur);
            newone = newone->next = cur;
            old = old->next;
        }
        while (head) {
            auto* ra = head->random;
            if (ra) {
                dict[head]->random = dict[ra];
            }
            head = head->next;
        }
        return dummy.next;
    }
};
// @lc code=end

