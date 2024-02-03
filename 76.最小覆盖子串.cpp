/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
public:
    bool check(unordered_map<char, int>& target, unordered_map<char, int>& cur) {
        if (target.size() > cur.size()) return false;
        for (const auto& kv : target) {

            if (cur[kv.first] < kv.second) return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        unordered_map<char, int> m1, m2;
        for (char c : t) {
            m1[c]++;
        }
        vector<bool> valid(s.length(), false);
        int min_left = 0, min_right = INT_MAX;
        for (int left = 0, cur = 0; cur < s.length(); cur++) {
            m2[s[cur]]++;
            //此时找到区间[left, cur]满足匹配
            bool found = false;
            while (check(m1, m2) && left <= cur) {
                found = true;
                m2[s[left++]]--;
            }
            //此时缩小区间到不满足匹配, 注意此时区间应为[left-1, cur)
            if (found && cur-left+1 < min_right-min_left) {
                min_left = left-1;
                min_right = cur;
            }
        }
        return min_right == INT_MAX ? "" : s.substr(min_left, min_right-min_left+1);
    }
};
// @lc code=end

