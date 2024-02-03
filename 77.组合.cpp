/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
public:
    void combine(vector<vector<int>>& res, vector<int>& vec, int cur, int n, int k) {
        for (int i = cur; i+k-1 <= n; i++) {
            vec.push_back(i);
            if (k-1 > 0) {
                combine(res, vec, i+1, n, k-1);
            }else{
                res.push_back(vec);
            }
            vec.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> vec;
        combine(res, vec, 1, n, k);
        return res;
    }
};
// @lc code=end

