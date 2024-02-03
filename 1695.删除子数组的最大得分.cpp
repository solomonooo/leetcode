/*
 * @lc app=leetcode.cn id=1695 lang=cpp
 *
 * [1695] 删除子数组的最大得分
 */

// @lc code=start
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int max = 0, cur_max = 0;
        //key: nums[i]; val: idx
        unordered_map<int, int> m;
        for (int i = 0, start = 0; i < nums.size(); i++) {
            int val = nums[i];
            auto it = m.find(val);
            if (it != m.end()) { 
                for (int j = start; j <= it->second; j++) {
                    cur_max -= nums[j];
                }
                start = std::max(it->second+1, start);
            }
            cur_max += val;
            m[val] = i;
            max = std::max(max, cur_max);
        }
        return max;
    }
};
// @lc code=end

