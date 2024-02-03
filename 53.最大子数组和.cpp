/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
public:
    //如果当前子串<=0, 那么显然如果加上这个子串，肯定是<=当前的值的
    //相反，一定会增加和
    //需要考虑特殊情况，如果当前子串<=0, 需要重置当前的求和
    int maxSubArray(vector<int>& nums) {
         int maxn = INT_MIN;
         for (int i = 0, sum = 0; i < nums.size(); i++) {
            sum += nums[i];
            maxn = max(maxn, sum);
            if (sum <= 0) sum = 0;
         };
         return maxn;
    }
};
// @lc code=end

