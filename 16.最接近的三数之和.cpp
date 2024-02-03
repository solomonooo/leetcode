/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
class Solution {
public:
    //典型的双指针解法
    int threeSumClosest(vector<int>& nums, int target) {
        int ret = INT_MAX;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int a = nums[i];
            if (i > 0 && nums[i] == nums[i-1]) continue;
            for (int left = i + 1, right = n-1; left < right;) {
                int b = nums[left], c = nums[right];
                int sum = a+b+c;
                if (abs((int64_t)sum-target) < abs((int64_t)ret-target))
                    ret = sum;
                if (sum > target) {
                    right--;
                    while (left < right && nums[right] == nums[right+1]) right--; 
                }else if (sum < target) {
                    left++;
                    while (left < right && nums[left] == nums[left-1]) left++; 
                }
                else return target;
            }
        }
        return ret;
    }
};
// @lc code=end

