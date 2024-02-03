/*
 * @lc app=leetcode.cn id=836 lang=cpp
 *
 * [836] 矩形重叠
 */

// @lc code=start
class Solution {
public:

    //rec1: 0, x1; 1, y1; 2, x2; 3, y2
    //rec2: 0, x3; 1, y3; 2, x4; 3, y4

    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        
        return !(rec1[2] <= rec2[0] || rec2[2] <= rec1[0]) && 
            !(rec1[3] <= rec2[1] || rec2[3] <= rec1[1]);
    }
};
// @lc code=end

