/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
class Solution {
public:
    bool check(vector<bool>& vec, char c) {
        if (c == '.') return true;
        int v = c - '0';
        if(vec[v-1]) return false;
        vec[v-1] = true;
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            vector<bool> row_total(9, false);
            vector<bool> col_total(9, false);
            vector<bool> other_total(9, false);
            for (int j = 0; j < 9; j++) {
                if (!check(row_total, board[i][j])) return false;
                if (!check(col_total, board[j][i])) return false;
                if (!check(other_total, board[3*(i/3)+j/3][3*(i%3)+(j%3)])) return false;
            }
        }
        return true;
    }
};
// @lc code=end

