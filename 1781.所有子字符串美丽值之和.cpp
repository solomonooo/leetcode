/*
 * @lc app=leetcode.cn id=1781 lang=cpp
 *
 * [1781] 所有子字符串美丽值之和
 */

// @lc code=start
class Solution {
public:
    //暴力遍历
    int beautySum(string s) {
        int res = 0, n = s.length();
        for (int left = 0; left + 1 < n; left++) {
            vector<int> dict(26, 0);
            int maxn = 0;
            for (int right = left; right < n; right++) {
                int idx = s.at(right) - 'a';
                dict[idx]++;
                maxn = max(maxn, dict[idx]);
                int minn = INT_MAX;
                for (int v : dict) {
                    if (v > 0) {
                        minn = min(v, minn);
                    }
                }
                res += maxn - minn;
            }
        }
        return res;
    }
};
// @lc code=end

