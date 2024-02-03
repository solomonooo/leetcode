/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
class Solution {
public:
    enum STATUS {
        START = 0,
        SIGN,
        NUM,
        END
    };

    int idx(char c) {
        if (c == ' ') return 0;
        if (c == '+' || c == '-') return 1;
        if (c >= '0' && c <= '9') return 2;
        return 3;
    }

    int myAtoi(string s) {
        //我们需要写一个状态机
        //0, ' ';1, +-; 2, 0~9; 3, others;
        static map<STATUS, vector<STATUS>> state_map = {
            {START, {START, SIGN, NUM, END}},
            {SIGN, {END, END, NUM, END}},
            {NUM, {END, END, NUM, END}}
        };

        STATUS state = START;
        int64_t ret = 0;
        int sign = 1;
        for (int i = 0; i < s.length(); i++) {
            char c = s.at(i);
            state = state_map[state][idx(c)];
            if (state == END) break;
            if (c == '+' || c == '-') {
                sign = c == '+' ? 1 : -1;
            } else if (c >= '0' && c <= '9') {
                ret = ret*10+(c-'0');
                if (ret >= INT_MAX) break;
            }
        }
        if (sign != 0) ret = sign * ret;
        return ret > INT_MAX ? INT_MAX : (ret < INT_MIN ? INT_MIN : ret);
    }
};
// @lc code=end

