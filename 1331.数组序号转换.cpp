/*
 * @lc app=leetcode.cn id=1331 lang=cpp
 *
 * [1331] 数组序号转换
 */

// @lc code=start
class Solution {
public:
    vector<int> arrayRankTransform1(vector<int>& arr) {
        //key: arr[i]; value: idx in vec
        multimap<int, int> m;
        for (int i = 0; i < arr.size(); i++) {
            m.emplace(arr[i], i);
        }

        vector<int> ans(arr.size());
        int idx = 0;

        for (auto it = m.begin(); it != m.end(); ++it) {
            if (idx == 0) {
                idx++;
            }else{
                auto p_it = prev(it);
                if (p_it->first != it->first)
                    idx++;
            }
            ans[it->second] = idx;
        }
        return ans;
    }

    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> vec = arr;
        sort(vec.begin(), vec.end());
        unordered_map<int, int> m;
        for (int i : vec) {
            if (m.count(i) == 0)
                m[i] = m.size() + 1;
        }
        vector<int> ans(arr.size());
        for (int i = 0; i < arr.size(); i++) {
            ans[i] = m[arr[i]];
        }
        return ans;
    }


};
// @lc code=end

