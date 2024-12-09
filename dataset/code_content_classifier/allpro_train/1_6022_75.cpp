#include <bits/stdc++.h>
using namespace std;
const int MXN = (int)4e5 + 7;
const int MOD = (int)1e9 + 7;
const int N = (int)1e3 + 7;
const double EPS = (double)1e-9;
int n, m, tin[MXN], timer, fup[MXN], ind = 0, cnt[MXN], ans, tag[MXN];
vector<int> g[MXN];
vector<pair<int, int> > node;
bool used[MXN];
pair<int, int> ord[MXN];
map<pair<int, int>, bool> key;
map<pair<int, int>, int> wow;
void dfs(int v, int p = 1) {
  used[v] = 1;
  tin[v] = fup[v] = ++timer;
  for (int to : g[v]) {
    if (to == p) continue;
    if (used[to]) {
      fup[v] = min(fup[v], tin[to]);
    } else {
      dfs(to, v);
      fup[v] = min(fup[v], fup[to]);
      if (fup[to] > tin[v]) {
        key[{to, v}] = 1;
        key[{v, to}] = 1;
        node.push_back({v, to});
      }
    }
  }
}
void dfs1(int v, int p) {
  cnt[ind]++;
  tag[v] = ind;
  used[v] = 1;
  for (int to : g[v]) {
    if (used[to] && to != p && tag[v] == tag[to]) {
      int x = wow[{to, v}];
      ord[x] = {v, to};
    }
  }
  for (int to : g[v]) {
    if (to == p) continue;
    if (!used[to] && !key[{to, v}]) {
      int x = wow[{to, v}];
      ord[x] = {v, to};
      dfs1(to, v);
    }
  }
}
void dfs2(int v, int p) {
  used[v] = 1;
  for (int to : g[v]) {
    if (p == to) continue;
    if (!used[to]) {
      if (key[{v, to}]) {
        int x = wow[{v, to}];
        ord[x] = {to, v};
      }
      dfs2(to, v);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    wow[{u, v}] = i;
    wow[{v, u}] = i;
    ord[i] = {u, v};
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1);
  int kek = 0;
  fill(used + 1, used + n + 1, false);
  for (int i = 1; i <= n; i++) {
    if (!used[i]) {
      ind++;
      dfs1(i, i);
      if (ans < cnt[ind]) {
        ans = max(ans, cnt[ind]);
        kek = ind;
      }
    }
  }
  fill(used + 1, used + n + 1, false);
  for (int i = 1; i <= n; i++) {
    if (!used[i] && tag[i] == kek) {
      dfs2(i, i);
      break;
    }
  }
  cout << ans << '\n';
  for (int i = 1; i <= m; i++) {
    cout << ord[i].first << ' ' << ord[i].second << '\n';
  }
  return 0;
}
