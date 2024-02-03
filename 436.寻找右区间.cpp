/*
 * @lc app=leetcode.cn id=436 lang=cpp
 *
 * [436] 寻找右区间
 */

// @lc code=start
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        //key: start; value: idx;
        map<int, int> m;
        for (int i = 0; i < intervals.size(); i++) {
            m[intervals[i][0]] = i;
        }

        vector<int> ans;
        for (const auto& i : intervals) {
            auto it = m.lower_bound(i[1]);
            if (it == m.end())
                ans.push_back(-1);
            else
                ans.push_back(it->second);
        }

        return ans;
    }
};
// @lc code=end

