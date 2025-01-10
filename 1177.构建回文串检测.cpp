/*
 * @lc app=leetcode.cn id=1177 lang=cpp
 *
 * [1177] 构建回文串检测
 */

// @lc code=start
class Solution {
public:
   vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        //题目分为2部分：
        //怎么判断回文的改动次数？ 统计字符出现频率的奇偶就行了
        //超时控制
        //          使用前缀和减少计算量
        int n = s.length();
        vector<int> count(n+1); //用来统计奇偶性，每一个位代表一个字符
        for(int i = 0; i < s.length(); i++) {
            count[i+1] = count[i] ^ (1 << (s.at(i) - 'a'));
        }
        vector<bool> res;
        for (auto& vec : queries) {
            int left = vec[0], right = vec[1], k = vec[2];
            int val = count[right+1] ^ count[left];
            int cnt = 0;
            while (val > 0) {
                cnt += (val & 1);
                val = val >> 1;
            }
            res.push_back(cnt / 2 <= k);
        }
        return res;
    }
};
// @lc code=end

