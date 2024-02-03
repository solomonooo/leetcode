/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] N 字形变换
 */

// @lc code=start
class Solution {
public:
    //不要被z字形迷惑，实际上原始字符串可以理解为排列出一个W波浪形
    //周期是R=2*numRows-2
    //第一个位置是%R == 0
    //后面每两个位置成对出现  n*R+i 和 n*R+n-i，需要注意i和n-i会重合
    string convert(string s, int numRows) {
        //先判断边界条件 1和>=n都没有意义
        if (numRows <= 1 || numRows >= s.length())
            return s;
        string res;
        int cycle = 2*numRows-2;
        //遍历需要按照输出的顺序，先遍历每一行，遍历的时候判断边界即可
        for(int i = 0; i < numRows; i++){
            for(int j = 0; j < s.length(); j+=cycle){
                if(j+i < s.length())
                    res += s[j+i];
                //i为0和numRows-1的时候，是只有一个元素的
                //其他的每个周期的位置都有2个值 n*R+i 和 n*R+n-i
                if(i > 0 && i < numRows-1 && j+cycle-i < s.length())
                    res += s[j+cycle-i];
            }
        }
        return res;
    }
};
// @lc code=end

