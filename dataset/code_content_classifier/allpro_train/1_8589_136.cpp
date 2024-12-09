#include <bits/stdc++.h>
using namespace std;
const long long maxn = 7e5 + 100;
const long long mod = 998244353;
const long long base = 30;
const long long base1 = 260;
long long l[maxn];
long long r[maxn];
long long val[maxn];
long long cnt[maxn];
long long mx[maxn];
long long dp[maxn];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  if (fopen("t.inp", "r")) {
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
  }
  long long n, k, m;
  cin >> n >> k >> m;
  for (int i = 1; i <= m; i++) {
    cin >> l[i] >> r[i] >> val[i];
  }
  long long ans = 1;
  for (int bit = 0; bit < k; bit++) {
    for (int i = 0; i <= n + 1; i++) {
      dp[i] = 0;
      mx[i] = 0;
      cnt[i] = 0;
    }
    for (int i = 1; i <= m; i++) {
      if (val[i] & (1ll << bit)) {
        cnt[l[i]]++;
        cnt[r[i] + 1]--;
      } else {
        mx[r[i] + 1] = max(mx[r[i] + 1], l[i]);
      }
    }
    long long nw = 1;
    dp[0] = 1;
    long long pos = 0;
    for (int i = 1; i <= n + 1; i++) {
      mx[i] = max(mx[i], mx[i - 1]);
      cnt[i] += cnt[i - 1];
      if (cnt[i]) {
        dp[i] = 0;
        continue;
      }
      while (pos < mx[i]) {
        nw = (nw - dp[pos] + mod) % mod;
        pos++;
      }
      dp[i] = nw;
      nw = (nw + dp[i]) % mod;
    }
    ans = (ans * dp[n + 1]) % mod;
  }
  cout << ans;
}
