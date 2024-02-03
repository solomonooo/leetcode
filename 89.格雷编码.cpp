/*
 * @lc app=leetcode.cn id=89 lang=cpp
 *
 * [89] 格雷编码
 */

// @lc code=start
class Solution {
public:
    //如果我们已经有了n-1的序列，那么我们可以这么构造n的序列：
    //将n-1序列反转填入，并且每个数都在高位n设置上1
    vector<int> grayCode(int n) {
        vector<int> res;
        res.reserve(1 << n);
        res.push_back(0);
        for (int i = 1; i <= n; i++) {
            for (int j = res.size()-1; j >= 0; j--) {
                res.push_back(res[j] | 1 <<(i-1));
            }
        }
        return res;
    }

    //格雷编码的计算公式： i = (i>>1)^i
    vector<int> grayCode2(int n) {
        vector<int> ret(1 << n);
        for (int i = 0; i < ret.size(); i++) {
            ret[i] = (i >> 1) ^ i;
        }
        return ret;
    }
};
// @lc code=end

