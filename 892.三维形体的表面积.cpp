/*
 * @lc app=leetcode.cn id=892 lang=cpp
 *
 * [892] 三维形体的表面积
 */

// @lc code=start
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int res = 0;
        int row = grid.size();
        for (int i = 0; i < row; i++) {
            int col = grid[i].size();
            for (int j = 0; j < col; j++) {
                int cnt = grid[i][j];
                if (cnt == 0) continue;
                res += cnt * 6 - max(cnt-1, 0) * 2;
                if (j + 1 < col) {
                    res -= min(cnt, grid[i][j+1]) * 2;
                }
                if (i + 1 < row) {
                    res -= min(cnt, grid[i+1][j]) * 2;
                }
            }
        }
        return res;
    }
};
// @lc code=end

