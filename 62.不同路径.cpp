/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
class Solution {
public:
    //经典的dp
    //dp[i][j]: 到达i,j位置的方法数
    //dp[i][j] = dp[i-1][j] + dp[i][j-1]
    //dp[0][0] = 1
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0)
                    dp[0][0] = 1;
                else
                    dp[i][j] = (i > 0 ? dp[i-1][j] : 0) + (j > 0 ? dp[i][j-1] : 0);
            }
        }
        return dp[m-1][n-1];
    }
};
// @lc code=end

