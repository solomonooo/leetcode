/*
 * @lc app=leetcode.cn id=165 lang=cpp
 *
 * [165] 比较版本号
 */

// @lc code=start
class Solution {
public:
    int get_subver(string_view sv, size_t& start) {
        int ret = 0;
        while (start < sv.length() && sv[start] != '.') {
            ret = ret * 10 + (sv[start] - '0');
            start++;
        }
        return ret;
    }

    int compareVersion(string version1, string version2) {
        string_view sv1(version1);
        string_view sv2(version2);
        for (size_t s1 = 0, s2 = 0; s1 < sv1.length() || s2 < sv2.length(); s1++, s2++) {
            int v1 = get_subver(sv1, s1);
            int v2 = get_subver(sv2, s2);
            if (v1 == v2) continue;
            return v1 > v2 ? 1 : -1;
        }

        return 0;
    }
};
// @lc code=end

