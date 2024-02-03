/*
 * @lc app=leetcode.cn id=2420 lang=cpp
 *
 * [2420] 找到所有好下标
 */

// @lc code=start
class Solution {
public:
    //这里有陷阱，注意i并不需要一定比i-1小，也不一定要比i+1小
    vector<int> goodIndicesEx(vector<int>& nums, int k) {
        vector<int> res;
        for (int start = 0, cur = 1, end = 2; end < nums.size(); start++) {
            while (cur - start < k && cur + 1 < nums.size()) {
                if (cur != start && nums[cur-1] < nums[cur])
                    start = cur;
                cur++;
            }
            if (cur + 1 == nums.size()) break;
            while (end - cur < k && end + 1 < nums.size()) {
                if (cur < end && nums[end] > nums[end+1])
                    break;
                end++;
            }
            if (end - cur == k) {
                res.push_back(cur);
            }
        }
        return res;
    }

    //动态规划
    //left[i]: 从i开始算起，左边降序的个数
    //right[i]: 从i开始算起，右边降序的个数
    //符合条件的: left[i-1] >= k and right[i+1] >=k
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> left(n, 1), right(n, 1);
        for (int i = 1; i < n; i++) {
            if (nums[i] <= nums[i-1])
                left[i] = left[i-1] + 1;
            if (nums[n-i-1] <= nums[n-i])
                right[n-i-1] = right[n-i] + 1;
        }
        vector<int> res;
        //注意，从<k开始是没有意义的，
        for (int i = k; i < n - k; i++) {
            if (left[i-1] >= k && right[i+1] >= k)
                res.push_back(i);
        }
        return res;
    }
};
// @lc code=end

