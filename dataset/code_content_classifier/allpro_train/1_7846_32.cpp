#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 3e5 + 10, MOD = 1e9 + 7;
long long n, a[MAXN];
long long ps[MAXN], ans;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  ps[0] = 1;
  for (long long i = 1; i < MAXN; i++) ps[i] = (2 * ps[i - 1]) % MOD;
  cin >> n;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  for (long long i = 1; i <= n; i++) {
    long long x = (a[i] * (ps[i - 1] - ps[n - i]));
    bool mark = 0;
    if (x < 0) mark = 1;
    x = abs(x);
    x %= MOD;
    if (mark) x = -x;
    ans = ans + x;
    mark = 0;
    if (ans < 0) mark = 1;
    ans = abs(ans);
    ans %= MOD;
    if (mark) ans = -ans;
  }
  cout << ans;
}
