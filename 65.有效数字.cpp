/*
 * @lc app=leetcode.cn id=65 lang=cpp
 *
 * [65] 有效数字
 */

// @lc code=start
class Solution {
public:
    bool isEPower(string& s, int start) {
        int n = s.length();
        if (start <= 1 || start >= n) return false;
        for (int i = start; i < n; i++) {
            if (s[i] == '+' || s[i] == '-') {
                if (i != start || i + 1 == n) return false;
            } else if (s[i] < '0' || s[i] > '9') {
                return false;
            }
        }
        return true;
    }

    bool isNumber2(string s) {
        if (s.empty()) return false;
        int decimal_point = -1;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'e' || s[i] == 'E') {
                if (i == 0 || s[i-1] == '+' || s[i-1] == '-') return false;
                return isEPower(s, i+1);
            } else if (s[i] == '+' || s[i] == '-') {   //符号必须在第一位
                if (i != 0 || i+1==s.length()) return false;
            } else if (s[i] == '.') {   //小数点只能出现一次
                if (decimal_point >= 0) return false;
                //前后必须要有一个数字
                bool front = i > 0 ? (s[i-1] >= '0' && s[i-1] <= '9') : false;
                bool back = i+1 < s.length() ? (s[i+1] >= '0' && s[i+1] <= '9') : false;
                if (!front && !back) return false;
                decimal_point = i;
            } else if (s[i] < '0' || s[i] > '9') {
                return false;
            }
        }
        return true;
    }

    enum State {
        STATE_INITIAL,
        STATE_INT_SIGN,     //有符号
        STATE_INTEGER,      //整数部分
        STATE_POINT,        //前面有整数的小数点
        STATE_POINT_WITHOUT_INT,    //前面无整数的小数点
        STATE_FRACTION,     //小数部分
        STATE_EXP,
        STATE_EXP_SIGN,
        STATE_EXP_NUMBER
    };

    enum CharType {
        CHAR_NUMBER,
        CHAR_EXP,
        CHAR_POINT,
        CHAR_SIGN,
        CHAR_ILLEGAL
    };

    CharType toCharType(char ch) {
        if (ch >= '0' && ch <= '9') {
            return CHAR_NUMBER;
        } else if (ch == 'e' || ch == 'E') {
            return CHAR_EXP;
        } else if (ch == '.') {
            return CHAR_POINT;
        } else if (ch == '+' || ch == '-') {
            return CHAR_SIGN;
        } else {
            return CHAR_ILLEGAL;
        }
    }

    bool isNumber(string s) {
        unordered_map<State, unordered_map<CharType, State>> transfer{
            {
                STATE_INITIAL, {
                    {CHAR_NUMBER, STATE_INTEGER},           //数字开头，进入整数状态
                    {CHAR_SIGN, STATE_INT_SIGN},            //符号开头，进入整数符号状态
                    {CHAR_POINT, STATE_POINT_WITHOUT_INT}   //小数点开头，进入无整数位小数点状态
                }
            },
            {
                STATE_INT_SIGN, {
                    {CHAR_NUMBER, STATE_INTEGER},          
                    {CHAR_POINT, STATE_POINT_WITHOUT_INT}
                }
            },
            {
                STATE_INTEGER, {
                    {CHAR_NUMBER, STATE_INTEGER},
                    {CHAR_POINT, STATE_POINT},
                    {CHAR_EXP, STATE_EXP}
                }
            },
            {
                STATE_POINT_WITHOUT_INT, {
                    {CHAR_NUMBER, STATE_FRACTION}
                }
            },
            {
                STATE_POINT, {
                    {CHAR_NUMBER, STATE_FRACTION},
                    {CHAR_EXP, STATE_EXP}
                }
            },
            {
                STATE_FRACTION, {
                    {CHAR_NUMBER, STATE_FRACTION},
                    {CHAR_EXP, STATE_EXP}
                }
            },
            {
                STATE_EXP, {
                    {CHAR_SIGN, STATE_EXP_SIGN},
                    {CHAR_NUMBER, STATE_EXP_NUMBER}
                }
            },
            {
                STATE_EXP_SIGN, {
                    {CHAR_NUMBER, STATE_EXP_NUMBER}
                }
            },
            {
                STATE_EXP_NUMBER, {
                    {CHAR_NUMBER, STATE_EXP_NUMBER}
                }
            }
        };

        State st = STATE_INITIAL;
        for (int i = 0; i < s.length(); i++) {
            CharType t = toCharType(s[i]);
            auto iter = transfer[st].find(t);
            if (iter == transfer[st].end()) return false;
            st = iter->second;
        }
        return st == STATE_INTEGER || st == STATE_POINT || st == STATE_FRACTION || st == STATE_EXP_NUMBER;
    }
};
// @lc code=end

