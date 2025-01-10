/*
 * @lc app=leetcode.cn id=373 lang=cpp
 *
 * [373] 查找和最小的 K 对数字
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        typedef pair<int, int> Idx;
        auto cmp = [&nums1, &nums2](const Idx& a, const Idx& b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };
        int m = nums1.size(), n = nums2.size();
        vector<vector<int>> res;
        priority_queue<Idx, vector<Idx>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < min(k, m); i++) {
            pq.emplace(i, 0);
        }
        for (int i = 0; i < k; i++) {
            if (pq.empty()) break;
            auto[a, b] = pq.top();
            pq.pop();
            res.push_back({nums1[a], nums2[b]});
            if (b+1 < n) {
                pq.emplace(a, b+1);
            }
            
        }
        return res;
    }
};
// @lc code=end

