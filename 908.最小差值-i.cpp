/*
 * @lc app=leetcode.cn id=908 lang=cpp
 *
 * [908] 最小差值 I
 */

// @lc code=start
class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int minn = nums[0], maxn = nums[0];
        for (int i : nums) {
            minn = min(i, minn);
            maxn = max(i, maxn);
        }
        return max(0, maxn - minn - 2 * k);
    }
};
// @lc code=end

