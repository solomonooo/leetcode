/*
 * @lc app=leetcode.cn id=44 lang=cpp
 *
 * [44] 通配符匹配
 */

// @lc code=start
class Solution {
public:
    //动态规划
    //dp[i][j] = s[0..i-1]和p[0..j-1]匹配情况
    //      p[j-1] == ?  => dp[i-1][j-1]
    //      p[j-1] == *  => dp[i][j-1] 匹配0个 || dp[i-1][j] 匹配1个以上
    //      other        => dp[i-1][j-1] && s[i-1] == p[j-1]
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true;
        for (int i = 0; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == 0) {
                    dp[i][j] = (p[j-1] == '*') && dp[i][j-1];
                }else{
                    if (p[j-1] == '?')
                        dp[i][j] = dp[i-1][j-1];
                    else if (p[j-1] == '*')
                        dp[i][j] = dp[i][j-1] || dp[i-1][j];
                    else
                        dp[i][j] = dp[i-1][j-1] && s[i-1] == p[j-1];
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end

