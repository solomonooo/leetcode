/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& preorder, int pre_left, int pre_right, 
                        vector<int>& inorder, int in_left, int in_right, 
                        unordered_map<int, int>& index) {
        if (pre_left > pre_right) {
            return nullptr;
        }
        //前序第一个节点就是当前node
        //利用中序来确定左右子树的大小x
        int in_cur = index[preorder[pre_left]];
        int left_cnt = in_cur - in_left;
        auto* cur = new TreeNode(preorder[pre_left]);
        cur->left = buildTree(preorder, pre_left+1, pre_left+left_cnt, inorder, in_left, in_cur-1, index);
        cur->right = buildTree(preorder, pre_left+1+left_cnt, pre_right, inorder, in_cur+1, in_right, index);
        return cur;
    }

    TreeNode* buildTree2(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        unordered_map<int, int> index;
        //用中序数组构造hash map,为了快速定位
        for (int i = 0; i < n; i++) {
            index[inorder[i]] = i;
        }
        return buildTree(preorder, 0, n-1, inorder, 0, n-1, index);
    }

    //迭代法
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (!preorder.size()) {
            return nullptr;
        }
        auto* root = new TreeNode(preorder[0]);
        stack<TreeNode*> stk;
        stk.push(root);
        int in_idx = 0;
        for (int i = 1; i < preorder.size(); i++) {
            int pre_val = preorder[i];
            auto* node = stk.top();
            if (node->val != inorder[in_idx]) {
                node->left = new TreeNode(pre_val);
                stk.push(node->left);
            }else{
                while(!stk.empty() && stk.top()->val == inorder[in_idx]) {
                    node = stk.top();
                    stk.pop();
                    in_idx++;
                }
                node->right = new TreeNode(pre_val);
                stk.push(node->right);
            }
        }
        return root;
    }
};
// @lc code=end

