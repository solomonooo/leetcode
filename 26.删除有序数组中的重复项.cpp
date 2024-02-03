/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        size_t idx = 1;
        for(size_t i = 1; i < nums.size(); i++){
            if(nums[idx-1] != nums[i]){
                    nums[idx++] = nums[i];
            }
        }
        return idx;
    }
};
// @lc code=end

