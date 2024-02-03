/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> output;
        vector<string> queens(n, string(n, '.'));
        solve(output, queens, n, 0, 0, 0, 0);
        return output;
    }

    void solve(vector<vector<string>>& output, vector<string>& queens, int n, int row, int col, int left_diagonal, int right_diagonal) {
        if (row == n) {
            output.push_back(queens);
        }else{
            //bit=0表示可用，位运算后avail的bit=1表示可用
            int avail = ((1<<n)-1) & (~(col | left_diagonal | right_diagonal));
            for (int i = avail; i > 0; i &= i-1) {
                int flag = i & (-i);
                int idx = __builtin_ctz(flag);
                queens[row][idx] = 'Q';
                solve(output, queens, n, row+1, col | flag, (left_diagonal | flag) >> 1, (right_diagonal | flag) << 1);
                queens[row][idx] = '.';
            }
        }
    }
};
// @lc code=end

