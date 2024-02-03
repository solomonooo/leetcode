/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
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
    vector<TreeNode *> generateTree(int from, int to)
    {
        vector<TreeNode *> ret;
        if(to - from < 0) 
            ret.push_back(0);
        else if(to - from == 0) 
            ret.push_back(new TreeNode(from));
        else {
            for(int i=from; i<=to; i++)
            {
                auto l = generateTree(from, i-1);
                auto r = generateTree(i+1, to);

                for(int j=0; j<l.size(); j++)
                {
                    for(int k=0; k<r.size(); k++)
                    {
                        TreeNode * h = new TreeNode (i);
                        h->left = l[j];
                        h->right = r[k];
                        ret.push_back(h);
                    }
                }
            }
        }
        return ret;
    }

    //核心思想是：选择root节点，然后拆分两边去生成子树
    //需要理解题意，二叉搜索树，意味着二叉树是有序的
    vector<TreeNode *> generateTrees(int n) {
        if(n == 0){
            return vector<TreeNode *>();
        }
        return generateTree(1, n);
    }
};
// @lc code=end

