/*
 * @lc app=leetcode.cn id=2841 lang=cpp
 *
 * [2841] 几乎唯一子数组的最大和
 */

// @lc code=start
class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        long long maxn = 0, sum = 0;
        unordered_map<int, int> counter;
        for (int start = 0, end = 0; end < nums.size(); end++, start++) {
            counter[nums[end]]++;
            sum += nums[end];
            while (end - start + 1 < k && end + 1 < nums.size()) {
                end++;
                sum += nums[end];
                counter[nums[end]]++;
            }
            if (end - start + 1 == k && counter.size() >= m) {
                maxn = max(maxn, sum);
            }
            if (counter[nums[start]] > 1)
                counter[nums[start]]--;
            else
                counter.erase(nums[start]);
            sum -= nums[start];
        }
        return maxn;
    }
};
// @lc code=end

