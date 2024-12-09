#include <iostream>
#include <cmath>

const long long MOD = 1e9 + 7;

long long modInverse(long long a, long long m) {
    long long m0 = m, t, q;
    long long x0 = 0, x1 = 1;
 
    if (m == 1)
       return 0;
 
    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
 
    if (x1 < 0)
       x1 += m0;
 
    return x1;
}

long long expectedTime(int n, int m, int rb, int cb, int rd, int cd, int p) {
    long long dr = std::abs(rd - rb);
    long long dc = std::abs(cd - cb);
    long long ans = dr + dc;
    long long prob = p * modInverse(100, MOD) % MOD;

    long long total = 0;
    for(int i = 0; i <= 2*n + 1; i++) {
        total += i * (MOD + prob - 1) % MOD * modInverse(prob, MOD) % MOD;
        total %= MOD;
    }

    for(int i = 0; i <= 2*m + 1; i++) {
        total += i * (MOD + prob - 1) % MOD * modInverse(prob, MOD) % MOD;
        total %= MOD;
    }

    return (ans + total) % MOD;
}

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        int n, m, rb, cb, rd, cd, p;
        std::cin >> n >> m >> rb >> cb >> rd >> cd >> p;

        long long result = expectedTime(n, m, rb, cb, rd, cd, p);
        std::cout << result << std::endl;
    }

    return 0;
}