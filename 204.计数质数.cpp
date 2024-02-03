/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 */

// @lc code=start
class Solution {
public:
    int countPrimes2(int n) {
        vector<bool> prime(n, true);
        int ans = 0;
        for (int i = 2; i < n; i++) {
            if (prime[i]) {
                ans++;
                for (auto j = (int64_t)i * i; j < n; j += i) {
                    prime[j] = false;
                }
            }
        }
        return ans;
    }

    int countPrimes(int n) {
        vector<int> primes;
        vector<bool> isPrimes(n, true);
        for (int i = 2; i < n; i++) {
            if (isPrimes[i]) {
                primes.push_back(i);
            }
            for (int j = 0; j < primes.size() && i * primes[j] < n; j++) {
                isPrimes[i*primes[j]] = false;
                if (i % primes[j] == 0)
                    break;
            }
        }
        return primes.size();
    }

};

// @lc code=end

