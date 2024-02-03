/*
 * @lc app=leetcode.cn id=1942 lang=cpp
 *
 * [1942] 最小未被占据椅子的编号
 */

// @lc code=start
class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        multimap<int, int> arrived, leave;
        for (int i = 0; i < times.size(); i++) {
            arrived.emplace(times[i][0], i);
            leave.emplace(times[i][1], i);
        }

        //使用优先队列比使用set更好，因为我们不需要对available完整排序
        priority_queue<int, vector<int>, greater<int>> available;
        unordered_map<int, int> seat;   //<firend, seat idx>
        auto iter1 = arrived.begin();
        auto iter2 = leave.begin();
        while (iter1 != arrived.end()) {
            if (iter1->first >= iter2->first) {
                //some leave
                available.push(seat[iter2->second]);
                seat.erase(iter2->second);
                iter2++;
            }else{
                if (available.empty()) {
                    int cur = seat.size();
                    seat[iter1->second] = cur;
                }else{
                    seat[iter1->second] = available.top();
                    available.pop();
                }
                if (iter1->second == targetFriend) break;
                iter1++;
            }
        }
        return seat[targetFriend];
    }

    int smallestChairEx(vector<vector<int>>& times, int targetFriend) {
        //这里有个陷阱，到达时间是各不相同的，但是离开时间可以是一样的！
        //所以leave不能用map
        multimap<int, int> arrived, leave;
        for (int i = 0; i < times.size(); i++) {
            arrived.emplace(times[i][0], i);
            leave.emplace(times[i][1], i);
        }
        priority_queue<int, vector<int>, greater<int>> available;
        for (int i = 0; i < times.size(); i++) {
            available.push(i);
        }
        unordered_map<int, int> seats;   //<firend, seat idx>
        auto iter1 = arrived.begin();
        auto iter2 = leave.begin();
        while (iter1 != arrived.end()) {
            int time = iter1->first;
            int person = iter1->second;
            while (iter2 != leave.end() && iter2->first <= time) {
                available.push(seats[iter2->second]);
                iter2++;
            }

            int seat = available.top();
            seats[person] = seat;
            available.pop();
            if (person == targetFriend) return seat;
            iter1++;
        }
        return -1;
    }
};
// @lc code=end

