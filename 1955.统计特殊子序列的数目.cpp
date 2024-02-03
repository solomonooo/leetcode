/*
 * @lc app=leetcode.cn id=1955 lang=cpp
 *
 * [1955] 统计特殊子序列的数目
 */

// @lc code=start
class Solution {
public:
    static constexpr int mod = 1000000007;

    /*
    dp[i] = dp[i][2]

    dp[i][2] = n[i] == 2 ? dp[i-1][2]*2 + dp[i-1][1] : dp[i-1][2];
    dp[i][1] = n[i] == 1 ? dp[i-1][1]*2 + dp[i-1][0] : dp[i-1][1];
    dp[i][0] = n[i] == 0 ? dp[i-1][0]*2 + 1 : dp[i-1][0];

    dp[0] == 0 ? 1,0,0,  0,0,0
*/

    int countSpecialSubsequences_1(vector<int>& nums) {
        vector<vector<int>> dp;
        for (int i = 0; i < 3; i++) {
            dp.push_back(vector<int>(nums.size()));
            dp[i][0] = i == 0 && nums[i] == 0 ? 1 : 0;
            for (int j = 1; j < nums.size(); j++) {
                if (nums[j] == i) {
                    dp[i][j] = ((dp[i][j-1]*2%mod) + (i > 0 ? dp[i-1][j-1] : 1)) % mod;
                }else{
                    dp[i][j] = dp[i][j-1];
                }
            }
        }

        return dp[2][nums.size()-1];
    }

    int countSpecialSubsequences(vector<int>& nums) {
        vector<int> dp(3, 0);
        for (int n : nums) {
            dp[n] = (dp[n] * 2 % mod + (n > 0 ? dp[n-1] : 1)) % mod;
        }
        return dp[2];
    }


};

// @lc code=end




