/*
 * @lc app=leetcode.cn id=2256 lang=cpp
 *
 * [2256] 最小平均差
 */

// @lc code=start
class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int64_t total = 0;
        for (auto i : nums)
            total += i;

        int64_t left = 0, right = total;
        int ans = 0;
        int min_avg = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            left += nums[i];
            right -= nums[i];
            int64_t avg_left = left / (i+1);
            int64_t avg_right = i + 1 < nums.size() ? right / (nums.size()-i-1) : 0;
            if (abs(avg_right-avg_left) < min_avg) {
                ans = i;
                min_avg = abs(avg_right-avg_left);
            }
        }
        return ans;
    }
};
// @lc code=end

