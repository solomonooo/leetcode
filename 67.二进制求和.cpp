/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length()-1, j = b.length()-1;
        int c = 0;
        string res;
        while(i >= 0 || j >= 0 || c > 0){
            c += i >= 0 ? a[i--]-'0' : 0;
            c += j >= 0 ? b[j--]-'0' : 0;
            res = char(c%2 + '0') + res;
            c /= 2;
        }
        return res;
    }
};
// @lc code=end

