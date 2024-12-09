#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000007

long long binomial_coefficient(int n, int k) {
    if (k == 0 || k == n) {
        return 1;
    }
    long long num = 1, den = 1;
    for (int i = 0; i < k; i++) {
        num = (num * (n - i)) % MOD;
        den = (den * (i + 1)) % MOD;
    }
    return (num * pow(den, MOD - 2, MOD)) % MOD;
}

long long pow(long long x, long long y, long long p) {
    long long res = 1;
    x = x % p;
    while (y > 0) {
        if (y & 1) {
            res = (res * x) % p;
        }
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

int main() {
    int N, K;
    std::cin >> N >> K;

    std::vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end());

    long long sum = 0;
    for (int i = K-1; i < N; i++) {
        sum = (sum + A[i] * binomial_coefficient(i, K-1)) % MOD;
    }

    std::cout << sum << std::endl;

    return 0;
}