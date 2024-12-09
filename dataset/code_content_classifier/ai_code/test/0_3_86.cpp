#include <iostream>

const int mod = 998244353;

long long power(long long base, long long exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, k, x;
        std::cin >> n >> k >> x;

        long long ans;
        if (n % 2 == 1) {
            ans = power(2, n - 1);
            if (k == 1) {
                if (x == 0) {
                    ans = (ans * 2) % mod;
                }
            } else {
                if (x == 0 || x == (1 << k) - 1) {
                    ans = (ans * 2) % mod;
                }
            }
        } else {
            ans = power(2, n);
            if (x == 0 || x == (1 << k) - 1) {
                ans = (ans - 1 + mod) % mod;
            }
        }
        
        std::cout << ans << std::endl;
    }

    return 0;
}