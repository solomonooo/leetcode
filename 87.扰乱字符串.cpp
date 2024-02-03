/*
 * @lc app=leetcode.cn id=87 lang=cpp
 *
 * [87] 扰乱字符串
 */

// @lc code=start
class Solution {
public:
    struct Key {
        int idx1;
        int idx2;
        int len;
    };

    struct KeyHash 
    {
        size_t operator()(const Key& k) const {
            return hash<int>()(k.idx1<<2) ^ hash<int>()(k.idx2<<1) ^ hash<int>()(k.len);
        }
    };

    struct KeyEqual
    {
        bool operator()(const Key& k1, const Key& k2) const {
            return k1.idx1 == k2.idx1 && k1.idx2 == k2.idx2 && k1.len == k2.len;
        }
    };
    typedef unordered_map<Key, bool, KeyHash, KeyEqual> Visited_Map;

    bool check(string& s1, int idx1, string& s2, int idx2, int len) {
        vector<int> tmp(26, 0);
        for (int i = 0; i < len; i++) {
            tmp[s1[idx1+i] - 'a']++;
            tmp[s2[idx2+i] - 'a']--;
        }
        return all_of(tmp.begin(), tmp.end(), [](int i) { return i == 0;});
    }

    bool isScramble(string& s1, int idx1, string& s2, int idx2, int len, Visited_Map& visited) {
        auto iter = visited.find({idx1, idx2, len});
        if (iter != visited.end()) {
            return iter->second;
        } 
        
        bool ret = false;
        if (s1.compare(idx1, len, s2, idx2, len) == 0) {
            ret = true;
        }else if (!check(s1, idx1, s2, idx2, len)) {
            ret = false;
        }else{
            for (int i = 1; i < len; i++) {
                if (isScramble(s1, idx1, s2, idx2, i, visited) && isScramble(s1, idx1+i, s2, idx2+i, len-i, visited)) {
                    ret = true;
                    break;
                }
                if (isScramble(s1, idx1, s2, idx2+len-i, i, visited) && isScramble(s1, idx1+i, s2, idx2, len-i, visited)) {
                    ret = true;
                    break;
                }
            }
        } 
        visited[{idx1, idx2, len}] = ret; 
        return ret;
    }

    //这题有几个个重点
    //怎么避免string作为参数时的复制开销？ 使用索引，这里的关键是怎么分解问题，我们不用真的去拆分string，只需要靠开始位置和长度就行。因为长度不同肯定为false，所以我们只需要3个int就能描述
    //怎么记忆状态？可以使用hashmap，这里的要点是如何写hash函数和equal函数
    //检查单次频率是否匹配可以提高速度
    bool isScramble(string s1, string s2) {
        Visited_Map visited;
        return isScramble(s1, 0, s2, 0, s1.length(), visited);
    }
};
// @lc code=end

