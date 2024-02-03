/*
 * @lc app=leetcode.cn id=2278 lang=cpp
 *
 * [2278] 字母在字符串中的百分比
 */

// @lc code=start
class Solution {
public:
    int percentageLetter(string s, char letter) {
        int l = 0;
        for (auto c : s) {
            if (c == letter) l++;
        }
        cout<<"l = "<<l<<endl;
        return l*100 / s.length();
    }
};
// @lc code=end

