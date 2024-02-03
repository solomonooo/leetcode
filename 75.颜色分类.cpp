/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        for (int cur = 0, v0 = -1, v2 = nums.size(); cur < v2; cur++) {
            int val = nums[cur];
            if (val == 0) {
                if (v0 < cur) swap(nums[v0+1], nums[cur]);
                v0++;
            }else if (val == 2) {
                swap(nums[--v2], nums[cur--]);
            }
        }
    }
};
// @lc code=end

