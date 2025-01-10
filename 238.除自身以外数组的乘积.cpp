/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        for (int i = 1; i < n; i++) {
            res[i] = res[i-1] * nums[i-1];
        }
        int right = 1;
        for (int i = n-1; i >= 0; i--) {
            res[i] *= right;
            right *= nums[i];
        }
        return res;
    }

    vector<int> productExceptSelf2(vector<int>& nums) {
        //看起来这题可以先计算所有元素的乘积，然后用除法，但是有2个问题
        //1. 不给用除法
        //2. 如果元素存在0，则相当麻烦
        int n = nums.size();
        vector<int> left(n, 1), right(n, 1);
        for (int i = 1; i < n; i++) {
            left[i] = left[i-1] * nums[i-1];
        }
        for (int i = n - 2; i >= 0; i--) {
            right[i] = right[i+1] * nums[i+1];
        }
        vector<int> res;
        for (int i = 0; i < n; i++) {
            res.push_back(left[i] * right[i]);
        }
        return res;
    }
};
// @lc code=end

