/*
 * @lc app=leetcode.cn id=2124 lang=cpp
 *
 * [2124] 检查是否所有 A 都在 B 之前
 */

// @lc code=start
class Solution {
public:
    bool checkString(string s) {
        int last_a = -1, first_b = INT_MAX;
        for (int i = 0; i < s.length(); i++) {
            if (s.at(i) == 'a') {
                last_a = i;
            }else{
                first_b = min(first_b, i);
            }
        }
        return last_a < first_b;
    }
};
// @lc code=end

