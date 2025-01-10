/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0 || (divisor == INT_MIN)) return 0;
        if (divisor == 1) return dividend;
        if (divisor == -1) return dividend == INT_MIN ? INT_MAX : 0-dividend;
        bool nagtive = (dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0);
        if (nagtive) divisor = 0 - divisor;
        dividend = dividend - divisor;
        int ret = 1;
        if (divisor < 0) divisor = 0 - divisor;
        if (dividend < 0) dividend = 0 - dividend;
        while (dividend >= divisor) {
            int cur_divisor = divisor;
            int cur_cnt = 1;
            while (cur_divisor <= dividend - cur_divisor) {
                cur_divisor += cur_divisor;
                cur_cnt += cur_cnt;
            }
            while (dividend >= cur_divisor) {
                dividend -= cur_divisor;
                ret += cur_cnt;
            }
        }

        return ret;
    }
};
// @lc code=end

