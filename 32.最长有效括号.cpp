/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> dp(s.length(), 0);
        int max = 0;
        for(int i = 1; i < s.length(); i++){
            if(s[i] == ')'){
                //(******)
                if(i - dp[i-1] - 1 >= 0 && s[i - dp[i-1] - 1] == '('){
                    dp[i] = dp[i-1]+2;
                    //加上前面匹配好的有效串
                    if(i - dp[i-1] - 2 >= 0){
                        dp[i] += dp[i - dp[i-1] - 2];
                    }
                    max = std::max(max, dp[i]);
                }
            }
        }
        return max;
    }
};
// @lc code=end

