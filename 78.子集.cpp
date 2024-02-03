/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    void subsets(vector<vector<int>>& res, vector<int>& vec, vector<int>& nums, int cur) {
        res.push_back(vec);
        for (int i = cur; i < nums.size(); i++) {
            vec.push_back(nums[i]);
            if (i + 1 < nums.size()) {
                subsets(res, vec, nums, i+1);
            }else{
                res.push_back(vec);
            }
            vec.pop_back();
        }
    }

    vector<vector<int>> subsets2(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> vec;
        subsets(res, vec, nums, 0);
        return res;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        for (int i = 0; i < (1<<n); i++) {
            vector<int> vec;
            for (int flag = i; flag > 0; flag&=flag-1) {
                int offset = __builtin_ctz(flag & (-flag));
                vec.push_back(nums[offset]);
            }
            res.push_back(vec);
        }
        return res;
    }

    
};
// @lc code=end

