#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;

long long power(long long x, long long y) {
    long long res = 1;
    x = x % MOD;
    if (x == 0) return 0;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % MOD;
        y = y >> 1;
        x = (x * x) % MOD;
    }
    return res;
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    long long ans = 0;
    for (int i = 1; i < N; i++)
        ans = (ans + 1LL * i * (N - i) * M * M % MOD) % MOD;
    for (int i = 1; i < M; i++)
        ans = (ans + 1LL * i * (M - i) * N * N % MOD) % MOD;

    long long two_inv = power(2, MOD - 2);
    long long comb = 1;
    for (int i = 1; i <= N * M - 2; i++) {
        comb = (comb * (N * M - i) % MOD) * power(i, MOD - 2) % MOD;
        if (i >= K - 2) {
            ans = (ans * 2 + 1LL * comb * (N * N % MOD) % MOD * (M * M % MOD) % MOD) % MOD;
        }
    }

    cout << ans << endl;

    return 0;
}