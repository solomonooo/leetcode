/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */

// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        if (path.length() == 1) return path;
        stack<string> s;
        for (int left = 1, right = 1; left < path.length(); left = right+1) {
            right = left;
            while (right < path.length() && path[right] != '/') right++;
            if (left == right) continue;
            auto p = path.substr(left, right-left);
            if (p == ".") {
                // do nothing
            }else if (p == "..") {
                if (!s.empty()) s.pop();
            }else{
                s.push(move(p));
            }
        }
        string res;
        while(!s.empty()) {
            res = res.empty() ? s.top() : (s.top()+'/'+res);
            s.pop();
        }
        return "/" + res;
    }
};
// @lc code=end

