/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution {
public:
    //主要的难点在不准使用int64
    //所以我们需要在迭代rev之前先判断rev是不是小于INT_MIN/10或者大于INT_MAX/10
    int reverse(int x) {
        int ret = 0;
        while(x){
            if (ret < INT_MIN/10 || ret > INT_MAX/10) return 0;
            ret = ret*10 + x%10;
            x/=10;
        }
        return ret;
    }
};

// @lc code=end

