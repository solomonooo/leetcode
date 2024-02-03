/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution {
public:
    void subsets(vector<vector<int>>& res, vector<int>& vec, vector<int>& nums, int cur) {
        res.push_back(vec);
        for (int i = cur; i < nums.size(); i++) {
            if (i > cur && nums[i] == nums[i-1]) continue;
            vec.push_back(nums[i]);
            if (i + 1 < nums.size()) {
                subsets(res, vec, nums, i+1);
            }else{
                res.push_back(vec);
            }
            vec.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> vec;
        sort(nums.begin(), nums.end());
        subsets(res, vec, nums, 0);
        return res;
    }
};
// @lc code=end

