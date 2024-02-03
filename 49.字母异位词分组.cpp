/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:
    string sort(string& s){
        vector<int> flag(26, 0);
        for(char c : s)
            flag[c-'a']++;
        string res(s.length(), 'a');
        int pos = 0;
        for(int i = 0; i < flag.size(); i++)
            for(int j = 0; j < flag[i]; j++)
                res[pos++] += i;
        return res;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, int> m;
        for(string s : strs) {
            auto key = sort(s);
            auto iter = m.find(key);
            if (iter != m.end())
                res[iter->second].push_back(s);
            else{
                res.push_back(vector<string>(1, s));
                m[key] = res.size()-1;
            }
        }
        return res;
    }
};
// @lc code=end

