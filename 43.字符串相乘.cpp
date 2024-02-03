/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */

// @lc code=start
class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.length(), n = num2.length();
        vector<int> res(m+n, 0);
        for (int i = 0; i < n;i ++) {
            for (int j = 0; j < m; j++) {
                int idx = i + j;
                int cur = (num1[m-j-1]-'0') * (num2[n-i-1]-'0');
                res[idx] += cur;
                while (res[idx] >= 10) {
                    res[idx+1] += res[idx] / 10;
                    res[idx] %= 10;
                    idx++;
                }
            }
        }
        string output;
        for (int i = res.size() -1; i >= 0; i--) {
            if (output.empty() && res[i] == 0) continue;
            output.push_back(res[i] + '0');
        }
        return output.empty() ? "0" : output;
    }
};
// @lc code=end

