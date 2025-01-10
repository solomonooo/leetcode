/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
class Solution {
public:
    //暴力法：每行二叉搜索
    //更好的方案：右上角可以看做一个二叉搜索树的root
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0, j = n-1; i < m && j >= 0;) {
            int cur = matrix[i][j];
            if (cur == target) return true;
            if (cur < target) {
                i++;
            }else{
                j--;
            }
        }
        return false;
    }
};
// @lc code=end

