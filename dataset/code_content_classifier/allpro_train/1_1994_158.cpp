#include <bits/stdc++.h>
const long long INF = 2000000005;
const long long BIG_INF = 2000000000000000005;
const long long mod = 1000000007;
const long long P = 31;
const long double PI = 3.141592653589793238462643;
const double eps = 1e-9;
using namespace std;
vector<pair<long long, long long> > dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
inline bool valid(long long x, long long y, long long n, long long m) {
  return x >= 0 && y >= 0 && x < n && y < m;
}
mt19937 rng(1999999973);
long long n, m, k, ans = 0, a[25][25];
unordered_map<long long, long long> col[25][25];
void dfs1(long long x, long long y, long long val) {
  if (!valid(x, y, n, m)) return;
  val ^= a[x][y];
  if (x + y == (n + m - 2) / 2) {
    col[x][y][val]++;
    return;
  }
  dfs1(x + 1, y, val);
  dfs1(x, y + 1, val);
}
void dfs2(long long x, long long y, long long val) {
  if (!valid(x, y, n, m)) return;
  if ((n - 1 - x) + (m - 1 - y) == (n + m - 2) - ((n + m - 2) / 2)) {
    ans += col[x][y][val ^ k];
    return;
  }
  val ^= a[x][y];
  dfs2(x - 1, y, val);
  dfs2(x, y - 1, val);
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> m >> k;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  if (n + m - 2 <= 1) {
    long long val = 0;
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < m; j++) {
        val ^= a[i][j];
      }
    }
    cout << ((val == k) ? 1 : 0);
    exit(0);
  }
  dfs1(0, 0, 0);
  dfs2(n - 1, m - 1, 0);
  cout << ans;
  return 0;
}
