#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const double pi = acos(-1);
const int p = 1e9 + 7;
int cnt[111][2][22], tmp[2][22], ans[2][22];
int n, k;
vector<int> G[111];
int mul(int a, int b) { return 1ll * a * b % p; }
void add(int& a, int b) { a = (a + b) % p; }
void dfs(int u, int f) {
  cnt[u][0][0] = cnt[u][1][k] = 1;
  for (int v : G[u]) {
    if (v == f) continue;
    dfs(v, u);
    memset(tmp, 0, sizeof tmp);
    for (int i = 0; i <= k; i++) {
      for (int j = 0; j <= k; j++) {
        if (i != k) add(tmp[0][max(i + 1, j)], mul(cnt[u][0][j], cnt[v][0][i]));
        if (j > i)
          add(tmp[1][j], mul(cnt[u][1][j], cnt[v][0][i]));
        else if (i != k)
          add(tmp[0][i + 1], mul(cnt[u][1][j], cnt[v][0][i]));
        if (i > j)
          add(tmp[1][i - 1], mul(cnt[u][0][j], cnt[v][1][i]));
        else
          add(tmp[0][j], mul(cnt[u][0][j], cnt[v][1][i]));
        if (true) add(tmp[1][max(i - 1, j)], mul(cnt[u][1][j], cnt[v][1][i]));
      }
    }
    memcpy(cnt[u], tmp, sizeof cnt[u]);
  }
}
int main() {
  cin >> n >> k;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dfs(1, 1);
  int ans = 0;
  for (int j = 0; j <= k; j++) add(ans, cnt[1][1][j]);
  cout << ans << endl;
  return 0;
}
