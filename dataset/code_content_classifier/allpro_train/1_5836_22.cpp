#include <bits/stdc++.h>
using namespace std;
int const LIM = 1e5 + 10;
int n, init[LIM], goal[LIM], p[LIM], cnt[LIM], ans = 0;
vector<int> g[LIM], res;
bool used[LIM];
void dfs(int u) {
  used[u] = true;
  for (auto v : g[u])
    if (!used[v]) {
      p[v] = u;
      dfs(v);
    }
}
void calc(int u) {
  used[u] = true;
  cnt[u] = cnt[p[p[u]]];
  if (cnt[u] % 2 != 0) init[u] ^= 1;
  if (init[u] != goal[u]) {
    res.push_back(u - 1);
    init[u] = goal[u];
    ++ans;
    ++cnt[u];
  }
  for (auto v : g[u])
    if (!used[v]) calc(v);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    ++u;
    ++v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 2; i <= n + 1; ++i) cin >> init[i];
  for (int j = 2; j <= n + 1; ++j) cin >> goal[j];
  p[2] = 1;
  p[1] = 0;
  dfs(2);
  fill(used, used + LIM, false);
  calc(2);
  cout << ans << endl;
  for (auto x : res) cout << x << '\n';
  return 0;
}
