/*
 * @lc app=leetcode.cn id=1799 lang=cpp
 *
 * [1799] N 次操作后的最大分数和
 */

// @lc code=start
class Solution {
public:

    int maxScore(vector<int>& nums) {
        int m = nums.size();
        //space: 2^m + m*m
        vector<int> dp(1<<m, 0);
        vector<vector<int>> gcd_tmp(m, vector<int>(m, 0));
        //time: m*m
        for (int i = 0; i < m; i++) {
            for (int j = i+1; j < m; j++)
                gcd_tmp[i][j] = gcd(nums[i], nums[j]);
        }
        //all每一bit代表nums中的一个数字，每一个s代表子序列数字的组合
        int all = 1 << m;
        for (int s = 2; s < all; s++) {
            //计算当前元素的数量，只有偶数才有意义
            int t = __builtin_popcount(s);
            //不合法，不处理跳过, 因为我们总是22的成对的，不会有奇数个元素
            if (t & 1)
                continue;
            for (int i = 0; i < m; i++) {
                //判断第i个元素是否存在
                if ((s >> i) & 1) {
                    for (int j = i + 1; j < m; j++) {
                        //判断第j个元素是否存在
                        if (s >> j & 1) {
                            dp[s] = max(dp[s], dp[s ^ (1 << i) ^ (1 << j)] + t / 2 * gcd_tmp[i][j]);
                        }
                    }
                }
            }
        }

        return dp[all-1];
    }

};
// @lc code=end

