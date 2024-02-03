/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        if (target < matrix[0][0] || target > matrix[m-1][n-1]) return false;
        //两次二分查找
        int top = 0, down = m-1;
        while (top < down) {
            int mid = (top+down)/2;
            if (target >= matrix[mid][0] && target <= matrix[mid][n-1]) {
                top = down = mid;
            } else if (target > matrix[mid][n-1]) {
                top = mid+1;
            }else{
                down = mid-1;
            }
        }
        int left = 0, right = n-1;
        while (left < right) {
            int mid = (left+right)/2;
            if (target == matrix[top][mid]) return true;
            if (target > matrix[top][mid]) {
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        return matrix[top][left] == target;
    }
};
// @lc code=end

