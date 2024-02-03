/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 */

// @lc code=start
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int m = words.size(), n = words[0].length();
        //i代表s的n种划分方式，s按照n的大小划分区间(0+x*n, 1+x*n, ...)
        for (int i = 0; i < n && i+m*n <= s.length(); i++) {
            unordered_map<string, int> differ;
            //初始化，用计数为0代表命中了words里面的词
            //先把滑动窗口内的词都加进去，然后去掉words里面的词（表示命中）
            for (int j = 0; j < m; j++) {
                ++differ[s.substr(i+j*n, n)];
            }
            for (auto& v : words) {
                if (--differ[v] == 0) {
                    differ.erase(v);
                }
            }

            for (int start = i; start < s.length()-m*n+1; start += n) {
                if (start != i) {
                    //滑动窗口移动了，载入新的字符串
                    string word = s.substr(start+(m-1)*n, n);
                    if (++differ[word] == 0) {
                        differ.erase(word);
                    }
                    //处理滑出的老字符串
                    word = s.substr(start-n, n);
                    if (--differ[word] == 0) {
                        differ.erase(word);
                    }
                }
                if (differ.empty()) {
                    res.emplace_back(start);
                }
            }
        }
        return res;
    }
};
// @lc code=end

