/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        static unordered_map<char, string> m = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        if (digits.length() == 0) return {};
        vector<string> res; 
        for (char c : m[digits.at(0)]) {
            res.emplace_back(1, c);
        } 
        for (int i = 1; i < digits.size(); i++) {
            vector<string> tmp;
            for (auto& s : res) {
                for (char c : m[digits.at(i)]) {
                    tmp.emplace_back(s+c);
                }
            }
            res.swap(tmp);
        }
        return res;
    }
};
// @lc code=end

