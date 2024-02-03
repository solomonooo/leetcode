/*
 * @lc app=leetcode.cn id=920 lang=cpp
 *
 * [920] 播放列表的数量
 */

// @lc code=start
class Solution {
public:

    //dp[0][0] = 1
    //dp[i][j]: 听了i首歌里面有j首不同的歌曲
    //dp[i][j] = dp[i-1][j-1] * (n-j+1) + dp[i-1][j] * max(j-k, 0)
    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<int64_t>> dp(goal+1, vector<int64_t>(n+1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= goal; i++) {
            //没有必要从1开始，因为如果已经听了i首歌，那么至少里面有k首是不重复的
            for (int j = max(1, min(i, k)); j <= n; j++) {
                dp[i][j] = dp[i-1][j] * max(j-k, 0) + dp[i-1][j-1] * (n-j+1);
                dp[i][j] %= 1000000007;
            }
        }
        return (int)dp[goal][n];
    }
};
// @lc code=end

