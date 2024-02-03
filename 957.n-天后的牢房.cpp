/*
 * @lc app=leetcode.cn id=957 lang=cpp
 *
 * [957] N 天后的牢房
 */

// @lc code=start
class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        unsigned char c = 0;
        for (int i : cells) {
            c = (c << 1) | i;
        }

        unordered_map<unsigned char, int> m; //key: current val, 当前的计算轮
        //我们的目标是计算n=0时候的c
        while (n > 0) {
            auto iter = m.find(c);
            if (iter != m.end()) {
                int tmp = iter->second - n;
                n = n % tmp;
            }
            m[c] = n--;
            if (n >= 0)
                c = (~((c << 1) ^ (c >> 1))) & 0x7E; //7E=0x01111110
        }

        vector<int> res(cells.size());
        for (int i = 0; i < cells.size(); i++) {
            res[cells.size() - i - 1] = c & 1;
            c = c >> 1;
        }
        return res;
    }
};
// @lc code=end

