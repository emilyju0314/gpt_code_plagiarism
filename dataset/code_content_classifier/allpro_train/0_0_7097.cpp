#include <iostream>
#include <vector>

long long pow_mod(long long a, long long b, long long m) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * a) % m;
        }
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

int main() {
    int N;
    long long M;
    std::cin >> N >> M;

    std::vector<long long> fact(N + 1, 1);
    for (int i = 1; i <= N; i++) {
        fact[i] = (fact[i - 1] * i) % M;
    }

    long long ans = 0;
    for (int i = 0; i <= N; i++) {
        long long temp = (fact[N] * pow_mod(fact[N - i], M - 2, M) % M) * pow_mod(2, i, M) % M * pow_mod(2, pow_mod(2, N - i, M - 1), M) % M;
        if (i % 2 == 0) {
            ans = (ans + temp) % M;
        } else {
            ans = (ans - temp + M) % M;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}