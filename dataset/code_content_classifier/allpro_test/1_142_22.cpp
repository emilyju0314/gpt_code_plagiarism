#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("-O3")
#pragma GCC optimize("unroll-loops")
long long gcd(long long n, long long n1) {
  while (n != 0 && n1 != 0) {
    if (n > n1)
      n %= n1;
    else
      n1 %= n;
  }
  return n + n1;
}
long long lcm(long long n, long long n1) {
  long long nod = gcd(n, n1);
  return (n / nod) * (n1 / nod) * nod;
}
long long binpow(long long n, long long m) {
  if (m == 0) return 1;
  if (m % 2 == 1)
    return binpow(n, m - 1) * n;
  else {
    long long b = binpow(n, m / 2);
    return b * b;
  }
}
long long INF = 9999999999999999;
long long mod = 998244353;
void solve() {
  int n, m;
  cin >> m >> n;
  vector<vector<long long>> a(m, vector<long long>(n));
  vector<long long> maxs(n, -INF);
  vector<int> ismx(m, 0);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
      maxs[j] = max(maxs[j], a[i][j]);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (maxs[i] == a[j][i]) {
        ismx[j]++;
      }
    }
  }
  bool u = false;
  for (int i = 0; i < m; i++)
    if (ismx[i] > 1) u = true;
  if (n > m || u) {
    long long mn = INF;
    for (int i = 0; i < n; i++) mn = min(mn, maxs[i]);
    cout << mn << '\n';
    return;
  }
  long long mx = -INF;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      long long mn = INF;
      for (int i1 = 0; i1 < n; i1++)
        if (i1 != i && i1 != j) mn = min(mn, maxs[i1]);
      long long imx = -INF;
      for (int i1 = 0; i1 < m; i1++) {
        imx = max(imx, min(a[i1][i], a[i1][j]));
      }
      mn = min(mn, imx);
      mx = max(mx, mn);
    }
  }
  cout << mx << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
