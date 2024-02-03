/*
 * @lc app=leetcode.cn id=1340 lang=cpp
 *
 * [1340] 跳跃游戏 V
 */

// @lc code=start
class Solution {
public:

    /*
        dp[i] = max(dp[i-d], dp[i+d]) + 1
    */
    int maxJumps2(vector<int>& arr, int d) {
        multimap<int, int> m;
        for (int i = 0; i < arr.size(); i++) {
            m.emplace(arr[i], i);
        }

        vector<int> dp(arr.size(), 1);
        int len = arr.size();
        for (auto it = m.begin(); it != m.end(); ++it) {
            int idx = it->second;
            int val = it->first;
            for (int j = idx - 1, max = val; j >= 0 && j >= idx - d; j--) {
                if (arr[j] > max) {
                    dp[j] = std::max(dp[j], dp[idx]+1);
                    max = arr[j];
                }
            }
            for (int j = idx + 1, max = val; j < len && j <= idx + d; j++) {
                if (arr[j] > max) {
                    dp[j] = std::max(dp[j], dp[idx]+1);
                    max = arr[j];
                }
            }
        }

        int ans = 1;
        for (int i : dp) {
            ans = std::max(ans, i);
        }
        return ans;
    }

    //answer 2
    void dfs(vector<int>& arr, vector<int>& dp, int idx, int d) {
        if (dp[idx] != -1) return;

        dp[idx] = 1;
        for (int j = idx - 1; j >= 0 && j >= idx - d && arr[idx] > arr[j]; j--) {
            dfs(arr, dp, j, d);
            dp[idx] = std::max(dp[idx], dp[j]+1);
        }
        for (int j = idx + 1; j < arr.size() && j <= idx + d && arr[idx] > arr[j]; j++) {
            dfs(arr, dp, j, d);
            dp[idx] = std::max(dp[idx], dp[j]+1);
        }
    }

    int maxJumps(vector<int>& arr, int d) {
        vector<int> dp(arr.size(), -1);
        for (int i = 0; i < arr.size(); i++) {
            dfs(arr, dp, i, d);
        }

        return *max_element(dp.begin(), dp.end());
    }



 //   [6,4,14,6,8,13,9,7,10,6,12]

//    [2,1, 3,1,2, 3,2,1, 3,1, 4]


};
// @lc code=end

