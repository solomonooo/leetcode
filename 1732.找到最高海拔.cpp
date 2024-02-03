/*
 * @lc app=leetcode.cn id=1732 lang=cpp
 *
 * [1732] 找到最高海拔
 */

// @lc code=start
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0, max = 0;
        for (int i : gain) {
            ans += i;
            max = std::max(max, ans);
        }
        return max;
    }
};
// @lc code=end

