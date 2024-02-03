/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
class Solution {
public:
    //单调栈
    //我们可以用2个vector去计算left/right（左右边界）. 
    //边界的定义是<当前高度，如果只遍历一遍，则右边界很特殊，在有相同值的情况下计算并不严格正确，但是最右边的边界是正确的，所以结果也正确
    //这里有一个技巧，我们可以不使用left/right数组，实时计算就好
    //因为当我们单调栈出栈的时候，当前位置的左右边界就已经确定了，没有必要去存储
    //我们需要处理原数组单调递增的情况（这时候不会触发出栈），所以我们要额外多处理最后的n位置，直接用0去处理
    //这样就可以在最后强制把栈清空
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), area = 0;
        stack<int> mono_stack;
        for (int i = 0; i <= n; i++) {
            int val = i == n ? 0 : heights[i];
            while (!mono_stack.empty() && heights[mono_stack.top()] >= val) {
                int h = heights[mono_stack.top()];
                mono_stack.pop();
                int l = i - (mono_stack.empty() ? -1 : mono_stack.top())-1;
                area = max(area, h*l);
            }
            mono_stack.push(i);
        }
        return area;
    }
};
// @lc code=end

