#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
vector<int> adj[N];
set<int> q[N];
set<pair<int, int>, greater<pair<int, int> > > remain[N];
set<pair<int, int> > lca[N];
int ans[N], fa[N];
bool flag[N];
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
int stmp[N], ss;
void dfs(int cur, int pre) {
  stmp[cur] = ++ss;
  for (int id : q[cur]) {
    if (q[pre].count(id)) flag[id] = 1;
    if (!remain[id].empty()) {
      int x = remain[id].begin()->second;
      int y = find(x);
      lca[y].insert(pair<int, int>(id, cur));
      lca[y].insert(pair<int, int>(id, x));
    }
    remain[id].insert(pair<int, int>(stmp[cur], cur));
  }
  for (int to : adj[cur])
    if (to != pre) {
      dfs(to, cur);
      fa[to] = cur;
    }
  map<int, int> m;
  for (pair<int, int> top : lca[cur]) {
    int id = top.first, x = top.second;
    if (x != cur && remain[id].count(pair<int, int>(stmp[x], x))) ++m[id];
  }
  for (pair<int, int> top : m) {
    int id = top.first, num = top.second;
    if (q[cur].count(id))
      ans[id] += num;
    else if (num >= 2)
      ++ans[id];
  }
  for (pair<int, int> top : lca[cur]) {
    int id = top.first, x = top.second;
    if (q[cur].count(id)) {
      if (x != cur) remain[id].erase(pair<int, int>(stmp[x], x));
    } else if (m[id] >= 2)
      remain[id].erase(pair<int, int>(stmp[x], x));
  }
}
int main() {
  int n, x, y, num, m;
  while (cin >> n) {
    ss = 0;
    memset(fa, 0, sizeof(fa)), memset(ans, 0, sizeof(ans)),
        memset(flag, 0, sizeof(flag));
    for (int i = (0); i <= (n); ++i)
      adj[i].clear(), q[i].clear(), lca[i].clear(), fa[i] = i;
    for (int i = 0; i < (n - 1); ++i) {
      scanf("%d%d", &x, &y);
      adj[x].push_back(y), adj[y].push_back(x);
    }
    cin >> m;
    for (int i = 0; i < (m); ++i) remain[i].clear();
    for (int i = 0; i < (m); ++i) {
      scanf("%d", &num);
      while (num--) {
        scanf("%d", &x);
        q[x].insert(i);
      }
    }
    dfs(1, 0);
    for (int i = 0; i < (m); ++i) printf("%d\n", flag[i] ? -1 : ans[i]);
  }
  return 0;
}
