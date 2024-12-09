#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-8;
const long long mod = 1e9 + 7;
const long long INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
const long long MAXN = 2e5 + 10;
vector<long long> e[MAXN];
long long vis[MAXN];
long long ans = 0;
void dfs(long long start, long long now, long long fa) {
  if (start == now && fa != start) {
    vis[start] = 1;
    ans++;
    return;
  }
  if (e[now].size() != 2) return;
  for (long long i = 0; i < e[now].size(); ++i) {
    long long v = e[now][i];
    if (v != fa && vis[v] == 0) {
      vis[v] = 1;
      dfs(start, v, now);
    }
  }
}
void solve() {
  long long n, m;
  cin >> n >> m;
  for (long long i = (1); i <= (m); ++i) {
    long long u, v;
    cin >> u >> v;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  for (long long i = (1); i <= (n); ++i) {
    if (vis[i] == 0 && e[i].size() == 2) {
      dfs(i, i, i);
    }
  }
  cout << ans;
}
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long _ = 1;
  for (long long i = 1; i <= _; ++i) {
    solve();
  }
  return 0;
}
