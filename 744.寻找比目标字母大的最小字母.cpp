/*
 * @lc app=leetcode.cn id=744 lang=cpp
 *
 * [744] 寻找比目标字母大的最小字母
 */

// @lc code=start
class Solution {
public:
    char nextGreatestLetterEx(vector<char>& letters, char target) {
        auto iter = find_if(letters.begin(), letters.end(), [&](auto& a){
            return a > target;
        });
        return iter == letters.end() ? letters[0] : *iter;
    }

    char nextGreatestLetter(vector<char>& letters, char target) {
        if (target >= letters.back()) return letters[0];
        return *upper_bound(letters.begin(), letters.end() -1, target);
    }

};
// @lc code=end

