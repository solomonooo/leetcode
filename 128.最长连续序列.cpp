/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set;
        for (const int& num : nums) {
            num_set.insert(num);
        }

        int maxn = 0;
        //不遍历nums的原因是，num_set会帮忙去重
        for (int i : num_set) {
            if (num_set.count(i-1)) continue;   //剪枝，如果前驱存在，不要重复计算了
            int cur = i, len = 1;
            while (num_set.count(cur+1)) {
                cur++;
                len++;
            }
            maxn = max(maxn, len);
        }
        return maxn;
    }
};
// @lc code=end

