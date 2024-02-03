/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
    //1. 贪心算法
    //优先选择下一步可以跳到更远y的位置x，但并不意味着i的下一步一定跳到y,因为在[x,y]之间可能存在更远的跳法
    //下一次贪心选择的时候，以y为限制，选择[x,y]之间能跳到的更远z的位置
    //如果第一次跳到x，x最远可以跳到y，那x一定可以跳到[x,y]之间的那个位置，所以每次都是最优的选择
    int jump(vector<int>& nums) {
        int n = nums.size(), maxn = 0, step = 0;
        for (int i = 0, end = 0; i < n-1; i++) {
            maxn = max(maxn, i+nums[i]);
            if (i == end) {
                step++;
                end = maxn;
            }
        }
        return step;
    }

    //2. 动态规划
    int jumpEX(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= nums[i] && i+j < n; j++) {
                if (dp[i+j] > 0)
                    dp[i+j] = min(dp[i+j], dp[i] + 1);
                else
                    dp[i+j] = dp[i] + 1;
            }
        }
        return dp[n-1];
    }

};
// @lc code=end

