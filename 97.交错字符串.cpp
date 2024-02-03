/*
 * @lc app=leetcode.cn id=97 lang=cpp
 *
 * [97] 交错字符串
 */

// @lc code=start
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length(), n = s2.length(), l = s3.length();
        if (m+n != l) return false;
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i==0 && j==0) {
                    dp[i][j] = true;
                }else{
                    bool b1 = i > 0? dp[i-1][j] && (s1[i-1]==s3[i+j-1]) : false;
                    bool b2 = j > 0? dp[i][j-1] && (s2[j-1]==s3[i+j-1]) : false;
                    dp[i][j] = b1 || b2;
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end

