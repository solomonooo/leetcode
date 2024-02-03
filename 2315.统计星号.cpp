/*
 * @lc app=leetcode.cn id=2315 lang=cpp
 *
 * [2315] 统计星号
 */

// @lc code=start
class Solution {
public:
    int countAsterisks(string s) {
        int ret = 0;
        bool in_flag = false;
        for (size_t i = 0; i < s.length(); i++) {
            if (s[i] == '|') {
                in_flag = !in_flag;
            }else{
                if (!in_flag && s[i] == '*')
                    ret++;
            }
        }
        return ret;
    }
};
// @lc code=end

