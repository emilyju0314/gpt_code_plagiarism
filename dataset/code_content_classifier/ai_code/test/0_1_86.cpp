#include <iostream>
#include <vector>

const int MOD = 998244353;

long long power(long long x, long long y) {
    long long res = 1;
    x %= MOD;
    while(y > 0) {
        if(y & 1) {
            res = (res * x) % MOD;
        }
        y >>= 1;
        x = (x * x) % MOD;
    }
    return res;
}

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        int n, k, x;
        std::cin >> n >> k >> x;

        if(n == 1) {
            std::cout << "1\n";
        } else if(n == 2) {
            std::cout << power(2, k-1) << "\n";
        } else {
            // If x is non-zero and n is odd, the number of valid sequences is 0
            if(x != 0 && n % 2 == 1) {
                std::cout << "0\n";
            } else {
                std::cout << power(2, n-1) << "\n";
            }
        }
    }

    return 0;
}