#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (!b) return a;
  return gcd(b, a % b);
}
long long power(long long x, long long y, long long p = 1e18) {
  long long result = 1;
  x %= p;
  while (y > 0) {
    if (y & 1) result = (result * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return result;
}
void solve() {
  long long n, m;
  cin >> n >> m;
  string x, y;
  cin >> x >> y;
  long long L[n + 1][m + 1];
  long long i, j;
  long long res = 0;
  for (i = 0; i <= n; i++) {
    for (j = 0; j <= m; j++) {
      if (i == 0 || j == 0) {
        L[i][j] = -max(i, j);
      } else {
        L[i][j] = max(L[i - 1][j] - 1, L[i][j - 1] - 1);
        if (x[i - 1] == y[j - 1]) {
          L[i][j] = L[i - 1][j - 1] + 2;
        }
      }
      L[i][j] = max(L[i][j], 0ll);
      res = max(res, L[i][j]);
    }
  }
  cout << res;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  long long x = 1;
  cout << fixed << setprecision(12);
  while (t--) {
    solve();
    x++;
  }
  cerr << "Time Taken : " << (float)clock() / CLOCKS_PER_SEC << " secs"
       << "\n";
}
