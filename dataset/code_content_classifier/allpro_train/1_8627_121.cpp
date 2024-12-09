#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T& x) {
  cin >> x;
}
template <typename T, typename... Types>
inline void read(T& x, Types&... args) {
  cin >> x;
}
const long long N = 100;
long double p[N][N];
long long n;
bool ok[4 * N][N];
long double dp[4 * N][N];
long double dp2[4 * N][N];
void go(long long no, long long l, long long r, long long w) {
  if (l == r) {
    if (w == l) dp[no][w] = 1, dp2[no][w] = 0;
    return;
  }
  long double& res = dp[no][w];
  long double& res2 = dp2[no][w];
  if (ok[no][w]) return;
  ok[no][w] = 1;
  res = 0;
  res2 = 0;
  long long mid = (l + r) / 2;
  long double score = (r - l + 1) / 2;
  if (w <= mid) {
    go(2 * no, l, mid, w);
    long double pw = dp[2 * no][w];
    long double ew = dp2[2 * no][w];
    for (long long j = mid + 1; j <= r; j++) {
      go(2 * no + 1, mid + 1, r, j);
      long double pj = dp[2 * no + 1][j];
      long double ej = dp2[2 * no + 1][j];
      long double v = ej + ew;
      res2 = max(res2, 1.0L * v);
      res += pw * pj * p[w][j];
    }
  } else {
    go(2 * no + 1, mid + 1, r, w);
    long double pw = dp[2 * no + 1][w];
    long double ew = dp2[2 * no + 1][w];
    for (long long j = l; j <= mid; j++) {
      go(2 * no, l, mid, j);
      long double pj = dp[2 * no][j];
      long double ej = dp2[2 * no][j];
      long double v = ej + ew;
      res2 = max(res2, 1.0L * v);
      res += pw * pj * p[w][j];
    }
  }
  res2 += res * score;
}
int32_t main() {
  long long e;
  cin >> e;
  n = (1 << e);
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < n; j++) {
      cin >> p[i][j];
      p[i][j] /= 100;
    }
  }
  long double ans = 0;
  for (long long i = 0; i < n; i++) {
    go(1, 0, n - 1, i);
    ans = max(ans, dp2[1][i]);
  }
  cout << fixed << setprecision(11);
  cout << ans << endl;
}
