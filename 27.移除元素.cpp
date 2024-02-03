/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElementEx(vector<int>& nums, int val) {
        int len = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                if (len != i) {
                    nums[len] = nums[i];
                    
                }
                len++;
            }
        }
        return len;
    }

    int removeElement(vector<int>& nums, int val) {
        int len = 0;
        for (int i = 0, j = nums.size()-1; i <= j; i++) {
            if (nums[i] == val) {
                while (i < j && nums[j] == val) j--;
                if (i >= j) break;
                nums[i] = nums[j--];
            }
            len++;
        }
        return len;
    }
};
// @lc code=end

