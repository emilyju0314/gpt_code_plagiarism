#include <iostream>
#include <vector>
#include <cmath>

const int MOD = 1e9 + 7;

int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1;
}

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    int count = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        if (a[i] == -1) {
            count++;
        }
    }

    long long result = 0;
    long long base = modInverse(n, MOD);

    for (int i = 0; i < n; i++) {
        if (a[i] == -1) {
            result = (result + base) % MOD;
        }
    }

    long long p = 1;
    for (int i = 0; i < count; i++) {
        p = (p * k) % MOD;
    }

    long long q = modInverse(p, MOD);
    int ans = (result * q) % MOD;
    std::cout << ans << std::endl;

    return 0;
}