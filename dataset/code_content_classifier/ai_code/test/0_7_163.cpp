#include <iostream>
#include <cmath>
using namespace std;

const int MOD = 1e9 + 7;

int powmod(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (1LL * res * a) % MOD;
        }
        a = (1LL * a * a) % MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, rb, cb, rd, cd, p;
        cin >> n >> m >> rb >> cb >> rd >> cd >> p;

        int dy = abs(rb - rd);
        int dx = abs(cb - cd);

        int g = min(dy, dx);
        int total = dy + dx - g;
        int ans = 0;

        if (p == 100) {
            ans = total;
        } else {
            int r = powmod(100 - p, MOD - 2);
            int s1 = (powmod(p, total + 1) - 1 + MOD) % MOD;
            int s2 = powmod(p, 2) - 1;
            s2 = (1LL * s2 * (MOD - r)) % MOD;
            ans = (1LL * s1 * r % MOD - s2 + MOD) % MOD;
        }

        cout << ans << endl;
    }

    return 0;
}