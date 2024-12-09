#include <bits/stdc++.h>
using namespace std;
typedef const int& cint;
const int mod = 1e9 + 7;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const long long inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;
int n, m, qq;
vector<int> to[300300];
vector<int> ans[300300];
int sum[300300];
int up[300300];
int dep[300300];
void dfs(cint u, cint fa) {
  dep[u] = dep[fa] + 1;
  up[u] = fa;
  for (int v : to[u]) {
    if (v != fa && !dep[v]) {
      dfs(v, u);
    }
  }
}
int ss = 0;
void sol(cint u, cint fa) {
  if (sum[u] % 2) ++ss;
  for (int v : to[u]) {
    if (v != fa && dep[v] == dep[u] + 1) {
      sol(v, u);
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  int u, v;
  for (int i = 1; i <= m; i++) {
    cin >> u >> v;
    to[u].push_back(v);
    to[v].push_back(u);
  }
  dfs(1, 1);
  cin >> qq;
  for (int i = 1; i <= qq; i++) {
    cin >> u >> v;
    vector<int> tmp;
    while (dep[v] > dep[u]) {
      tmp.push_back(v);
      v = up[v];
    }
    while (dep[u] > dep[v]) {
      ans[i].push_back(u);
      u = up[u];
    }
    while (u != v) {
      ans[i].push_back(u);
      tmp.push_back(v);
      u = up[u];
      v = up[v];
    }
    ans[i].push_back(u);
    for (int j = tmp.size() - 1; j >= 0; j--) ans[i].push_back(tmp[j]);
    for (int j = 0; j < ans[i].size(); j++) {
      if (j != 0 && j != ans[i].size() - 1) ++sum[ans[i][j]];
      ++sum[ans[i][j]];
    }
  }
  sol(1, 1);
  if (ss == 0) {
    cout << "YES" << endl;
    for (int i = 1; i <= qq; i++) {
      cout << ans[i].size() << endl;
      for (int j : ans[i]) cout << j << ' ';
      cout << endl;
    }
  } else {
    cout << "NO" << endl;
    cout << ss / 2 << endl;
  }
  return 0;
}
