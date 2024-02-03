/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
public:
    void premute(vector<int>& nums, vector<vector<int>>& output, vector<int>& cur, int flag) {
        if (flag == 0) {
            output.push_back(cur);
            return;
        }

        for (int i = flag, prev=INT_MIN; i > 0; i &=i-1) {
            int idx = __builtin_ctz(i&(-i));
            if (nums[idx] == prev) continue;
            cur.push_back(nums[idx]);
            premute(nums, output, cur, flag^(1<<idx));
            cur.pop_back();
            prev = nums[idx];
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> output;
        vector<int> cur;
        premute(nums, output, cur, (1<<nums.size())-1);
        return output;
    }
};
// @lc code=end

