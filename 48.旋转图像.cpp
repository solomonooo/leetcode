/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution {
public:
    //顺时针旋转意味着逆时针交换
    //每个位置构成的环都需要逆时针交换，依次按照外圈向内遍历
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n - i - 1; i++){
            for(int j = i; j < n - i - 1; j++){
                swap(matrix[i][j], matrix[n-j-1][i]);
                swap(matrix[n-j-1][i], matrix[n-i-1][n-j-1]);
                swap(matrix[n-i-1][n-j-1], matrix[j][n-i-1]);
            }
        }
    }
};
// @lc code=end

