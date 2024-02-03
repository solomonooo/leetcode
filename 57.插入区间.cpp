/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 */

// @lc code=start
class Solution {
public:
    //问题的关键在于，如何判断交集
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> output;
        bool flag = false;
        int left = newInterval[0], right = newInterval[1]; 
        for (auto& val : intervals) {
            if (val[1] < left) {    //没有交集，在左边，直接插入
                output.push_back(val);
            }else if (val[0] > right) { //没有交集，在右边，先插入新区间，再插入
                if (!flag) output.push_back({left, right});
                output.push_back(val);
                flag = true;
            }else{  //有交集
                left = min(left, val[0]);
                right = max(right, val[1]);
            }
        }
        if (!flag) output.push_back({left, right});
        return output;
    }
};
// @lc code=end

