/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
class Solution {
public:
    string int2string(vector<int>& vec) {
        string res = to_string(vec[0]);
        for (size_t i = 1; i < 4; i++) {
            res += "." + to_string(vec[i]);
        }
        return res;
    }

    void restoreIpAddress(string& s, size_t offset, int cnt, vector<int>& cur, vector<string>& res) {
        if (cnt == 4) {
            if (offset == s.length()) {
                res.push_back(int2string(cur));
            }
            return;
        }else if (offset == s.length()) {
            return;
        }

        int val = 0;
        for (size_t i = offset; i < s.length() && i < offset + 3; i++) {
            val = val * 10 + (s.at(i) - '0');
            if (val <= 255) {
                cur[cnt] = val;
                restoreIpAddress(s, i+1, cnt+1, cur, res);
            }
            if (val == 0 || val > 255) break;
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        vector<int> cur(4);
        restoreIpAddress(s, 0, 0, cur, res);
        return res;
    }
};
// @lc code=end

