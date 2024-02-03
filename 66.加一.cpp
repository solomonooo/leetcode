/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> output;
        int extra = 1;
        for (int i = digits.size()-1; i >= 0; i--) {
            int cur = digits[i] + extra;
            output.push_back(cur%10);
            extra = cur / 10;
        }
        if (extra > 0) output.push_back(extra);
        reverse(output.begin(), output.end());
        return output;
    }
};
// @lc code=end

