/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        auto* node = root;
        TreeNode* prev = nullptr;
        while(s.size() > 0 || node){
            if (node) {
                s.push(node);
                node = node->left;
            }else{
                if (!s.top()->right || prev == s.top()->right) {
                    res.push_back(s.top()->val);
                    prev = s.top();
                    s.pop();
                }else{
                    node = s.top()->right;
                }
                /*
                node = s.top();
                s.pop();
                if (!node->right || prev == node->right) {
                    res.push_back(node->val);
                    prev = node;
                    node = nullptr;
                }else{
                    s.push(node);
                    node = node->right;
                }
                */
            }
        }
        return res;
    }
};
// @lc code=end

