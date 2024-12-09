#include <bits/stdc++.h>
using namespace std;
long long solve();
vector<long long> a;
string s;
long long n;
long long fact[5000];
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  fact[0] = 1;
  for (long long i = 1; i < 5000; i++) {
    fact[i] = (fact[i - 1] * i) % 998244353;
  }
  while (t--) {
    solve();
  }
  return 0;
}
void in(vector<long long> &a, long long n) {
  long long i = 0, x;
  for (i = 0; i < n; i++) {
    cin >> x;
    a.push_back({x});
  }
}
long long dp[500 + 1][500 + 1];
long long epow(long long val, long long p) {
  if (p == 0) return 1;
  if (p & 1) return (val * epow((val * val) % 998244353, p / 2)) % 998244353;
  return epow((val * val) % 998244353, p / 2) % 998244353;
}
long long comb[500 + 1][500 + 1];
long long ncr(long long n, long long r) {
  if (n == r || r == 0) return 1;
  if (comb[n][r] != -1) return comb[n][r];
  return comb[n][r] = (ncr(n - 1, r - 1) + ncr(n - 1, r)) % 998244353;
}
long long total;
long long find(long long cnt, long long x) {
  if (cnt < 2 || x < 1) return 0;
  if (dp[cnt][x] != -1) return dp[cnt][x];
  total++;
  if (x < cnt) {
    dp[cnt][x] = epow(x, cnt) - epow(x - 1, cnt);
    if (dp[cnt][x] < 0) dp[cnt][x] += 998244353;
    return dp[cnt][x];
  }
  dp[cnt][x] = 0;
  long long val;
  for (long long i = 0; i <= n - 2; i++) {
    val = (find(cnt - i, x - cnt + 1) * ncr(cnt, i)) % 998244353;
    val = (val * epow(cnt - 1, i)) % 998244353;
    dp[cnt][x] = (dp[cnt][x] + val) % 998244353;
  }
  return dp[cnt][x];
}
long long solve() {
  a.clear();
  s.clear();
  long long i = 0, j = 0, k = 0;
  long long flag = 0;
  long long x = 0, y = 0, z = 0;
  cin >> n;
  cin >> x;
  memset(dp, -1, sizeof(dp));
  memset(comb, -1, sizeof(comb));
  long long ans = 0;
  total = 0;
  for (i = 1; i <= x; i++) ans = (ans + find(n, i)) % 998244353;
  cout << ans << endl;
  return 0;
}
