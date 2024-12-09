#include <bits/stdc++.h>
using namespace std;
long long n, m, p, l, r, a[100009], s[100009], q[100009], d[100009], g[100009],
    f[109][100009];
int main() {
  cin >> n >> m >> p;
  for (long long i = 1; i <= n - 1; ++i) {
    long long dd;
    cin >> dd;
    d[i + 1] = d[i] + dd;
  }
  for (long long i = 1; i <= m; ++i) {
    long long x, y;
    cin >> x >> y;
    a[i] = y - d[x], s[i] = s[i - 1] + a[i];
  }
  sort(a + 1, a + 1 + m);
  memset(f, 0x3f, sizeof f), f[0][0] = 0;
  for (long long i = 1; i <= p; ++i) {
    for (long long j = 1; j <= m; ++j) g[j] = f[i - 1][j] + s[j];
    l = r = 1, q[1] = 0;
    for (long long j = 1; j <= m; ++j) {
      while (l < r && g[q[l + 1]] - g[q[l]] <= a[j] * (q[l + 1] - q[l])) ++l;
      f[i][j] = min(f[i - 1][j], g[q[l]] + a[j] * (j - q[l]) - s[j]);
      if (g[j] >= 4e18) continue;
      while (l < r && (g[j] - g[q[r]]) * (q[r] - q[r - 1]) <=
                          (g[q[r]] - g[q[r - 1]]) * (j - q[r]))
        --r;
      q[++r] = j;
    }
  }
  cout << f[p][m] << endl;
  return 0;
}
