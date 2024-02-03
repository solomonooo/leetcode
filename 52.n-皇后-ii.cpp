/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N 皇后 II
 */

// @lc code=start
class Solution {
public:
    int totalNQueens(int n) {
        int cnt = 0;
        solve(cnt, n, 0, 0, 0, 0);
        return cnt;
    }

    void solve(int& cnt, int n, int row, int col, int left_diagonal, int right_diagonal) {
        //bit=0表示可用，位运算后avail的bit=1表示可用
        int avail = ((1<<n)-1) & (~(col | left_diagonal | right_diagonal));
        for (int i = avail; i > 0; i &= i-1) {
            if (row + 1 == n) {
                cnt++;
            }else{
                int flag = i & (-i);
                solve(cnt, n, row+1, col | flag, (left_diagonal | flag) >> 1, (right_diagonal | flag) << 1);
            }  
        }
    }
};
// @lc code=end

