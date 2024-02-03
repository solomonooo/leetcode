/*
 * @lc app=leetcode.cn id=68 lang=cpp
 *
 * [68] 文本左右对齐
 */


// @lc code=start
class Solution {
public:
    string generate(vector<string>& words, int left, int right, int space, bool lastline) {
        int num = right - left + 1;
        string res;
        if (num == 1) {
            res += words[left];
            res.append(space, ' ');
        }else{
            int avg_space = lastline ? 1 : space / (num-1);
            int extra_space = lastline ? 0 : space - (num-1) * avg_space;
            for (int i = left; i <= right; i++) {
                res += words[i];
                if (i < right) {
                    int cur_space = 0;
                    if (lastline) {
                        cur_space = 1;
                    } else{
                        cur_space = avg_space + (extra_space > 0 ? 1 : 0);
                        extra_space--;
                    }
                    res.append(cur_space, ' ');
                    space -= cur_space;
                }
            }
            if (space > 0) res.append(space, ' ');
        }
        return res;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int n = words.size();
        //left当前行的左边界，right-1当前行的右边界
        for (int left = 0, right = 0; left < n;) {
            int cur_len = 0;
            while (right<n && cur_len + words[right].length() + right - left <= maxWidth) {
                cur_len += words[right++].length();
            }
            if (right < n)
                res.push_back(generate(words, left, right-1, maxWidth-cur_len, false));
            else
                res.push_back(generate(words, left, right-1, maxWidth-cur_len, true));
            left = right;
            right = left;
        }
        return res;
    }
};
// @lc code=end

