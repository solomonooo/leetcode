/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1;
        while(start <= end){
            int mid = start + (end-start)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[start] <= nums[mid]){
                if(target >= nums[start] && target < nums[mid])
                    end = mid -1;
                else  //target < start || target > mid
                    start = mid+1;
            }else{
                if(target <= nums[end] && target > nums[mid])
                    start = mid+1;
                else
                    end = mid - 1;
            }
        } 
        return -1;  
        //return nums.size()>0 && nums[start] == target ? start : -1; 
    }   
};
// @lc code=end

