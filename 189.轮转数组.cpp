/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组
 */

// @lc code=start
class Solution {
public:
    void rotate2(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        if (n == 1 || k == 0) {
            return;
        }

        vector<int> tmp(k, 0);
        for (int i = 0; i < k; i++) {
            tmp[i] = nums[n-k+i];
        }
        for (int i = n-1-k; i >= 0; i--) {
            nums[i+k] = nums[i];
        }
        for (int i = 0; i < k; i++) {
            nums[i] = tmp[i];
        }
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        if (n != 1 && k > 0) {
            reverse(nums.begin(), nums.end());
            reverse(nums.begin(), nums.begin()+k);
            reverse(nums.begin()+k, nums.end());
        }
    }
};
// @lc code=end

