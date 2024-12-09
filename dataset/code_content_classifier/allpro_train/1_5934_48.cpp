#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
const int maxq = 1e5 + 5;
int n, m;
int q;
int op[maxq], x[maxq], y[maxq];
int shelf[maxn][maxn];
int ans[maxq];
vector<int> g[maxq];
int cnt = 0;
void ReadInput() {
  cin >> n >> m >> q;
  for (int i = 1; i <= q; ++i) {
    cin >> op[i] >> x[i];
    if (op[i] == 4)
      g[x[i]].push_back(i);
    else {
      g[i - 1].push_back(i);
      if (op[i] != 3) cin >> y[i];
    }
  }
}
void dfs(int u) {
  bool flag = false;
  if (op[u] == 1) {
    cnt += shelf[x[u]][y[u]] ? 0 : 1;
    flag = (shelf[x[u]][y[u]] == 0);
    shelf[x[u]][y[u]] = 1;
  } else if (op[u] == 2) {
    cnt += shelf[x[u]][y[u]] ? -1 : 0;
    flag = (shelf[x[u]][y[u]] == 1);
    shelf[x[u]][y[u]] = 0;
  } else if (op[u] == 3) {
    int i = x[u];
    for (int j = 1; j <= m; ++j) {
      cnt += shelf[i][j] ? -1 : 1;
      shelf[i][j] ^= 1;
    }
  }
  ans[u] = cnt;
  for (int v : g[u]) dfs(v);
  if (op[u] == 1) {
    cnt += flag ? -1 : 0;
    shelf[x[u]][y[u]] = flag ? 0 : 1;
  } else if (op[u] == 2) {
    cnt += flag ? 1 : 0;
    shelf[x[u]][y[u]] = flag ? 1 : 0;
  } else if (op[u] == 3) {
    int i = x[u];
    for (int j = 1; j <= m; ++j) {
      cnt += shelf[i][j] ? -1 : 1;
      shelf[i][j] ^= 1;
    }
  }
}
void Solve() {
  fill_n(&shelf[0][0], sizeof(shelf) / sizeof(shelf[0][0]), 0);
  dfs(0);
  for (int i = 1; i <= q; ++i) cout << ans[i] << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ReadInput();
  Solve();
}
