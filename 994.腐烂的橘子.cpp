/*
 * @lc app=leetcode.cn id=994 lang=cpp
 *
 * [994] 腐烂的橘子
 */

// @lc code=start
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int fresh_cnt = 0, time = 0, m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int val = grid[i][j];
                if (val == 1) {
                    fresh_cnt++;
                }else if (val == 2) {
                    q.emplace(i, j);
                }
            }
        }
        while (!q.empty() && fresh_cnt > 0) {
            int s = q.size();
            for (int k = 0; k < s; k++) {
                auto [i, j] = q.front();
                q.pop();
                if (i > 0 && grid[i-1][j] == 1) {
                    q.emplace(i-1, j);
                    grid[i-1][j] = 2;
                    fresh_cnt--;
                }
                if (i+1 < m && grid[i+1][j] == 1) {
                    q.emplace(i+1, j);
                    grid[i+1][j] = 2;
                    fresh_cnt--;
                }
                if (j > 0 && grid[i][j-1] == 1) {
                    q.emplace(i, j-1);
                    grid[i][j-1] = 2;
                    fresh_cnt--;
                }
                if (j+1 < n && grid[i][j+1] == 1) {
                    q.emplace(i, j+1);
                    grid[i][j+1] = 2;
                    fresh_cnt--;
                }
            }
            time++;
        }
        return fresh_cnt > 0 ? -1 : time;
    }
};
// @lc code=end

