/*
 * @lc app=leetcode.cn id=2570 lang=cpp
 *
 * [2570] 合并两个二维数组 - 求和法
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int, int> m;
        for (const auto& v : nums1) {
            m[v[0]] = v[1]; 
        }
        for (const auto& v : nums2) {
            m[v[0]] += v[1]; 
        }
        vector<vector<int>> res;
        for (const auto& kv : m) {
            res.emplace_back(vector<int>{kv.first, kv.second});
        }
        return res;
    }
};
// @lc code=end

