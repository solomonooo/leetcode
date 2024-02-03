/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */

// @lc code=start
class Solution {
public:
    string countAndSay(int n) {
        vector<int> vec = {1};
        for (int i = 1; i < n; i++) {
            vector<int> tmp;
            for (int j = 0; j < vec.size();j++) {
                int v = vec[j], cnt = 1;
                while(j+1 < vec.size() && vec[j+1] == v) {
                    j++;
                    cnt++;
                }
                tmp.push_back(cnt);
                tmp.push_back(v);
            }
            tmp.swap(vec);
        }
        //queue to string
        string res;
        for (int i : vec) {
            res += '0' + i;
        }
        return res;
    }
};
// @lc code=end

