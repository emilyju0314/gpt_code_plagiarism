#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

const int MOD = 998244353;

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<int> a(n);
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
        }

        std::vector<int> freq(n + 1, 0);
        int mex = 0;
        long long result = 1;

        for (int i = 0; i < n; i++) {
            while (freq[mex] > 0) {
                result = (result * 2) % MOD;
                freq[mex]++;
                mex++;
            }

            freq[a[i]]++;
        }

        std::cout << (result - 1 + MOD) % MOD << std::endl;
    }

    return 0;
}