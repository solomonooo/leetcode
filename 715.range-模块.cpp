/*
 * @lc app=leetcode.cn id=715 lang=cpp
 *
 * [715] Range 模块
 */

// @lc code=start
class RangeModule {
public:
    RangeModule() {}

    void addRange(int left, int right) {
        auto it = bound_.upper_bound(left);
        if (it != bound_.begin()) {
            auto start = prev(it);
            //i <= left < j
            if (start->second >= right) {
                //目标区间完全被包含
                //i <= left < right <= j
                return;
            }
            if (start->second >= left) {
                //i <= left <= j < right
                left = start->first;
                bound_.erase(start);
            }
            //else{
                //do nothing for i < j <= left < right
            //}
        }
        while (it != bound_.end() && it->first <= right) {
            //left < i < right
            right = max(right, it->second);
            it = bound_.erase(it);
        }
        bound_[left] = right;
    }

    bool queryRange(int left, int right) {
        auto it = bound_.upper_bound(left);
        if (it == bound_.begin()){
            //left < i < j 
            return false;
        }
        it = prev(it);
        //i <= left < j
        return right <= it->second;
    }

    void removeRange(int left, int right) {
        auto it = bound_.upper_bound(left);
        if (it != bound_.begin()) {
            auto start = prev(it);
             //i <= left < j
            if (start->second >= right) {
                //i <= left < right <= j
                int j = start->second;
                if (start->first == left) {
                    // i == left < right <= j
                    //需要后面插入[right, j)
                    bound_.erase(start);
                }else{
                    // i < left < right <= j
                    //修改当前为[i, left)
                    //且后面插入[right, j)
                    start->second = left;
                }
                if (right != j) {
                    bound_[right] = j;
                }
                return;
            }else if (start->second > left) {
                //i <= left < j < right
                if (start->first == left) {
                    //i == left < j < right
                    bound_.erase(start);
                }else {
                    //i < left < j < right
                    start->second = left;
                }
            }
        }

        while (it != bound_.end() && it->first < right) {
            //left < i < right
            if (it->second <= right) {
                //left < i < j <= right
                it = bound_.erase(it);
            }else {
                //left < i < right < j
                //插入[right, j)
                bound_[right] = it->second;
                bound_.erase(it);
                break;
            }
        }
    }

protected:
    std::map<int, int> bound_;
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */
// @lc code=end

