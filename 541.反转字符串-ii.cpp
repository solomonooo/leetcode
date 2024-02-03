/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */

// @lc code=start
class Solution {
public:
    /*
    string reverseStr(string s, int k) {
        stack<char> sc;
        for(int i = 0; i < s.length(); i++) {
            if (sc.size() < k) {
                sc.push(s[i]);
            } else {
                //reverse
                i -= k;
                while (sc.size() > 0) {
                    s[i++] = sc.top();
                    sc.pop();
                }

                i += k-1;
            }
        }
        for (int i = s.length() - sc.size(); sc.size() > 0; i++){
            s[i] = sc.top();
            sc.pop();
        }
        return s;
    }
    */

    string reverseStr(string s, int k) {
        int n = s.length();
        for (int i = 0; i < n; i += 2*k) {
            reverse(s.begin() + i, s.begin() + min(n, i + k));
        }
        return s;
    }




};
// @lc code=end

