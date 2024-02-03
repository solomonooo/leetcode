/*
 * @lc app=leetcode.cn id=1603 lang=cpp
 *
 * [1603] 设计停车系统
 */

// @lc code=start
class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small) {
        car_.push_back(big);
        car_.push_back(medium);
        car_.push_back(small);
    }
    
    bool addCar(int carType) {
        if (car_[carType-1] > 0) {
            car_[carType-1]--;
            return true;
        }
        return false;
    }

protected:
    vector<int> car_;
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
// @lc code=end

