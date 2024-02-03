/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution {
public:
    //无法用dp，因为搜索路径的方向无法确定，无法用一个确定的dp顺序来解决
    bool check(vector<vector<char>>& board, vector<vector<bool>>& visited, int row, int col, string& word, int idx) {
        if (board[row][col] != word[idx]) return false;
        if (idx+1 == word.length()) return true;
        visited[row][col] = true;
        //尝试4个方向
        int m = board.size(), n = board[0].size();
        if (row > 0 && !visited[row-1][col]) {
            if (check(board, visited, row-1, col, word, idx+1)) return true;
        }
        if (col > 0 && !visited[row][col-1]) {
            if (check(board, visited, row, col-1, word, idx+1)) return true;
        }
        if (row+1 < m && !visited[row+1][col]) {
            if (check(board, visited, row+1, col, word, idx+1)) return true;
        }
        if (col+1 < n && !visited[row][col+1]) {
            if (check(board, visited, row, col+1, word, idx+1)) return true;
        }
        visited[row][col] = false;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (check(board, visited, i, j, word, 0)) return true;
            }
        }
        return false;
    }
};
// @lc code=end

