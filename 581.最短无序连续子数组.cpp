/*
 * @lc app=leetcode.cn id=581 lang=cpp
 *
 * [581] 最短无序连续子数组
 */

// @lc code=start
class Solution {
public:
    int findUnsortedSubarray2(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        stack<int> s1, s2;
        while (left + 1 < nums.size() && nums[left] <= nums[left+1]) {
            s1.push(nums[left++]);
        }
        s1.push(nums[left++]);
        while(left < nums.size() && !s1.empty()) {
            if (nums[left] < s1.top())
                s1.pop();
            else 
                left++;
        }
        while (right - 1 >= 0 && nums[right] >= nums[right-1]) {
            s2.push(nums[right--]);
        }
        s2.push(nums[right--]);
        while(right >= 0 && !s2.empty()) {
            if (nums[right] > s2.top())
                s2.pop();
            else 
                right--;
        }
        int cnt = nums.size() - s2.size() - s1.size();
        return max(0, cnt);
    }

    //对于最大值的位置
    //right记录的是，比当前的最大值大于等于的最右的位置
    //这个遍历只能从左往右完成，从右往左只能用我上面的办法
    int findUnsortedSubarray(vector<int>& nums) {
        int left = -1, min = INT_MAX;
        int right = -1, max = INT_MIN;
        int n = nums.size();
        for (int i = 0; i < n; i++) { 
            if (nums[i] < max)
                right = i;
            else
                max = nums[i];
            if (nums[n-i-1] > min)
                left = n-i-1;
            else
                min = nums[n-i-1];
        }
        return right == -1 ? 0 : right - left + 1;
    }

};

// @lc code=end

