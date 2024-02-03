/*
 * @lc app=leetcode.cn id=1372 lang=cpp
 *
 * [1372] 二叉树中的最长交错路径
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
    void dp(TreeNode* node) {
        l.clear();
        r.clear();
        q.push({node, nullptr});
        while (!q.empty()) {
            auto* cur = q.front().first;
            auto* parent = q.front().second;
            l[cur] = r[cur] = 0;
            if (parent) {
                if (cur == parent->left) l[cur] = r[parent] + 1;
                if (cur == parent->right) r[cur] = l[parent] + 1;
            }

            q.pop();
            if (cur->left) q.push({cur->left, cur});
            if (cur->right) q.push({cur->right, cur});
        }
    }

    int longestZigZag(TreeNode* root) {
        dp(root);
        int ans = 0;
        for (auto& kv : l)
            ans = max(ans, kv.second);
        for (auto& kv : r)
            ans = max(ans, kv.second);
        return ans;
    }

    protected:
        //l : 从root开始到node，且node是他parent左子树的最大交错路径
        //r : 从root开始到node，且node是他parent右子树的最大交错路径
        unordered_map<TreeNode*, int> l, r;
        //<node, parent node>
        queue<pair<TreeNode*, TreeNode*>> q;
};
// @lc code=end

