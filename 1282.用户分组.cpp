/*
 * @lc app=leetcode.cn id=1282 lang=cpp
 *
 * [1282] 用户分组
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        map<int, vector<int>> m;
        for (int i = 0; i < n; i++) {
            m[groupSizes[i]].push_back(i);
        }

        vector<vector<int>> ans;
        for (auto& kv : m) {
            int sz = kv.first;
            const auto& nn = kv.second;
            for (int i = 0; i < nn.size(); i+=sz) {
                ans.emplace_back(vector<int>(nn.begin()+i, nn.begin()+i+sz));
            }
        }
        return ans;
    }
};
// @lc code=end

