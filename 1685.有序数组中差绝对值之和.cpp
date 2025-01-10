/*
 * @lc app=leetcode.cn id=1685 lang=cpp
 *
 * [1685] 有序数组中差绝对值之和
 */

// @lc code=start
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> s(n+1, 0);
        for (int i = 0; i < n; i++) {
            s[i+1] = s[i] + nums[i];
        }
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            int cur = nums[i];
            int left = i * cur - s[i];
            int right = s.back() - s[i] - (n-i)*cur;
            res[i] = left + right;
        }
        return res;
    }
};
// @lc code=end

