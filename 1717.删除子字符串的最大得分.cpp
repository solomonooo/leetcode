/*
 * @lc app=leetcode.cn id=1717 lang=cpp
 *
 * [1717] 删除子字符串的最大得分
 */

// @lc code=start
class Solution {
public:
    int maximumGain2(string s, int x, int y) {
        if (x < y) {
            reverse(s.begin(), s.end());
            swap(x, y);
        }
        stack<char> sk1, sk2;
        int cnt_x = 0, cnt_y = 0;
        for (char c : s)
        {
            if (!sk1.empty() && sk1.top() == 'a' && c == 'b'){
                cnt_x++;
                sk1.pop();
            }else{
                sk1.push(c);
            }
        }
        while(!sk1.empty())
        {
            if (!sk2.empty() && sk2.top() == 'a' && sk1.top() == 'b'){
                sk2.pop();
                cnt_y++;
            }else{
                sk2.push(sk1.top());
            }
            sk1.pop();
        }
        return cnt_x * x + cnt_y * y;
    }

    int maximumGain(string s, int x, int y) {
        int res = 0, a = 0, b = 0;
        s.push_back('-');
        for (char c : s){
            if (c != 'a' && c != 'b'){
                if (a != 0 && b != 0)
                    res += min(x, y) * min(a, b);
                a = b = 0;
            }else{
                if (c == 'a') a++;
                else b++;
                if (a != 0 && c == 'b' && x >= y) {
                    res += x;
                    a--;
                    b--;
                }else if(b != 0 && c == 'a' && x <= y) {
                    res += y;
                    a--;
                    b--;
                }
            }
        }
        return res;
    }
};
// @lc code=end

