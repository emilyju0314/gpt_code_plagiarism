#include <iostream>
using namespace std;

const int MOD = 1e9+7;

long long powMod(long long x, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            res = (res * x) % mod;
        }
        x = (x * x) % mod;
        n /= 2;
    }
    return res;
}

int main() {
    int N, M;
    cin >> N >> M;

    long long ans = 1;
    for (int i = 1; i <= N; i++) {
        ans = (ans * i) % MOD;
    }

    long long cnt = 1;
    for (int i = M-N+1; i <= M; i++) {
        cnt = (cnt * i) % MOD;
    }

    ans = (ans * cnt) % MOD;

    cnt = powMod(ans, MOD-2, MOD);

    for (int i = 1; i <= N; i++) {
        cnt = (cnt * i) % MOD;
    }

    cout << cnt << endl;

    return 0;
}