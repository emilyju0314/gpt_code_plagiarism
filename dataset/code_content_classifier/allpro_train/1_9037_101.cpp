#include <bits/stdc++.h>
using namespace std;
long long n, d;
const long long N = 102;
long long a[N] = {};
long long m[102][102] = {};
struct point {
  long long x, y;
  void get() { cin >> x >> y; }
  long long dist(const point &a) {
    return d * ((long long)abs(x - a.x) + (long long)abs(y - a.y));
  }
} pt[102];
void solve() {
  cin >> n >> d;
  for (long long i = 2; i < n; ++i) cin >> a[i];
  for (long long i = 1; i < n + 1; ++i) {
    pt[i].get();
  }
  for (long long i = 1; i < n + 1; ++i) {
    for (long long j = 1; j < n + 1; ++j) {
      if (i == j)
        m[i][j] = 1e15;
      else
        m[i][j] = pt[i].dist(pt[j]) - a[i];
    }
  }
  for (long long i = 1; i < n + 1; ++i) {
    for (long long j = 1; j < n + 1; ++j) {
      for (long long k = 1; k < n + 1; ++k) {
        if (i != j and j != k and k != i) {
          m[j][k] = min(m[j][k], m[j][i] + m[i][k]);
        }
      }
    }
  }
  cout << m[1][n];
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
