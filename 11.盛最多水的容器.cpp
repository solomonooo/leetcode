/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    //双指针法
    //从两端开始，每次从小的那里减少
    //如果值相等，实际上不管我们减少那边，值都不会比当前值大
    int maxArea(vector<int>& height) {
        int maxn = 0, n = height.size();
        for (int left = 0, right = n-1; left < right;) {
            if (height[left] <= height[right]) {
                int cur = (right-left) * height[left];
                maxn = max(maxn, cur);
                left++;
            }else{
                int cur = (right-left) * height[right];
                maxn = max(maxn, cur);
                right--;
            }
        }
        return maxn;
    }
};
// @lc code=end

