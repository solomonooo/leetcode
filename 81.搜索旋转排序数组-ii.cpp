/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */

// @lc code=start
class Solution {
public:
    //在原始问题里，我们通过判断开始和结束位置，可以知道哪边的区间是有序的
    //举个例子，比如start<k<end, 这时有k+1 < end < start < k, 
    //如果mid >= start, 显然mid在start和k之间, start和mid之间是有序的，可以二分
    //如果mid < start, 显然  mid < end < start, 所以mid和end之间是有序的，可以二分
    //回到我们的问题，如果start == end，那判断就失效了，我们无法知道mid左右的区间到底是什么样的，也许mid在start这边的区间，也许mid在end那边的区间
    //所以，我们可以直接排除这种情况
    bool search(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1;
        while (nums[start] == nums[end] && start < end) end--;
        while (start < end) {
            int mid = (start+end) / 2;
            if (nums[mid] == target) return true;
            if (nums[start] <= nums[mid]) {
                if (nums[start] <= target && target < nums[mid])
                    end = mid-1;
                else
                    start = mid+1;
            }else{
                if (nums[mid] < target && target <= nums[end])
                    start = mid+1;
                else 
                    end = mid-1;
            }
        }
        return nums[start] == target ? true : false;
    }
};
// @lc code=end

