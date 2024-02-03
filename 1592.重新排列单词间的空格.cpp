/*
 * @lc app=leetcode.cn id=1592 lang=cpp
 *
 * [1592] 重新排列单词间的空格
 */

// @lc code=start
class Solution {
public:
    string reorderSpaces(string text) {
        string_view svv(text);
        vector<string_view> vec;
        int z = 0;
        for (size_t i = 0; i < text.length(); i++) {
            if (text[i] == ' ') {
                z++;
                continue;
            }
            size_t pos = i; 
            while (pos+1 < text.length() && text[pos+1] != ' ')
                pos++;
            vec.push_back(svv.substr(i, pos-i+1));
            i = pos;
        }

        string ans;
        int z1 = z / (vec.size() > 1 ? vec.size()-1 : 1);
        for (auto& v : vec){
            ans.append(v.data(), v.length());
            ans.append(z > z1 ? z1 : z, ' ');
            z -= z1;
        }
        if (z > 0) ans.append(z, ' ');
        return ans;
    }

    //特别注意，string_view assign给string的时候，需要注意length问题
};
// @lc code=end

