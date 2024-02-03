/*
 * @lc app=leetcode.cn id=2117 lang=cpp
 *
 * [2117] 一个区间内所有数乘积的缩写
 */

// @lc code=start
class Solution {
public:
    string abbreviateProduct(int left, int right) {
        int n2 = 0, n5 = 0;
        //calc 0
        for (int i = left; i <= right; i++) {
            int t = i;
            while (t%2==0) t /= 2, n2++;
            while (t%5==0) t /= 5, n5++;
        }
        int c = min(n2, n5);
        n2 = n5 = c;

        //calc low 5
        bool flag = true;
        int64_t low = 1, cur = 1;
        for (int i = left; i <=right; i++) {
            int t = i;
            while (n2 > 0 && t%2 == 0) t /= 2, n2--;
            while (n5 > 0 && t%5 == 0) t /= 5, n5--;
            low = low * t % 100000;
            if (flag) {
                cur = cur * t;
                if (cur >= 10000000000LL) flag = false;
            }
        }
        if (flag)
            return to_string(cur) + "e" + to_string(c);

        //calc high 5
        long double b = 0;
        long double lne = log((long double)10.0);
        for (int i = left; i <= right; i++) {
            b += log((long double)i) / lne;
        }
        int64_t high = pow((long double)10.0, b - int64_t(b) + 4);
        char buffer[20] = {0};
        snprintf(buffer, 20, "%05lld", low);
        return to_string(high) + "..." + string(buffer) + "e" + to_string(c);
    }

};

// @lc code=end


