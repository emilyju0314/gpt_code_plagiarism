#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9, maxn = 2e3 + 123, N = 1e5 + 20, LOG = 20, mod = 1e9 + 7;
const int dx[] = {0, 0, -1, 1}, dy[] = {1, -1, 0, 0};
const long double eps = 1e-12, pi = 3.14159265359;
const pair<unsigned long long, unsigned long long> base = make_pair(127, 137);
const long long INF = 1e18;
int n, m, cnt[maxn];
char a[maxn][maxn];
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) cin >> a[i][j];
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (a[i][j] == '1') cnt[j]++;
  for (int i = 0; i < n; ++i) {
    bool ok = 0;
    for (int j = 0; j < m; ++j)
      if (cnt[j] == 1 && a[i][j] == '1') {
        ok = 1;
        break;
      }
    if (!ok) {
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";
  return 0;
}
