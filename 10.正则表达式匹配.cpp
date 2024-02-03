/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        //动态规划问题
        //dp[i][j]表示s前i个子串和p前j个子串是否匹配
        vector<vector<bool>> dp(s.length()+1, vector<bool>(p.length()+1, false));
        for(int i = 0; i <= s.length(); i++){
            for(int j = 0; j <= p.length(); j++){
                if(j == 0)
                    //初始的0串我们认为都是匹配的
                    dp[i][j] = i == 0;
                else if(i == 0)
                    //匹配a*b，但是a是0个的情况，也就是p前面有一段冗余的部分
                    //j==1的时候进来，题目已经保证了p里每个*前面必有合法字符，也就是p[0]绝对不是'*', 所以dp[0][j-2]一定合法不会越界
                    dp[i][j] = p[j-1] == '*' && dp[0][j-2];
                else{
                    if(p[j-1] == '*')
                        //匹配2种情况：
                        //1. 如果*前面的p子串已经匹配了s的前i个子串，这时候认为*匹配了0个p[j-2]
                        //2. 如果*前面的p子串已经匹配了s的前i-1个子串, 这时候需要检查s[i-1]是不是满足匹配. 要么s[i-1]和p[j-2]相等，要么p[j-2]是通配符.
                        dp[i][j] = dp[i][j-2] || ((s[i-1] == p[j-2] || p[j-2] == '.') && dp[i-1][j]);
                    else
                        //如果p的前j-1子串已经匹配了s的前i-1个子串, 这时候检查s[i-1]是不是满足匹配
                        dp[i][j] = ((s[i-1] == p[j-1] || p[j-1] == '.') && dp[i-1][j-1]);
                }
            }
        }
        return dp[s.length()][p.length()];
    }
};
// @lc code=end

