/*
 * @lc app=leetcode.cn id=60 lang=cpp
 *
 * [60] 排列序列
 */

// @lc code=start
class Solution {
public:
    string getPermutationEx(int n, int k) {
        int factorial = 1;
        int flag = (1<<n)-1;
        for (int i = 0; i < n-1; i++) factorial *= i+1;
        string res;
        while (k > 1) {
            int cur_flag = flag;
            for (int i = 0; i < ((k-1)/factorial); i++) cur_flag &= cur_flag-1;
            int tmp = cur_flag & (-cur_flag);
            res += '1' + __builtin_ctz(tmp);
            flag ^= tmp;
            k = (k-1) % factorial + 1;
            factorial /= --n;
        }
        while (flag > 0) {
            int tmp = flag & (-flag);
            res += '1' + __builtin_ctz(tmp);
            flag &= flag-1;
        }
        return res;
    }

    string getPermutation(int n, int k) {
        int factorial = 1;
        for (int i = 0; i < n-1; i++) factorial *= i+1;
        vector<bool> valid(n, true);
        string res;
        for (int i = 1, f = n-1; i <=n; i++, f--) {
            int order = (k-1) / factorial + 1;  //表示需要添加的数字顺序
            for (int j = 0, o = 0; j < n; j++) {
                if (valid[j]) o++;
                if (o == order) {
                    res += '1' + j; 
                    valid[j] = false;
                    break;
                }
            }
            k -= factorial * (order-1);
            factorial = f > 0 ? (factorial/f) : 1;
            
        }
        return res;
    }
};
// @lc code=end

