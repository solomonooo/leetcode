/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start
class Solution {
public:
    int numDecodings(string s) {
        if(s.empty() || s[0] == '0')
            return 0;

        int r1 = 1, r2 = 1, cur = 1;
        for(int i = 1; i < s.length(); i++){
            cur = s[i] != '0' ? r1 : 0;
            if(s[i-1] == '1' || (s[i-1] == '2' && s[i] < '7')){
                cur += r2;
            }
            r2 = r1;
            r1 = cur;
        }

        return cur;
    }

    int numDecodings2(string s) {
        int n = s.size();
        vector<int> f(n + 1);
        f[0] = 1;
        for (int i = 1; i <= n; ++i) {
            //使用一个字符解码
            if (s[i - 1] != '0') {
                f[i] = f[i - 1];
            }
            //使用2个字符解码
            if (i > 1) {
                if(s[i-2] == '1' || (s[i-2] == '2' && s[i-1] < '7')){
                    f[i] += f[i - 2];
                }
            }
        }
        return f[n];
    }
};
// @lc code=end

