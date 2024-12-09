#include <iostream>
#include <vector>

#define MOD 998244353

long long power(long long base, long long exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    long long result = 1;
    long long sum = 0;

    for (int i = 0; i < n; i++) {
        result = (result * (a[i] - (i == 0 ? 0 : 1))) % MOD;
        sum = (sum + (result * power(a[i], MOD - 2)) % MOD) % MOD;
    }

    std::cout << (result * power(sum, n)) % MOD << std::endl;

    return 0;
}