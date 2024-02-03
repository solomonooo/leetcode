/*
 * @lc app=leetcode.cn id=1323 lang=cpp
 *
 * [1323] 6 和 9 组成的最大数字
 */

// @lc code=start
class Solution {
public:
    /*
    int maximum69Number (int num) {
        if (num < 10) {
            return max(num, 9);
        }
        int right = num%10;
        int left = maximum69Number(num/10) * 10;
        return left + right == num ? left + 9 : left + right;        
    }
    */

    int maximum69Number (int num) {
        auto s = to_string(num);
        for (auto& c : s) {
            if (c == '6') {
                c = '9';
                break;
            }
        }
        return stoi(s);
    }
};
// @lc code=end

