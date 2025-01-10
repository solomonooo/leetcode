/*
 * @lc app=leetcode.cn id=2602 lang=cpp
 *
 * [2602] 使数组元素全部相等的最少操作次数
 */

// @lc code=start
class Solution {
public:
    int find_idx(vector<int>& nums, int val) {
        int left = 0, right = nums.size()-1;
        while (left < right) {
            int mid = (left+right)/2;
            if (nums[mid] == val) return mid;
            if (nums[mid] < val) {
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return left;
    }

    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        int n = nums.size(), m = queries.size();
        sort(nums.begin(), nums.end());
        vector<long long> s(n+1, 0);
        for (int i = 0; i < n; i++) {
            s[i+1] = s[i] + nums[i];
        }

        vector<long long> res(m);
        for (int i = 0; i < m; i++) {
            int target = queries[i];
            //long long idx = find_idx(nums, target);
            long long idx = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
            while (idx < n && nums[idx] < target) idx++;
            long long left = idx * target - s[idx];
            long long right = s.back() - s[idx] - (n-idx)*target;
            res[i] = left + right;
        }
        return res;
    }
};
// @lc code=end

