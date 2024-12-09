#include <iostream>
#include <cmath>

#define MOD 998244353

using namespace std;

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        b /= 2;
    }
    return res;
}

int main() {
    int n, m, L, R;
    cin >> n >> m >> L >> R;

    long long ans = 0;
    long long total = n * m;

    for (long long i = L; i <= R; i++) {
        if (i % 2 == total % 2) {
            long long ways = binpow(R - L + 1, total);
            long long odd_ways = (total % 2 == 1) ? binpow(R - L + 1, total) : 0;
            ways = (ways + odd_ways) % MOD;
            ways = (ways * binpow(total, MOD - 2)) % MOD;
            ans = (ans + ways) % MOD;
        }
    }

    cout << ans << endl;

    return 0;
}