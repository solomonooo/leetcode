/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int row = matrix.size();
        int col = matrix[0].size();
        for (int left = 0, right = col, top = 0, down = row; left < right && top < down;) {
            for (int i = left; i < right && top < down; i++)
                ans.push_back(matrix[top][i]);
            top++;
            for (int i = top; i < down && left < right; i++)
                ans.push_back(matrix[i][right-1]);
            right--;
            for (int i = right-1; i >= left && top < down; i--)
                ans.push_back(matrix[down-1][i]);
            down--;
            for (int i = down-1; i >= top && left < right; i--) 
                ans.push_back(matrix[i][left]);
            left++;
        }
        return ans;
    }
};
// @lc code=end

