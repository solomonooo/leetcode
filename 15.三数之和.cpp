/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    //排序+双指针
    //这个题目的重点在于如何处理重复，一般我们要处理重复问题，都需要先排序
    //在外层循环的时候，我们需要跳过重复的元素
    //在用双指针遍历的时候，我们需要跳过重复的元素，并且我们的原则应该是看当前的sum，选择跳左边还有右边，直接遍历效率很差
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i = 0; i + 1 < nums.size(); i++){
            if(i>0 && nums[i] == nums[i-1])
                continue;
            
            int a = nums[i], j = i+1, k = nums.size()-1;
            while(j < k){
                int b = nums[j], c = nums[k], sum = a+b+c;
                if(sum == 0)
                    res.push_back({a, b, c});
                if(sum<=0)
                    while(j<k && nums[j]==b) j++;
                if(sum>=0)
                    while(j<k && nums[k]==c) k--;
            }
        }
        return res;
    }
};

// @lc code=end

