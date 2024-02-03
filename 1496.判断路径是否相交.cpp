/*
 * @lc app=leetcode.cn id=1496 lang=cpp
 *
 * [1496] 判断路径是否相交
 */

// @lc code=start
class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int, int>> s = {{0,0}};
        int x = 0, y = 0;
        for (char c : path) {
            if (c == 'N') y++;
            else if (c == 'S') y--;
            else if (c == 'E') x++;
            else x--;
            auto res = s.emplace(x, y);
            if (res.second == false) return true;
        }
        return false;
    }
};
// @lc code=end

