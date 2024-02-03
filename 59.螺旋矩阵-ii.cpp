/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution {
    public:
        vector<vector<int> > generateMatrix(int n) {
            vector<vector<int> > res( n, vector<int>(n) );
            int left, right, top, down, index;
            left = top = index = 0;
            right = down = n-1;
            while(left <= right && top <= down){
                for(int i = left; i <= right; i++)
                    res[top][i] = ++index;
                top++;
                for(int i = top; i <= down; i++)
                    res[i][right] = ++index;
                right--;
                for(int i = right; i >= left; i--)
                    res[down][i] = ++index;
                down--;
                for(int i = down; i >= top; i--)
                    res[i][left] = ++index;
                left++;
            }
            return res;
        }
};
// @lc code=end

