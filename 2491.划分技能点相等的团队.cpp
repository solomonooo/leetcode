/*
 * @lc app=leetcode.cn id=2491 lang=cpp
 *
 * [2491] 划分技能点相等的团队
 */

// @lc code=start
class Solution {
public:
    long long dividePlayers2(vector<int>& skill) {
        vector<pair<int, int>> teams;
        unordered_multiset<int> s;
        int sum = 0, n = skill.size();
        for (int i : skill) {
            sum += i; 
            s.insert(i);
        }
        int target = sum / (n/2);
        cout<<"target="<<target<<endl;
        while (!s.empty()) {
            int cur = *s.begin();
            s.erase(s.begin());
            auto it = s.find(target-cur);
            if (it == s.end()) return -1;
            s.erase(it);
            teams.emplace_back(cur, target-cur);
        }
        double ret = 0;
        for (auto& p : teams) {
            ret += p.first*p.second;
        }
        return ret;
    }

    long long dividePlayers(vector<int>& skill) {
        if (skill.size() == 0) return 0;
        sort(skill.begin(), skill.end());
        double res = 0;
        int target = skill.front()+skill.back();
        for (int i = 0, j = skill.size()-1; i < j; i++, j--) {
            if (skill[i] + skill[j] != target) 
                return -1;
            res += skill[i] * skill[j];
        }
        return res;
    }
};
// @lc code=end

