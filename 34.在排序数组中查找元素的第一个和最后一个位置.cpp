/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1};
        int mid = -1, n = nums.size();
        int left = 0, right = n-1;
        while (left <= right) {
            mid = left + (right-left) / 2;
            if (nums[mid] == target) {
                break;
            }
            if (target < nums[mid]) {
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        if (nums[mid] != target) return {-1, -1};
        int start = mid, end = mid;
        while (start > 0 && nums[start-1] == target) start--;
        while (end + 1 < n && nums[end+1] == target) end++;
        return {start, end};
    }
};
// @lc code=end

