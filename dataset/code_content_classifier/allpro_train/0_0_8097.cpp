#include <iostream>
#include <vector>

const int MOD = 1e9 + 7;

int mod_pow(int base, int exp, int mod) {
    int result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

int main() {
    int p, k;
    std::cin >> p >> k;

    if (k == 0) {
        std::cout << mod_pow(p, p - 1, MOD) << std::endl;
    } else {
        std::vector<int> visited(p, 0);
        int result = 1;
        for (int i = 1; i < p; ++i) {
            if (!visited[i]) {
                int start = i, cycle_len = 0;
                while (!visited[start]) {
                    visited[start] = 1;
                    start = (1LL * start * k) % p;
                    ++cycle_len;
                }
                result = (1LL * result * mod_pow(p, cycle_len, MOD)) % MOD;
            }
        }
        std::cout << result << std::endl;
    }

    return 0;
}