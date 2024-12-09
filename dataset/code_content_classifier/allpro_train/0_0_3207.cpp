#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

const long long MOD = 998244353;

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

long long factorial(long long n) {
    long long result = 1;
    for (long long i = 1; i <= n; ++i) {
        result = (result * i) % MOD;
    }
    return result;
}

long long choose(long long n, long long k) {
    if (k > n) {
        return 0;
    }
    long long num = factorial(n);
    long long den = (factorial(k) * factorial(n - k)) % MOD;
    return (num * power(den, MOD - 2)) % MOD;
}

bool hasAtMostKDistinctDigits(long long num, int k) {
    std::string numStr = std::to_string(num);
    std::vector<int> count(10, 0);
    for (char c : numStr) {
        count[c - '0']++;
    }
    int distinctDigits = 0;
    for (int i = 0; i <= 9; ++i) {
        if (count[i] > 0) {
            distinctDigits++;
        }
    }
    return distinctDigits <= k;
}

long long calculateSum(long long l, long long r, int k) {
    long long sum = 0;
    for (long long i = l; i <= r; ++i) {
        if (hasAtMostKDistinctDigits(i, k)) {
            sum = (sum + i) % MOD;
        }
    }
    return sum;
}

int main() {
    long long l, r;
    int k;
    std::cin >> l >> r >> k;

    long long sum = calculateSum(l, r, k);
    std::cout << sum << std::endl;

    return 0;
}