/*
 * @lc app=leetcode.cn id=2161 lang=cpp
 *
 * [2161] 根据给定数字划分数组
 */

// @lc code=start
class Solution {
public:
    vector<int> pivotArrayEx(vector<int>& nums, int pivot) {
        queue<int> q1, q2;
        int offset = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == pivot)
                q1.push(nums[i]);
            else if (nums[i] > pivot)
                q2.push(nums[i]);
            else {
                if (offset != i)
                    nums[offset] = nums[i];
                offset++;
            }
        }
        for (int i = offset; i < nums.size(); i++) {
            if (!q1.empty()) {
                nums[i] = q1.front();
                q1.pop();
            }else{
                nums[i] = q2.front();
                q2.pop();
            }
        }
        return nums;
    }

    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> res(nums.size(), pivot);
        int left = 0, right = nums.size()-1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < pivot) {
                res[left++] = nums[i];
            }else if (nums[i] > pivot) {
                res[right--] = nums[i];
            }
        }
        reverse(res.begin()+right+1, res.end());
        return res;
    }

};
// @lc code=end

