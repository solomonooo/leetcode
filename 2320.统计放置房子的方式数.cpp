/*
 * @lc app=leetcode.cn id=2320 lang=cpp
 *
 * [2320] 统计放置房子的方式数
 */

// @lc code=start
class Solution {
public:
    //dp[i][0] = dp[i-1][0] + dp[i-1][1]
    //dp[i][1] = dp[i-1][0]
    int countHousePlacementsEx(int n) {
        uint64_t res = 0;
        vector<vector<uint64_t>> dp(n, vector<uint64_t>(2));
        dp[0][0] = 1;
        dp[0][1] = 1;
        for (int i = 1; i < n; i++) {
            dp[i][0] = (dp[i-1][0] + dp[i-1][1]) % 1000000007;
            dp[i][1] = dp[i-1][0];
        }
        res = dp[n-1][0]+dp[n-1][1];
        return (res * res) % 1000000007;
    }

    //第i个地块的方案=i不放，i-1可放可不放 + i放，i-1一定不放，就等于i-2的数量
    //dp[i] = dp[i-1] +  dp[i-2]
    int countHousePlacements(int n) {
        uint64_t res = 0;
        vector<uint64_t> dp(n+1);
        dp[0] = 1;
        dp[1] = 2;
        for (int i = 2; i <= n; i++) {
            dp[i] = (dp[i-1] + dp[i-2]) % 1000000007;
        }
        return (dp[n] * dp[n]) % 1000000007;
    }
};
// @lc code=end

