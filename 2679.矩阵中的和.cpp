/*
 * @lc app=leetcode.cn id=2679 lang=cpp
 *
 * [2679] 矩阵中的和
 */

// @lc code=start
class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        vector<set<int>> tmp(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            for (int v : nums[i]) {
                tmp[i].insert(v);
            }
        }

        int ans = 0;
        for (int i = 0; i < nums[0].size(); i++) {
            int cur = 0;
            for ()
        }

        
    }
};
// @lc code=end

