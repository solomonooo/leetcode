/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
   //核心的算法是，最大路径有2种可能：
    //经过当前节点，path=left_height+right_height;
    //不经过当前节点，check left path and right path
    int depth(TreeNode* root, int& maxn) {
        if (root == nullptr) return 0;
        int left = depth(root->left, maxn);
        int right = depth(root->right, maxn);
        maxn = max(maxn, left+right);
        return max(left, right)+1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxn = 0;
        depth(root, maxn);
        return maxn;
    }
};
// @lc code=end

