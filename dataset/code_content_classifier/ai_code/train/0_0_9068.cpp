#include <iostream>
#define MOD 1000000007
using namespace std;

long long mod_pow(long long x, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) {
            res = (res * x) % mod;
        }
        x = (x * x) % mod;
        n >>= 1;
    }
    return res;
}

int main() {
    int N, K;
    cin >> N >> K;

    long long ans = 0;
    for (int i = 1; i <= K; i++) {
        long long cnt = mod_pow(K / i, N, MOD);
        for (int j = 2; j <= K / i; j++) {
            cnt = (cnt - mod_pow(K / i - j, N, MOD) * (j - 1) + MOD) % MOD;
        }
        ans = (ans + cnt * i) % MOD;
    }

    cout << ans << endl;
    return 0;
}