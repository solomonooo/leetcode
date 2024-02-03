/*
 * @lc app=leetcode.cn id=2564 lang=cpp
 *
 * [2564] 子字符串异或查询
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        //key: val in quer
        //val: first, answer
        unordered_map<int, pair<int, int>> m;
        if (auto pos = s.find('0'); pos != string::npos)
            m[0] = {pos, pos};
        for (int i = 0, n = s.length(); i < n; i++) {
            if (s[i] == '0') continue;
            int val = 0;
            for (int j = i; j < min(i+30, n); j++) {
                val = val << 1 | (s[j] & 1);
                if (!m.count(val))
                    m[val] = {i, j};
            }
        }

        vector<vector<int>> res;
        for (const auto& q : queries) {
            auto it = m.find(q[0] ^ q[1]);
            if (it != m.end())
                res.push_back({it->second.first, it->second.second});
            else
                res.push_back({-1, -1});
        }

        return res;
    }


    /*
    string to2(int val) {
        string s;
        while (val > 0) {
            s.push_back('0'+val%2);
            val /= 2;
        }
        std::reverse(s.begin(), s.end());
        return s;
    }

    vector<int> substringXorQueries(const string& s, int val) {
        string dst = val == 0 ? "0" : to2(val);
        int pos = s.find(dst);
        if (pos == string::npos) return {-1, -1};
        return {pos, pos+(int)dst.length()-1};
    }

    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        vector<vector<int>> res;
        for (const auto& q : queries) {
            int val = q[0] ^ q[1];
            res.emplace_back(substringXorQueries(s, val));
        }
        return res;
    }
    */
};
// @lc code=end

