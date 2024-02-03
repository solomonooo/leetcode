/*
 * @lc app=leetcode.cn id=2302 lang=cpp
 *
 * [2302] 统计得分小于 K 的子数组数目
 */

// @lc code=start
class Solution {
public:
    long long countSubarrays(vector<int> &nums, long long k) {
        long long cnt = 0, sum = 0;
        for (size_t start = 0, end = 0; end < nums.size(); end++) {
            sum += nums[end];
            while (sum * (end-start+1) >= k) {
                sum -= nums[start++];
            }
            cnt += end - start + 1;
        }
        return cnt;
    }
};
// @lc code=end

