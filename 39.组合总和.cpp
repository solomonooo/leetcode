/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
public:
    void combination(vector<int>& candidates, int idx, int target, vector<int>& vec, vector<vector<int>>& output) {
        int val = candidates[idx];
        if (target == val) {
            //find
            vec.push_back(val);
            output.push_back(vec);
            vec.pop_back();
        }else if (target > val) {
            //choose val
            vec.push_back(val);
            combination(candidates, idx, target - val, vec, output);
            vec.pop_back();
            
            //choose next
            if (idx + 1 < candidates.size())
                combination(candidates, idx+1, target, vec, output);
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> output;
        vector<int> vec;
        combination(candidates, 0, target, vec, output);
        return output;
    }
};
// @lc code=end

