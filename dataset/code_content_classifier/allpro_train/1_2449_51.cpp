#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
long long a1[2005][2005], a2[2005][2005], a3[2005][2005], a4[2005][2005];
char c[2005][2005];
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n, m;
  cin >> n >> m;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      cin >> c[i][j];
    }
  }
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      if (c[i - 1][j] != c[i][j] || c[i][j - 1] != c[i][j]) {
        a1[i][j] = 1;
        continue;
      }
      a1[i][j] = min(a1[i - 1][j], a1[i][j - 1]) + 1;
    }
  }
  for (long long i = 1; i <= n; i++) {
    for (long long j = m; j >= 1; j--) {
      if (c[i - 1][j] != c[i][j] || c[i][j + 1] != c[i][j]) {
        a2[i][j] = 1;
        continue;
      }
      a2[i][j] = min(a2[i - 1][j], a2[i][j + 1]) + 1;
    }
  }
  for (long long i = n; i >= 1; i--) {
    for (long long j = 1; j <= m; j++) {
      if (c[i + 1][j] != c[i][j] || c[i][j - 1] != c[i][j]) {
        a3[i][j] = 1;
        continue;
      }
      a3[i][j] = min(a3[i + 1][j], a3[i][j - 1]) + 1;
    }
  }
  for (long long i = n; i >= 1; i--) {
    for (long long j = m; j >= 1; j--) {
      if (c[i + 1][j] != c[i][j] || c[i][j + 1] != c[i][j]) {
        a4[i][j] = 1;
        continue;
      }
      a4[i][j] = min(a4[i + 1][j], a4[i][j + 1]) + 1;
    }
  }
  long long ans = 0;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      ans += min(min(a1[i][j], a2[i][j]), min(a3[i][j], a4[i][j]));
    }
  }
  cout << ans;
  return 0;
}
