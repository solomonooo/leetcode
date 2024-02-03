/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
class Solution {
public:
    //动态规划
    //要点，在任何位置编辑，和在末尾编辑是等价的
    //dp[i][j]: word1和前i个串变化成word2的第j个串的最小次数
    //dp[i][j]=min(dp[i-1][j]+1, dp[i][j-1]+1, dp[i-1][j-1]+(word1[i-1]==[word2[j-1]]))
    int minDistance(string word1, string word2) {
        int n1 = word1.length(), n2 = word2.length();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        for (int i = 0; i <= n1; i++) {
            for (int j = 0; j <= n2; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = i+j;
                }else{
                    int extra = word1[i-1] == word2[j-1] ? 0 : 1;
                    dp[i][j] = min(dp[i-1][j-1]+extra, min(dp[i-1][j]+1, dp[i][j-1]+1));
                }
            }
        }
        return dp[n1][n2];
    }
};
// @lc code=end

