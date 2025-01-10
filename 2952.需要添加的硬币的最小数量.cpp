/*
 * @lc app=leetcode.cn id=2952 lang=cpp
 *
 * [2952] 需要添加的硬币的最小数量
 */

// @lc code=start
class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        //先排序，非常必要，我们的算法依赖顺序
        sort(coins.begin(), coins.end());
        int ans = 0;
        //x表示[1,x-1]可以获取，index表示当前待取的数
        int x = 1, n = coins.size(), index = 0;
        //如果[1,x-1]可获取,怎么计算下一个数a可以支持的范围？
        //      下一个数a<=x，那么我们就把[1,x-1]里每个数+a, 显然新的区间是[1, x+a-1]
        //              a就标记为取过了
        //      下一个数a>x, 那么显然x不可取，我们添加一个新数x
        //              新的区间是[1, x+x-1] = [1, 2x-1]
        //直到x>target
        while (x <= target) {
            if (index < n && coins[index] <= x) {
                x += coins[index];
                index++;
            }else{
                x <<= 1;
                ans++;
            }
        }
        return ans;
    }
};
// @lc code=end

