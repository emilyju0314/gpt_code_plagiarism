#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

long long power(long long x, long long y) {
    long long res = 1;
    x = x % MOD;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % MOD;
        y = y >> 1;
        x = (x * x) % MOD;
    }
    return res;
}

int main() {
    long long n, k;
    cin >> n >> k;

    vector<long long> f(n+1);
    vector<long long> g(n+1, 1);

    for (long long i = 1; i <= n; i++) {
        f[i] = n / i;
    }

    for (long long i = 2; i <= n; i++) {
        for (long long j = 2 * i; j <= n; j += i) {
            g[j] = (g[j] - g[i] + MOD) % MOD;
        }
    }

    long long ans = 0;

    for (long long i = 1; i <= k; i++) {
        for (long long j = 1; j <= n; j++) {
            f[j] = (f[j] * g[j]) % MOD;
        }
        ans = (ans + f[n]) % MOD;
    }

    cout << ans << endl;

    return 0;
}