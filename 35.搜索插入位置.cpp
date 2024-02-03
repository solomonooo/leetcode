/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        int mid = (left+right)/2;
        while(left < right){
            if(target < nums[mid]){
                right = mid-1;
            }else if(target > nums[mid]){
                left = mid+1;
            }else{
                return mid;
            }
            mid = (left+right)/2;
        }
        
        return target <= nums[mid] ? mid : mid+1;
    }
};
// @lc code=end

