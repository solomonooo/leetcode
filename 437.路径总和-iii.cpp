/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
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
    int dfs(TreeNode* root, long long cur, int target, unordered_map<long long, int>& prefix) {
        if (root == nullptr) return 0;
        int ret = 0;
        cur += root->val;
        auto it = prefix.find(cur-target);
        if (it != prefix.end()) {
            ret = it->second;
        }
        prefix[cur]++;
        ret += dfs(root->left, cur, target, prefix);
        ret += dfs(root->right, cur, target, prefix);
        prefix[cur]--;
        return ret;
    }

    int pathSum(TreeNode* root, int targetSum) {
        //prefix保存的是从root到当前节点的所有路径和（前缀和）
        unordered_map<long long, int> prefix;
        prefix[0] = 1;  //很有必要，代表空路径
        return dfs(root, 0, targetSum, prefix);
    }

/*
    int rootSum(TreeNode* root, int target) {
        int ret = root->val == target ? 1 : 0;
        if (root->left) {
            ret += rootSum(root->left, target-root->val);
        }
        if (root->right) {
            ret += rootSum(root->right, target-root->val);
        }
        return ret;
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;
        int ret = rootSum(root, targetSum);
        if (root->left) {
            ret += pathSum(root->left, targetSum);
        }
        if (root->right) {
            ret += pathSum(root->right, targetSum);
        }
        return ret;
    }
*/
};
// @lc code=end

