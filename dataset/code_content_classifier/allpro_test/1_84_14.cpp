#include <bits/stdc++.h>
using namespace std;
long long t, n = 1e5, k, phi[100005], p[100005], prefsum[100005],
             dp[21][100005];
void solve() {
  cin >> n >> k;
  if (k > 17)
    cout << n << '\n';
  else
    cout << n + dp[k][n] << '\n';
}
long long c(long long l, long long r) {
  long long val = 0;
  long long d = l;
  while (d > 0 && r > 0 && r / d > 0) {
    long long cat = r / d;
    long long st = d;
    long long dr = r / cat;
    val += (dr - st + 1) * p[cat];
    d = dr + 1;
  }
  return val;
}
void calcdp(int i, int st, int dr, int optl, int optr) {
  if (st > dr) return;
  int mij = (st + dr) / 2;
  bool ok = 0;
  if (mij == 1) ok = 1;
  pair<long long, long long> best = {1e18, -1};
  for (long long k = optl; k <= min(mij, optr); k++)
    best = min(best, {dp[i - 1][k - 1] + c(k, mij), k});
  dp[i][mij] = best.first;
  long long opt = best.second;
  calcdp(i, st, mij - 1, optl, opt);
  calcdp(i, mij + 1, dr, opt, optr);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  for (int i = 2; i <= 1e5; i++) phi[i] = i;
  for (int i = 2; i <= 1e5; i++) {
    bool prim = (phi[i] == i);
    for (int j = i; j <= 1e5; j += i)
      if (prim) {
        phi[j] /= i;
        phi[j] *= (i - 1);
      }
  }
  for (int i = 1; i <= 1e5; i++) p[i] = p[i - 1] + phi[i];
  for (long long i = 1; i <= n; i++) dp[1][i] = i * (i + 1) / 2 - i;
  for (int i = 2; i <= 17; i++) calcdp(i, 1, n, 1, n);
  cin >> t;
  while (t--) solve();
  return 0;
}
