/*
 * @lc app=leetcode.cn id=1104 lang=cpp
 *
 * [1104] 二叉树寻路
 */

// @lc code=start
class Solution {
public:
   int get_real(vector<int>& level_cnt, int level, int label) {
        //两数想加和=当前层第一个数+当前层最后一个数
        if (level % 2 == 1) return label;
        return (level_cnt[level-2]+1)+level_cnt[level-1] - label;
    }

    vector<int> pathInZigZagTree(int label) {
        //保存的是每个level最后的计数
        vector<int> level_cnt = {1};
        for (int cur = 1, prev = 1; cur < label; prev *= 2) {
            cur += prev*2;
            level_cnt.push_back(cur);
        }

        int level = level_cnt.size();
        int real_v = get_real(level_cnt, level, label);
        vector<int> path;
        while(level > 1) {
            path.push_back(label);
            real_v /= 2;
            label = get_real(level_cnt, --level, real_v);
        }
        path.push_back(1);
        reverse(path.begin(), path.end());
        return path;
    }
};
// @lc code=end

