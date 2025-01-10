/*
 * @lc app=leetcode.cn id=940 lang=cpp
 *
 * [940] 不同的子序列 II
 */

// @lc code=start
class Solution {
public:
    int distinctSubseqII(string s) {
        //动态规划
        //last表示某个字母上次出现的位置， -1表示没有出现过
        //我们需要在状态转移的过程中，用last计算，并更新
        vector<int> last(26, -1);
        static constexpr int mod = 1000000007;

        //如果i是子串的最后一个字符，那么有2种情况：
        //当前子串只有一个字符 数目1
        //当前子串至少2个字符，那么需要加和 dp[0]+dp[1]+...+dp[i-1] 并去重
        //重复的原因是: 前面有重复的字母
        //如果s[a] == s[b], 显然dp[a]是dp[b]的子集
        //dp[i] = 1 + (dp[0]+dp[1]+...+dp[i-1] 去重)
        int n = s.length();
        vector<int> dp(n+1, 0);
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j < 26; j++) {
                if (last[j] != -1) {
                    dp[i] = (dp[i] + dp[last[j]]) % mod;
                }
            }
            if ( i < n) {
                dp[i]++;
                last[s.at(i)-'a'] = i;
            }
        }
        //最后需要把dp求和，也可以dp多算一轮，不过没必要
        return dp[n];
    }
};
// @lc code=end

