/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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
    int dfs(TreeNode* root, int& maxn) {
        if (root == nullptr) return 0;
        int left_max = dfs(root->left, maxn);
        int right_max = dfs(root->right, maxn);
        int cur = root->val;
        maxn = max(maxn, cur + (left_max > 0 ? left_max : 0) + (right_max > 0 ? right_max : 0));
        return cur + max(left_max > 0 ? left_max : 0, right_max > 0 ? right_max : 0);
    }

    int maxPathSum(TreeNode* root) {
        int maxn = root ? root->val : 0;
        dfs(root, maxn);
        return maxn;
    }
};
// @lc code=end

