/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
class Solution {
public:
   int subarraySum(vector<int>& nums, int k) {
        //mp记录某个prefix值出现的次数
        unordered_map<int, int> mp;
        mp[0] = 1;
        int cnt = 0, prefix = 0;
        for (int i : nums) {
            prefix += i;
            auto it = mp.find(prefix - k);
            if (it != mp.end()) {
                cnt += it->second;
            }
            mp[prefix]++;
        }
        return cnt;
    }
};
// @lc code=end

