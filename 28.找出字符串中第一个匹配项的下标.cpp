/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */

// @lc code=start
class Solution {
public:
    //kmp算法
    //https://zhuanlan.zhihu.com/p/434013023
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        if (m == 0) return 0;

        //计算模式串的next数组
        vector<int> next(m);
        for (int i = 1, j = 0; i < m; i++) {
            //如果不相等，需要回退
            while (j > 0 && needle[i] != needle[j]) {
                j = next[j-1];
            }
            if (needle[i] == needle[j]) j++;
            next[i] = j;   
        }
        //利用next数组匹配原串
        for (int i = 0, j = 0; i < n; i++) {
            while (j > 0 && haystack[i] != needle[j]) {
                j = next[j-1];
            }
            if (haystack[i] == needle[j]) j++;
            if (j == m) return i-m+1;
        }
        return -1;
    }
};
// @lc code=end

