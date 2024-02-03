/*
 * @lc app=leetcode.cn id=773 lang=cpp
 *
 * [773] 滑动谜题
 */

// @lc code=start
class Solution {
public:
    int hash(const vector<vector<int>>& board) {
        int val = 0;
        for (const auto& v : board) {
            for (int i : v) {
                val = val * 10 + i;
            }
        }
        return val;
    }

    void slidingPuzzleEx(vector<vector<int>>& board, unordered_map<int, int>& history, int x, int y, int cur) {
        int cur_hash = hash(board);
        auto iter = history.find(cur_hash);
        if (iter != history.end() && iter->second <= cur) return;
        history[cur_hash] = cur;
        if (cur_hash == 123450) return;
        if (x > 0) {
            swap(board[x-1][y], board[x][y]);
            slidingPuzzleEx(board, history, x-1, y, cur+1);
            swap(board[x-1][y], board[x][y]);
        }
        if (y > 0) {
            swap(board[x][y-1], board[x][y]);
            slidingPuzzleEx(board, history, x, y-1, cur+1);
            swap(board[x][y-1], board[x][y]);
        }
        if (x + 1 < board.size()) {
            swap(board[x+1][y], board[x][y]);
            slidingPuzzleEx(board, history, x+1, y, cur+1);
            swap(board[x+1][y], board[x][y]);
        }
        if (y + 1 < board[0].size()) {
            swap(board[x][y+1], board[x][y]);
            slidingPuzzleEx(board, history, x, y+1, cur+1);
            swap(board[x][y+1], board[x][y]);
        }
    }

    int slidingPuzzleEx(vector<vector<int>>& board) {
        unordered_map<int, int> history;
        int r = board.size(), c = board[0].size();
        int x = 0, y = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (board[i][j] == 0) {
                    x = i;
                    y = j;
                    break;
                }
            }
        }
        slidingPuzzleEx(board, history, x, y, 0);
        auto iter = history.find(123450);
        return iter != history.end() ? iter->second : -1;
    }

    vector<vector<int>> neighbors = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};

    int slidingPuzzle(vector<vector<int>>& board) {
        auto get = [&](string& status) {
            vector<string> res;
            size_t pos = status.find('0');
            for (int i : neighbors[pos]) {
                swap(status[pos], status[i]);
                res.emplace_back(status);
                swap(status[pos], status[i]);
            }
            return res;
        };

        string init;
        init.reserve(8);
        for(auto& v : board) {
            for (int i : v) {
                init.push_back('0' + i);
            }
        }
        if (init == "123450") return 0;
        queue<pair<string, int>> q;
        set<string> seen = {init};
        q.emplace(init, 0);
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            for (auto&& next_status : get(cur.first)) {
                if (next_status == "123450") return cur.second+1;
                if (!seen.count(next_status)) {
                    q.emplace(next_status, cur.second+1);
                    seen.emplace(move(next_status));
                }  
            }
        }
        return -1;
    }
};
// @lc code=end

