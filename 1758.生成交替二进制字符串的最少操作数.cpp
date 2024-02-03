/*
 * @lc app=leetcode.cn id=1758 lang=cpp
 *
 * [1758] 生成交替二进制字符串的最少操作数
 */

// @lc code=start
class Solution {
public:
    int minOperations(string s) {
        int length = s.length();
        int cnt = 0;
        for (int i = 0; i < length; i++) {
            if (s.at(i) == ((i & 1) > 0 ? '1' : '0')) {
                cnt++;
            }
        }
        return min(cnt, length-cnt);
    }
};
// @lc code=end

