/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */

// @lc code=start
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool r1_zero = false, c1_zero = false;
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                c1_zero = true; 
                break;
            }
        }
        for (int i = 0; i < n; i++) {
            if (matrix[0][i] == 0) {
                r1_zero = true; 
                break;
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = matrix[i][0] = 0;
                }
            }
        }
        //切记必须倒着遍历，不然第1行列会被覆盖，后续没法判断
        for (int i = m-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                if (i == 0) {
                    if (r1_zero) matrix[0][j] = 0;
                }else if (j == 0) {
                    if (c1_zero) matrix[i][0] = 0;
                }else{
                    if (matrix[0][j] == 0 ||  matrix[i][0] == 0){
                        matrix[i][j] = 0;
                    }
                }
            }
        }
    }
};
// @lc code=end

