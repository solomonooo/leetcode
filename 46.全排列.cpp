/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    void premute(vector<int>& nums, vector<vector<int>>& output, vector<int>& cur, int flag) {
        if (flag == 0) {
            output.push_back(cur);
            return;
        }

        for (int i = flag; i > 0; i &=i-1) {
            int idx = __builtin_ctz(i&(-i));
            cur.push_back(nums[idx]);
            premute(nums, output, cur, flag^(1<<idx));
            cur.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> output;
        vector<int> cur;
        premute(nums, output, cur, (1<<nums.size())-1);
        return output;
    }
};
// @lc code=end

