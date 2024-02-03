/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool match(char c1, char c2) {
        if (c1 == '(' && c2 == ')') return true;
        if (c1 == '[' && c2 == ']') return true;
        if (c1 == '{' && c2 == '}') return true;
        return false;
    }

    bool is_left(char c) {
        if (c == '(') return true;
        if (c == '[') return true;
        if (c == '{') return true;
        return false;
    }

    bool isValid(string s) {
        stack<char> sc;
        for (char c : s) {
            if (is_left(c)) {
                sc.push(c);
            }else{
                if (sc.empty() || !match(sc.top(), c)) return false;
                sc.pop();
            }
        }
        return sc.empty();
    }
};
// @lc code=end

