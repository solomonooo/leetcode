/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 */

// @lc code=start
class Solution {
public:
    //这题的重点是要分解问题，原始的问题可以分解为针对每行的每个位置计算当前的直方图的最大面积
    //下面的解法和官方题解是反着来的，官方是计算每行的i位置前面有几个连续的1
    //但下面的解法是计算每行的i位置上面有几个连续的1
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), area = 0;
        //height数组，表示当前位置上边有多少个连续的1, n+1是为了计算方便，最后一位是0，为了方便出栈
        vector<int> height(n+1, 0); 
        for (int i = 0; i < m; i++) {
            stack<int> s;
            for (int j = 0; j <= n; j++) {
                //更新height数组
                if (j < n) {
                    height[j] = matrix[i][j] == '1' ? height[j]+1 : 0;
                }
                while (!s.empty() && height[s.top()] >= height[j]) {
                    int h = height[s.top()];
                    s.pop();
                    int w = s.empty() ? j :  j-s.top()-1;
                    area = max(area, w*h);
                }
                s.push(j);
            }
        }
        return area;
    }
};
// @lc code=end

