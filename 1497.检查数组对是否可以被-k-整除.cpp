/*
 * @lc app=leetcode.cn id=1497 lang=cpp
 *
 * [1497] 检查数组对是否可以被 k 整除
 */

// @lc code=start
class Solution {
public:

    bool canArrange(vector<int>& arr, int k) {
        vector<int> vec(k);
        for (int i : arr) {
            int mod = i % k;
            vec[mod >= 0 ? mod : mod+k]++;
        }

        for (int i = 1, j = k-1; i < j; i++, j--) {
            if (vec[i] != vec[j] || (vec[i]+vec[j]) %2 != 0)
                return false;
        }
        return vec[0] % 2 == 0;;
    }
};
// @lc code=end

