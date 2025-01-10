/*
 * @lc app=leetcode.cn id=2453 lang=cpp
 *
 * [2453] 摧毁一系列目标
 */

// @lc code=start
class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        unordered_map<int, pair<int, int>> dict;
        int minn = INT_MAX, cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            int idx = nums[i] % space;
            auto it = dict.find(idx);
            if (it == dict.end()) {
                it = dict.emplace(idx, make_pair(nums[i], 1)).first;
            }else{
                it->second.first = min(it->second.first, nums[i]);
                it->second.second++;
            }
            if (cnt == it->second.second) {
                minn = min(minn, it->second.first);
            }else if (cnt < it->second.second) {
                cnt = it->second.second;
                minn = it->second.first;
            }
        }
        return minn;
    }
};
// @lc code=end

