#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 1000000007

long long mod_pow(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
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
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());

    long long ans = 0;
    if (k == 1) {
        ans = mod_pow(2, n, MOD) - 1;
    } else {
        int count = 0;
        for (int i = 0; i < n - k + 1; i++) {
            if (a[i] == a[i + k - 1]) {
                count++;
            }
        }
        if (count == 0) {
            ans = mod_pow(2, k, MOD);
        } else if (count == 1) {
            ans = mod_pow(2, k, MOD) - 1;
        } else {
            ans = mod_pow(2, k, MOD);
        }
    }

    std::cout << ans << std::endl;

    return 0;
}