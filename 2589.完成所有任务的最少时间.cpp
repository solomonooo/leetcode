/*
 * @lc app=leetcode.cn id=2589 lang=cpp
 *
 * [2589] 完成所有任务的最少时间
 */

// @lc code=start
class Solution {
public:
    //贪心算法
    //1. 先对区间的end进行排序
    //2. 贪心策略
    ////先检查当前的区间有多少位置已经占用了
    ////对于剩余的duration，从后往前占用
    int findMinimumTime(vector<vector<int>>& tasks) {
        bitset<2000> run;
        sort(tasks.begin(), tasks.end(), [](auto& a, auto& b){
            return a[1] < b[1];
        }); 
        int cnt = 0;
        for (auto& t : tasks) {
            int d = t[2];
            for (int i = t[0]; i <= t[1]; i++) {
                if (run.test(i-1)) d--;
            }
            for (int i = t[1]; d > 0; i--) {
                if (!run.test(i-1)) {
                    run.set(i-1);
                    d--;
                    cnt++;
                }
            }
        }
        return cnt;
    }

};
// @lc code=end

