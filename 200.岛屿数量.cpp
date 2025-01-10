/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        visited[i][j] = false;
        if (i > 0 && visited[i-1][j] && grid[i-1][j] == '1') dfs(grid, visited, i-1, j);
        if (i+1 < m && visited[i+1][j] && grid[i+1][j] == '1') dfs(grid, visited, i+1, j);
        if (j > 0 && visited[i][j-1] && grid[i][j-1] == '1') dfs(grid, visited, i, j-1);
        if (j+1 < n && visited[i][j+1] && grid[i][j+1] == '1') dfs(grid, visited, i, j+1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, true));
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] && grid[i][j] == '1') {
                    dfs(grid, visited, i, j);
                    ans++;
                }
            }
        }
        return ans;
     }
};
// @lc code=end

