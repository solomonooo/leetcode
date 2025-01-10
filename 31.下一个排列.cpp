/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pos = n-2;
        while (pos >= 0 && nums[pos] >= nums[pos+1]) pos--;
        if (pos >= 0) {
            int change = n-1;
            while (change > pos && nums[change] <= nums[pos]) change--;
            swap(nums[pos], nums[change]);
        }
        reverse(nums.begin()+pos+1, nums.end());
    }
};

// @lc code=end


/