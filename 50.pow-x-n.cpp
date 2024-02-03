/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */ 

// @lc code=start
class Solution {
public:

    double myPowEx(double x, int64_t n)
    {
        if (n == 0) return 1;
        double res = myPowEx(x, n/2);
        return n & 0x1 > 0 ? res * res * x : res * res;
    }

    double myPowEx2(double x, int64_t n)
    {
        //实际上就靠不断*2来减少计算量
        double res = 1.0f;
        double val = x;
        while (n > 0){
            //如果是奇数次幂，可以先*val来处理掉尾巴，继续/2
            if (n & 0x1 > 0){
                res *= val;
            }
            val *= val;
            n = n / 2;
        }
        return res;
    }

    double myPow(double x, int n) {
        int64_t new_n = n;
        return new_n >= 0 ? myPowEx2(x, new_n) : 1.0 / myPowEx2(x, -new_n);
    }
};
// @lc code=end

