/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        //拍完序之后，按顺序插入的话，后面的start一定>=前面区间的start,所以只存在2种情况：
        //1. 存在交集, 后面的start<=前面的end; 2.没有交集
        for (auto& val : intervals) {
            int left = val[0], right = val[1];
            if (!res.empty() && res.back()[1] >= left) {
                res.back()[1] = max(res.back()[1], right);
            }else{
                res.push_back({left, right});
            }
        }
        return res;
    }
};
// @lc code=end

