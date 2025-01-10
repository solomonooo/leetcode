/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
public:
   typedef pair<int, int> Elem;

    struct cmp {
        bool operator()(const Elem& v1, const Elem& v2) {
            return v1.first < v2.first;
        }
    };

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<Elem, vector<Elem>, cmp> pq;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i});
            if (i + 1 >= k) {
                int left = i - k + 1;
                while (!pq.empty()) {
                    auto& cur = pq.top();
                    if (cur.second >= left) {
                        res.push_back(cur.first);
                        break;
                    }else{
                        pq.pop();
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end

