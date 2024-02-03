/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if (root) q.push(root);
        bool direction_flag = true;
        while (!q.empty()) {
            vector<int> cur(q.size());
            int n = q.size();
            for (int i = 0; i < n; i++) {
                if (direction_flag) {
                    cur[i] = q.front()->val;
                }else{
                    cur[n-i-1] = q.front()->val;
                }
                if (q.front()->left) q.push(q.front()->left);
                if (q.front()->right) q.push(q.front()->right);
                q.pop();
            }
            direction_flag = !direction_flag;
            res.push_back(move(cur));
        }
        return res;
    }
};
// @lc code=end

