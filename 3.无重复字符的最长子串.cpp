/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxn = 0, n = s.length();
        unordered_map<char, int> tmp; //<value, idx>
        int start = 0;
        for (int cur = 0; cur < n; cur++) {
            auto iter = tmp.find(s.at(cur));
            if (iter != tmp.end() && iter->second >= start) {
                maxn = max(maxn, cur-start);
                start = iter->second + 1;
            }
            tmp[s.at(cur)] = cur;
        }
        return max(maxn, n - start);
    }
};
// @lc code=end

