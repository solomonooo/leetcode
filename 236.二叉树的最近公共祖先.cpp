/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    //基于一个原理，如果一个节点的满足条件，那么有2种情况
    //      1. 左子树有p或q，右子树有q或者p，pq必然不能在同一棵子树
    //      2. 当前节点就是p或者q，左子树或者右子树其中有一个有q或者p
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& ans) {
        if (root == nullptr) return false;
        if (ans) return true;   //快速剪枝
        bool lson = dfs(root->left, p, q, ans);
        bool rson = dfs(root->right, p, q, ans);
        if (ans) return true;   //快速剪枝
        bool is_cur_matched = root->val == p->val || root->val == q->val;
        //lson && rson为true，代表左右子树都发现了p或者q，显然当前node是目标node
        if ((lson && rson) || (is_cur_matched && (lson || rson)))
            ans = root;
        return lson || rson || is_cur_matched;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = nullptr;
        dfs(root, p, q, ans);
        return ans;
    }
};
// @lc code=end

