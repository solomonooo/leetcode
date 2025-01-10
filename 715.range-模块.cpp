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

    std::string toString() {
        std::ostringstream ss;
        for (auto& kv : bound_) {
            ss <<"["<< kv.first <<", "<< kv.second <<") ";
        }
        ss<<std::endl;
        return ss.str();
    }

protected:
    std::map<int, int> bound_;
};

// Task: Implement a class named 'RangeList'
// A pair of integers define a range, for example: [1, 5). This range includes integers: 1, 2, 3, and 4.
// A range list is an aggregate of these ranges: [1, 5), [10, 11), [100, 201)
/** 
 *
 * NOTE: Feel free to add any extra member variables/functions you like.
*/

#include <cstdio>
#include <string>
#include <iostream>
#include <sstream>
#include <map>

//using namespace std;

class RangeList {
public:
    typedef std::pair<int, int> Range;

    /**
     *
     * Adds a range to the list
     * @param {Array<number>} range - Array of two integers that specify beginning and
    end of range.
    */
    void add(Range range) {
        int left = range.first;
        int right = range.second;
        //1. find the last range (l, r), l <= left
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
        //2. remove unnecessary range
        while (it != bound_.end() && it->first <= right) {
            //left < i < right
            right = std::max(right, it->second);
            it = bound_.erase(it);
        }
        //3. insert new range
        bound_[left] = right;
    }


    /** *
     * Removes a range from the list
     * @param {Array<number>} range - Array of two integers that specify beginning and
    end of range.
    */
    void remove(Range range) {
        int left = range.first;
        int right = range.second;
        //1. find the last range (l, r), l <= left
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

        //2. remove or split related range
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

    /** *
     * Convert the list of ranges in the range list to a string
     * @returns A string representation of the range list
    */
    std::string toString() {
        std::ostringstream ss;
        for (auto& kv : bound_) {
            ss <<"["<< kv.first <<", "<< kv.second <<") ";
        }
        ss<<std::endl;
        return ss.str();
    }

protected:
    //store ranges
    std::map<int, int> bound_;
};

//test 
int main(int argc, char* argv[]) {
    RangeList rl;
    std::cout<<rl.toString()<<std::endl; // Should be ""
    rl.add({1, 5});
    std::cout<<rl.toString()<<std::endl; // Should be: "[1, 5)"
    rl.add({10, 20});
    std::cout<<rl.toString()<<std::endl; // Should be: "[1, 5) [10, 20)"
    rl.add({20, 20});
    std::cout<<rl.toString()<<std::endl; // Should be: "[1, 5) [10, 20)"
    rl.add({20, 21});
    std::cout<<rl.toString()<<std::endl; // Should be: "[1, 5) [10, 21)"
    rl.add({2, 4});
    std::cout<<rl.toString()<<std::endl; // Should be: "[1, 5) [10, 21)"
    rl.add({3, 8});
    std::cout<<rl.toString()<<std::endl; // Should be: "[1, 8) [10, 21)"
    rl.remove({10 ,10});
    std::cout<<rl.toString()<<std::endl; // Should be: "[1, 8) [10, 21)"
    rl.remove({10, 11});
    std::cout<<rl.toString()<<std::endl; // Should be: "[1, 8) [11, 21)"
    rl.remove({15, 17});
    std::cout<<rl.toString()<<std::endl; // Should be: "[1, 8) [11, 15) [17, 21)"
    rl.remove({3, 19});
    std::cout<<rl.toString()<<std::endl; // Should be: "[1, 3) [19, 21)"
}



/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */
// @lc code=end

