/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0, end = 0, maxn = 0; i < n && maxn < n-1; i++) {
            maxn = max(maxn, i+nums[i]);
            if (i == end) {
                if (end == maxn && i < n-1) return false;
                end = maxn;
            }
        }
        return true;
    }
};
// @lc code=end

