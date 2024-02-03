/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根 
 */

// @lc code=start
class Solution {
public:
    //1. 牛顿法
    //构造函数y=x^2-x0, x0是输入，新函数与x轴的交集就是我们希望找到的sqrt(x)的解
    //x[i+1] = 0.5*(x[i]+x0/x[i]) x的迭代公式
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;
        double c = x, xi = x;
        while (true) {
            double tmp = 0.5*(xi+c/xi);
            if ((int)tmp == (int)xi) break;
            xi = tmp;
        }
        return (int)xi;
    }

    //2. 2分查找
    int mySqrt2(int x) {
        if(x < 2){
            return x;
        }
        int low = 1;
        int high = x;
        while(low < high){
            int mid = (low+high)/2;
            if(x/mid >= mid){
                low = mid + 1;
            }else{
                high = mid;
            }
        }
        return high-1;
    }
};
// @lc code=end

