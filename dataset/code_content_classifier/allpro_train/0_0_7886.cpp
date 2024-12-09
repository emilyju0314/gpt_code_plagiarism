#include <iostream>
#include <vector>

#define MOD 1000000007

long long modInv(long long a, long long m) {
    long long m0 = m, t, q;
    long long x0 = 0, x1 = 1;
    if (m == 1) return 0;
    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0) x1 += m0;
    return x1;
}

long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

long long expectedValue(long long n, int k) {
    std::vector<long long> divisors;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i * i != n) {
                divisors.push_back(n / i);
            }
        }
    }

    long long sum = 0;
    for (int i = 0; i < divisors.size(); i++) {
        sum += divisors[i];
    }
    
    long long N = divisors.size();
    long long P = sum % MOD;
    long long Q = 1;
    for (int i = 2; i <= k; i++) {
        Q = (Q * N) % MOD;
        P = (P * modInv(N, MOD)) % MOD;
    }

    long long result = (P * modInv(Q, MOD)) % MOD;
    return result;
}

int main() {
    long long n;
    int k;
    std::cin >> n >> k;

    long long result = expectedValue(n, k);
    std::cout << result << std::endl;

    return 0;
}