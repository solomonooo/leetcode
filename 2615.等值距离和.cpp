/*
 * @lc app=leetcode.cn id=2615 lang=cpp
 *
 * [2615] 等值距离和
 */

// @lc code=start
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int, vector<int>> dict;
        for (int i = 0; i < nums.size(); i++) {
            dict[nums[i]].push_back(i);
        }

        //关键算法，前缀树，对每个找到的值的vector，计算前缀树来简化求和计算
        //res[i]分为2部分：左边和右边. 这里i代表个数，从1开始，在c++里 i-1=idx
        //左边： (a<i>-a<1>)+(a<i>-a<2>)+...+(a<i>-a<i-1>)
        //      = (i-1)*a<i> - (a<1>+a<2>+...+a<i-1>)
        //      = idx * a<i> - s[idx]
        //右边： (a<i+1>-a<i>)+(a<i+2>-a<i>)+...+(a<n>-a<i>)
        //      = (a<i+1>+a<i_2>+...+a<n>) - (n-i)*a<i>
        //      = (a<i>+a<i+1>+a<i_2>+...+a<n>) - (n-i-1)*a<i>
        //      = (s[n] - s[idx]) - (n-i-1)*a<i>
        //      = s[n] - s[idx] - (n-idx) * a<i>
        vector<long long> res(nums.size());
        for (auto &[_, vec]: dict) {
            int n = vec.size();
            vector<long long> s(n+1, 0);   //idx: 当前i前面所有数的和，不包含自身
            for (int j = 0; j < n; j++) {
                s[j+1] = j > 0 ? s[j]+vec[j] : vec[j];
            }
            for (int j = 0; j < n; j++) {
                long long cur = vec[j];
                long long left = j * cur - s[j];
                long long right = s.back() - s[j] - (n-j) * cur;
                res[cur] = left + right;
            }
        }
        return res;
    }
};
// @lc code=end

