#include <bits/stdc++.h>
using namespace std;
using Int = long long;
int PREP = (cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(100), 0);
//int SEGV = getenv("D") || (exit(system("D= SEGFAULT_SIGNALS=all catchsegv ./prog.exe") >> 8), 0);
const Int MOD = 998244353;
const Int MAX = 10000;
Int fac[MAX], finv[MAX], inv[MAX];
void COMinit() {
    fac[0] = fac[1] = finv[0] = finv[1] = inv[1] = 1;
    for (int i = 2; i < MAX; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
Int COM(int n, int k) {
    if (n < k || n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
Int memo[3010][6010];
Int f(int n, int sum) {
    if (sum > 2 * n || sum < 0) return 0;
    if (n == 0) return sum == 0;
    if (memo[n][sum] != -1) return memo[n][sum];
    Int ans = f(n - 1, sum) + f(n - 1, sum - 1) + f(n - 1, sum - 2);
    ans %= MOD;
    return memo[n][sum] = ans;
}
Int memo2[3010][3010];
Int g(int k, int n, int m) {
#if 0
    if (n <= 0) return 0;
    if (k == 0) return f(n, m);
    if (memo2[k][n] != -1) return memo2[k][n];
    Int ans = g(k - 1, n - 1, m) + g(k, n - 1, m);
    ans %= MOD;
    return memo2[k][n] = ans;
#else
    Int ans = 0;
    for (int a = 1; a <= n - k; a++) {
        ans += COM(n - a - 1, k - 1) * f(a, m);
        ans %= MOD;
    }
    return ans;
#endif
}
int main() {
    COMinit();
    memset(memo, -1, sizeof(memo));
    int N, X; cin >> N >> X;
    Int ans = 0;
    for (int t = 0; t <= N * 2; t++) {
        if (t < X) {
            ans += f(N, t);
            ans %= MOD;
        } else if (t == X) {
            // zero
        } else {
            if (t % 2 == 0 && X % 2 == 1) {
                int k = (t - X + 1) / 2;
                int m = t - k * 4;
                if (m <= 0) {
                    ans += COM(N, t / 2);
                } else {
                    ans += g(k * 2, N, m);
                }
                ans %= MOD;
            }
            if (t % 2 == 1 && X % 2 == 0) {
                int k = (t - X + 1) / 2;
                int m = t - k * 4;
                if (m > 0) {
                    ans += g(k * 2, N, m);
                }
                ans %= MOD;
            }
        }
    }
    cout << ans << endl;
    return 0;
}