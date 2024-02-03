/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    //我们用指针来缓存找到的位置即可
    //注意，我们找到的第一个交换位置是，i > j, 选择i位置
    //第二个位置要选择小的那个，i > j, 选择j位置
    //比如，3,2,1 显然先找到3位置，然后找到1位置，才能交换，如果选择2位置则是错误的
    void recoverTree(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode *prev = nullptr, *cur = root, *m = nullptr, *n = nullptr;
        while (!s.empty() || cur) {
            while (cur) {
                s.push(cur);
                cur = cur->left;
            }
            cur = s.top();
            s.pop();
            if (prev && prev->val > cur->val) {
                if (m) {
                    n = cur;
                    break;
                }else{
                    m = prev;
                    n = cur;
                }
            }
            prev = cur;
            cur = cur->right;
        }
        swap(m->val, n->val);
    }
};
// @lc code=end

