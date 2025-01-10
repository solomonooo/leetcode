/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.length();
        if (len <= 1 || numRows == 1) return s;
        int cycle = 2*numRows-2;
        string ret;
        ret.reserve(len);
        for (int i = 0; i < numRows; i++) {
            for (int j = i; j < len; j+=cycle) {
                ret.push_back(s[j]);
                if (i > 0 && i < numRows-1 && j+cycle-2*i < len) {
                    ret.push_back(s[j+cycle-2*i]);
                }
            }
        }
        return ret;
    }
};


// @lc code=end

