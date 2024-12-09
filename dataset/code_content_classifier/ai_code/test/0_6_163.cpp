#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

long long modInverse(long long a, long long m) {
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

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, rb, cb, rd, cd, p;
        cin >> n >> m >> rb >> cb >> rd >> cd >> p;

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        dp[rb][cb] = 1;

        int dr = 1, dc = 1;
        long long ans = 0;
        long long prob = modInverse(p, MOD);

        while (true) {
            ans = (ans + dp[rd][cd]) % MOD;
            dp[rd][cd] = (dp[rd][cd] + prob) % MOD;

            if (dr == 1 && rd == n) dr = -1;
            if (dr == -1 && rd == 1) dr = 1;

            if (dc == 1 && cd == m) dc = -1;
            if (dc == -1 && cd == 1) dc = 1;

            rd += dr;
            cd += dc;

            if (rd == rb && cd == cb) break;
        }

        cout << ans << endl;
    }

    return 0;
}