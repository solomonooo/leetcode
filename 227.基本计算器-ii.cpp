/*
 * @lc app=leetcode.cn id=227 lang=cpp
 *
 * [227] 基本计算器 II
 */

// @lc code=start
class Solution {
public:
    int64_t getNum(string& s, int& idx) {
        int64_t val = 0, n = s.length();
        while (idx < n && s[idx] == ' ') idx++;
        while (idx < n && s[idx] != ' ') {
            if (s[idx] < '0' || s[idx] > '9') break;
            val = val * 10 + s[idx] - '0';
            idx++;
        }
        return val;
    }

    char getOp(string& s, int& idx) {
        int n = s.length();
        while (idx < n && s[idx] == ' ') idx++;
        if (idx == n) return '\0';
        return  s.at(idx++);
    }

    //核心思想分为几部分：
    //1. 怎么识别数字  
    //2. 怎么识别符号
    //3. 怎么处理op优先级，因为没有括号，所以其实简单的把*/先计算就好
    int calculate(string s) {
        int idx = 0, n = s.length();
        vector<int64_t> vec; 
        vec.push_back(getNum(s, idx));
        char preSign = '+';
        while (idx < n && preSign != '\0') {
            preSign = getOp(s, idx);
            int64_t right = getNum(s, idx);
            switch (preSign) {
                case '+': 
                    vec.push_back(right);
                    break;
                case '-':
                    vec.push_back(-right);
                    break;
                case '*':
                    vec.back() = vec.back()*right;
                    break;
                case '/':
                    vec.back() = vec.back() / right;
                    break;
                default:
                    break;
            }
        }
        int64_t res = 0;
        for (auto& v : vec) res += v;
        return res;
    }

    int calculate2(string s) {
        vector<int> stk;
        char preSign = '+';
        int num = 0;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            if (isdigit(s[i])) {
                num = num * 10 + int(s[i] - '0');
            }
            if (!isdigit(s[i]) && s[i] != ' ' || i == n - 1) {
                switch (preSign) {
                    case '+':
                        stk.push_back(num);
                        break;
                    case '-':
                        stk.push_back(-num);
                        break;
                    case '*':
                        stk.back() *= num;
                        break;
                    default:
                        stk.back() /= num;
                }
                preSign = s[i];
                num = 0;
            }
        }
        return accumulate(stk.begin(), stk.end(), 0);
    }
};
// @lc code=end

