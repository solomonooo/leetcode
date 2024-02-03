/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start
class Solution {
public:
    //补充说明：
    //1. 可以用位运算来代替bool数组
    // a ^= 1 << x; 可以设置x位（或者取消x位）
    // a &= (a-1) 消除最后一位1
    // a & (-a) 可以获取最后一位1  -a=~b+1
    //2. 解数独最快的解法：舞蹈链算法 + (将数独转换成约束描述，每个格子都可以转成4个约束条件)
    // 如果一个格子的数字确定了， 那矩阵行是唯一的，否则矩阵有9行（每个数字一行，但是最终舞蹈链算法会选择一行）
    typedef vector<vector<bool>> status_arr;
    void dfs(vector<vector<char>>& board, int pos, 
            status_arr& line, status_arr& col, status_arr& block,
            vector<pair<int,int>>& spaces) {
        if (pos == spaces.size()) {
            valid = true;
            return;
        }

        auto [i, j] = spaces[pos];
        //选择空白位置，开始尝试1~9 (实际索引对应0~8)
        for (int digit = 0; digit < 9 && !valid; digit++) {
            //该数字已经被占用
            if (line[i][digit] || col[j][digit] || block[i/3*3+j/3][digit])
                continue;
            line[i][digit] = col[j][digit] = block[i/3*3+j/3][digit] = true;
            board[i][j] = digit+'0'+1;
            dfs(board, pos+1, line, col, block, spaces);
            line[i][digit] = col[j][digit] = block[i/3*3+j/3][digit] = false;
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        status_arr line(9, vector<bool>(9, false));
        status_arr column(9, vector<bool>(9, false));
        status_arr block(9, vector<bool>(9, false));
        vector<pair<int,int>> spaces;
        valid = false;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    spaces.emplace_back(i, j);
                }else{
                    int v = board[i][j]- '0'-1;
                    line[i][v] = column[j][v] = block[(i/3)*3 + j/3][v] = true;
                }
            }
        }
        dfs(board, 0, line, column, block, spaces);
    }

private:
    bool valid = false;
    
};
// @lc code=end

