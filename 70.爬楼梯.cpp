/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    //动态规划
    //dp[i] = dp[i-1]+dp[i-2]
    int climbStairs(int n) {
        int res = 0;
        //不需要数组，从1开始，prev=1,表示到1需要1种方法, prev_prev=0
        for (int i = 1, prev=1, prev_prev=0; i <= n; i++) {
            res = prev + prev_prev;
            prev_prev = prev;
            prev = res;
        }
        return res;
    }
};
// @lc code=end

