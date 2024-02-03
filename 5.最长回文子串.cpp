/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    //两种方法
    //1. 中心扩展算法
    //遍历每个s[i],检查两边，找到最大的回文
    //需要遍历2种模式，<i, i>和<i, i+1>
    //状态转移方程类似dp:
    //P(i)(i) = true
    //P(i)(i+1) = s[i] == s[i+1]
    //P(i)(j) = P(i+1)(j-1) ^ (s[i] == s[j])
    pair<int, int> check(const string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s.at(left) == s.at(right)) {
            left--;
            right++;
        }
        return {left+1, right-1};
    }

    string longestPalindromeEx(string s) {
        int start = 0, end = 0;
        for (int i = 0; i < s.length(); i++) {
            for (int j = i; j < i + 2 && j < s.length(); j++) {
                auto [left, right] = check(s, i, j);
                if (right - left > end - start) {
                    start = left;
                    end = right;
                }
            }
        }
        return s.substr(start, end - start + 1);
    }

    //解法2: 动态规划
    //状态转移方程和上面一样的
    //注意:
    //1. 处理边界情况 s.length() < 2
    //2. 
    string longestPalindrome(string s) {
        if (s.length() < 2) return s;
        vector<vector<bool>> dp(s.length(), vector(s.length(), false));
        int start = 0, len = 1;
        for (int L = 1; L <= s.length(); L++) {
            //j-i+1=L => j = L+i-1
            for (int i = 0; L+i-1 < s.length(); i++) {
                if (L == 1) {
                    dp[i][i] = true;
                }else if (s.at(i) == s.at(L+i-1)){
                    //这里需要判断L == 2的情况
                    //L==2对应P(i)(i+1) = s[i] == s[i+1]
                    dp[i][L+i-1] = L > 2 ? dp[i+1][L+i-2] : true;
                    if (dp[i][L+i-1] && L > len) {
                        len = L;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start, len);
    }

};
// @lc code=end

