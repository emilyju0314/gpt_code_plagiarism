#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int dx[8] = {0, -1, 0, 1, -1, -1, 1, 1},
          dy[8] = {1, 0, -1, 0, -1, 1, -1, 1};
long long qk(long long x, long long y) {
  long long ans = 1;
  while (y) {
    if (y & 1) ans = ans * x;
    y >>= 1;
    x = x * x;
  }
  return ans;
}
vector<int> vt[5005];
int vis[5005];
int k = 0;
int xx[5005], yy[5005];
int cnt;
void dfs(int x) {
  if (vis[x]) {
    if (x == cnt) k = 2;
    return;
  }
  vis[x] = 1;
  for (auto it : vt[x]) {
    dfs(it);
  }
}
void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> xx[i] >> yy[i];
    vt[xx[i]].push_back(yy[i]);
  }
  k = 1;
  for (int i = 1; i <= n; i++) {
    memset(vis, 0, sizeof vis);
    cnt = i;
    dfs(i);
  }
  if (k == 1) {
    cout << 1 << endl;
    for (int i = 1; i <= m; i++) {
      cout << 1 << ' ';
    }
  } else {
    cout << 2 << endl;
    for (int i = 1; i <= m; i++) {
      if (xx[i] > yy[i])
        cout << 1 << ' ';
      else {
        cout << 2 << ' ';
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  ;
  solve();
  return 0;
}
