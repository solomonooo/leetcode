/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        for (int i = 0; i + 3 < n; i++) {
            int a = nums[i];
            if (i > 0 && nums[i] == nums[i-1]) continue;
            if ((int64_t)a+nums[i+1]+nums[i+2]+nums[i+3] > target) break;
            else if ((int64_t)a+nums[n-3]+nums[n-2]+nums[n-1] < target) continue;
            for (int j = i+1; j + 2 < n; j++) {
                int b = nums[j];
                if (j > i+1 && nums[j] == nums[j-1]) continue;
                if ((int64_t)a+b+nums[j+1]+nums[j+2] > target) break;
                else if ((int64_t)a+b+nums[n-2]+nums[n-1] < target) continue;
                for (int left = j+1, right = n-1; left < right;) {
                    int64_t sum = (int64_t)a+b+nums[left]+nums[right];
                    if (sum == target) {
                        res.emplace_back(vector<int>({a, b, nums[left], nums[right]}));
                    }
                    if (sum <= target && left + 1 < n) {
                        left++;
                        while(left + 1 < n && nums[left] == nums[left-1]) left++;
                    }
                    if (sum >= target && right > 0) {
                        right--;
                        while(right > 0 && nums[right] == nums[right+1]) right--;
                    } 
                }
            }
        }
        return res;
    }
};
// @lc code=end

