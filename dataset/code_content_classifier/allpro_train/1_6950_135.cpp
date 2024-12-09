#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const long long MAX = 1e3 + 7;
const long long dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const long long dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
long long i, j, k, t, n, q, l, r, mid;
long long ans, cnt, x, y, m;
long long mp[MAX], h[MAX];
long long pc[MAX][MAX], cc[MAX][MAX];
void solve() {
  cin >> n >> m;
  for (long long i = 0; i < n; i++) {
    cin >> x >> y;
    mp[y]++;
    pc[y][x]++;
  }
  for (long long i = 0; i < m; i++) {
    cin >> x >> y;
    h[y]++;
    cc[y][x]++;
  }
  for (long long i = 0; i < 1001; i++) {
    if (min(mp[i], h[i])) {
      cnt += min(mp[i], h[i]);
      for (long long j = 0; j < 1001; j++) {
        ans += min(pc[i][j], cc[i][j]);
      }
    }
  }
  cout << cnt << " " << ans << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  solve();
  return 0;
}
