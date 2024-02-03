/*
 * @lc app=leetcode.cn id=2303 lang=cpp
 *
 * [2303] 计算应缴税款总额
 */

// @lc code=start
class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        int64_t ans = 0;
        for (int i = 0, prev = 0; i < brackets.size(); i++) {
            int upper = brackets[i][0];
            int percent = brackets[i][1];
            ans += (min(upper, income) - prev) * percent;
            prev = upper;
            if (income <= upper)
                break;
        }
        cout<<"res="<<ans<<endl;
        //必须把100计算放到最后，不然有精度误差
        return (double)ans / 100.0f;
    }
};
// @lc code=end

