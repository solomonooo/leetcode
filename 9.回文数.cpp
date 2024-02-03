/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x%10 == 0 && x != 0))
            return false;
        int rev = 0;
        int cur = x;
        //不需要遍历完全，只需要rev == cur或者cur/10就行了
        //cur/10是因为可能x是奇数位
        while(rev < cur){
            rev = rev*10+cur%10;
            cur /= 10;
        }
        return cur == rev || cur == rev/10;
    }
};
// @lc code=end

