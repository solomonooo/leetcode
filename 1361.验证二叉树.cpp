/*
 * @lc app=leetcode.cn id=1361 lang=cpp
 *
 * [1361] 验证二叉树
 */

// @lc code=start
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> parent(n, 0);
        for (size_t i = 0; i < leftChild.size(); i++) {
            if (leftChild[i] < 0) continue;
            parent[leftChild[i]]++;
        }
        for (size_t i = 0; i < rightChild.size(); i++) {
            if (rightChild[i] < 0) continue;
            parent[rightChild[i]]++;
        }
        int root = -1;
        for (size_t i = 0; i < parent.size(); i++) {
            if (parent[i] > 1) return false;
            if (parent[i] == 0) {
                root = i;
                break;
            }
        }
        if (root == -1) return false;
        set<int> seen = {root};
        queue<int> pending;
        pending.push(root);
        while(!pending.empty()) {
            int cur = pending.front();
            pending.pop();
            int left = leftChild[cur];
            if (left >= 0) {
                if (seen.count(left)) return false;
                seen.insert(left);
                pending.push(left);
            }
            int right = rightChild[cur];
            if (right >= 0) {
                if (seen.count(right)) return false;
                seen.insert(right);
                pending.push(right);
            }
        }
        return seen.size() == n;
    }
};
// @lc code=end

