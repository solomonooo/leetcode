/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
    void generateParenthesis(vector<string>& output, string cur, int left, int right, int n) {
        if (left < n) {
            generateParenthesis(output, cur+'(', left+1, right, n);
        }
        if (left > right) {
            if (right + 1 == n) {
                output.emplace_back(cur+')');
            }else{
                generateParenthesis(output, cur+')', left, right+1, n);
            }
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generateParenthesis(res, "", 0, 0, n);
        return res;
    }
};
// @lc code=end

