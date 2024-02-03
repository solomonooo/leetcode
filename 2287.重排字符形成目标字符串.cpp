/*
 * @lc app=leetcode.cn id=2287 lang=cpp
 *
 * [2287] 重排字符形成目标字符串
 */

// @lc code=start
class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char, int> m1, m2;
        for (char c : target) {
            m1[c]++;
        }
        for (char c: s) {
            m2[c]++;
        }

        int ans = INT_MAX;
        for (auto& kv : m1) {
            int a = m2[kv.first];
            int b = kv.second;
            if (a < b) return 0;
            ans = min(ans, a/b);
        }

        return ans != INT_MAX ? ans : 0;
    }
};
// @lc code=end

