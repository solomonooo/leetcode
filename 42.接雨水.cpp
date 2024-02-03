/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap2(vector<int>& height) {
         int water = 0, n = height.size();
         for (int start = 0, end = n-1; start < end;) {
            int left = height[start], right = height[end];
            if (left <= right) {
                while (start+1 < end && left >= height[start+1]) {
                    water += left-height[++start];
                } 
                start++;
            }else{
                while (start+1 < end && right >= height[end-1]) {
                    water += right-height[--end];
                } 
                end--;
            }
         }
         return water;
    }

    int trap(vector<int>& height) {
        int ans = 0;
        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        while (left < right) {
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);
            if (height[left] < height[right]) {
                ans += leftMax - height[left];
                ++left;
            } else {
                ans += rightMax - height[right];
                --right;
            }
        }
        return ans;
    }
};
// @lc code=end

