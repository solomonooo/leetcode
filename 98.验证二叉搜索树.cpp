/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    bool isValidBST(TreeNode* node, int64_t minn, int64_t maxn) {
        if (node->val <= minn || node->val >= maxn) 
            return false;
        if (node->left && !isValidBST(node->left, minn, node->val)) {
            return false;
        }
        if (node->right && !isValidBST(node->right, node->val, maxn)) {
            return false;
        }
        return true;
    }

    bool isValidBST2(TreeNode* root) {
        if (!root) return true;
        return isValidBST(root, LLONG_MIN, LLONG_MAX);
    }

    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> s;
        int64_t prev = (int64_t)INT_MIN-1;
        auto* p = root;
        while (!s.empty() || p) {
            while (p) {
                s.push(p);
                p = p->left;
            }
            p = s.top();
            if (p->val <= prev) return false;
            prev = p->val;
            p = p->right;
            s.pop();
        }
        return true;
    }
};
// @lc code=end

