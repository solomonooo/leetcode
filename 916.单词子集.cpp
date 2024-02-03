/*
 * @lc app=leetcode.cn id=916 lang=cpp
 *
 * [916] 单词子集
 */

// @lc code=start=
class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> res;
        map<char, int> sign;
        for (auto& s : words2) {
            map<char, int> sg;
            for (char c : s) {
                sg[c]++;
            }
            for (auto& kv : sg) {
                sign[kv.first] = max(sign[kv.first], kv.second);
            }
        }
        for (auto& s : words1) {
            bool pass = true;
            for (auto& kv : sign) {
                char c = kv.first;
                int cnt = count(s.begin(), s.end(), c);
                if (cnt < kv.second) {
                    pass = false;
                    break;
                }
            }
            if (pass)
                res.emplace_back(s);
        }
        return res;
    }
};
// @lc code=end

