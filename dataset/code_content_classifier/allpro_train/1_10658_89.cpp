#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 3e5 + 100;
const long long INF = 1e18;
const long long MOD = 998244353;
void solve() {
  long long n;
  cin >> n;
  long long x1, x2, y1, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  vector<vector<char>> a(n + 2, vector<char>(n + 2, '1'));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> a[i][j];
    }
  }
  long long dx[4] = {1, -1, 0, 0};
  long long dy[4] = {0, 0, -1, 1};
  queue<pair<long long, long long>> q;
  vector<vector<long long>> used(n + 2, vector<long long>(n + 2, 0));
  vector<vector<long long>> used1(n + 2, vector<long long>(n + 2, 0));
  used[x1][y1] = 1;
  q.push({x1, y1});
  while (!q.empty()) {
    long long x = q.front().first, y = q.front().second;
    q.pop();
    for (int i = 0; i < 4; ++i) {
      long long nx = x + dx[i], ny = y + dy[i];
      if (nx > 0 && nx <= n && ny > 0 && ny <= n && used[nx][ny] == 0 &&
          a[nx][ny] == '0') {
        used[nx][ny] = 1;
        q.push({nx, ny});
      }
    }
  }
  used1[x2][y2] = 1;
  q.push({x2, y2});
  while (!q.empty()) {
    long long x = q.front().first, y = q.front().second;
    q.pop();
    for (int i = 0; i < 4; ++i) {
      long long nx = x + dx[i], ny = y + dy[i];
      if (nx > 0 && nx <= n && ny > 0 && ny <= n && used1[nx][ny] == 0 &&
          a[nx][ny] == '0') {
        used1[nx][ny] = 1;
        q.push({nx, ny});
      }
    }
  }
  long long ans = INF;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      for (int i1 = 1; i1 <= n; ++i1) {
        for (int j1 = 1; j1 <= n; ++j1) {
          if (used[i][j] == 0 || used1[i1][j1] == 0) continue;
          ans = min(1ll * (i1 - i) * (i1 - i) + (j1 - j) * (j1 - j), ans);
        }
      }
    }
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  long long test = 1;
  while (test--) solve();
  return 0;
}
