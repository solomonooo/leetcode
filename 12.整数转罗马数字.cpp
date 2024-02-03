/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */

// @lc code=start
class Solution {
public:
    string intToRoman(int num) {
        vector<string> m = {"", "M", "MM", "MMM"};
        vector<string> h = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        vector<string> t = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        vector<string> o = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        string res;
        res += m[num / 1000];
        num = num % 1000;
        res += h[num / 100];
        num = num % 100;
         res += t[num / 10];
        num = num % 10;
        return res + o[num];
    }
};
// @lc code=end

