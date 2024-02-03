/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
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
        }else if (target > val && idx + 1 < candidates.size()) {
            //choose val
            vec.push_back(val);
            combination(candidates, idx+1, target - val, vec, output);
            vec.pop_back();

            int next = idx+1;
            while (next + 1 < candidates.size() && candidates[next] == val) next++; 
            cout<<"next="<<next<<endl;   
            combination(candidates, next, target, vec, output);
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> output;
        vector<int> vec;
        combination(candidates, 0, target, vec, output);
        return output;
    }
};
// @lc code=end

