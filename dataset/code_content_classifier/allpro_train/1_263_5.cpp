#include <bits/stdc++.h>
using namespace std;
const int mn = 2e5 + 5;
const int mod = 1e9 + 7;
int n, q;
int a[mn];
bool is_cycle[mn];
int cycc[mn];
vector<int> cycle[mn];
int cycnt;
int cyid[mn];
int to[mn];
int dist[mn];
vector<int> rg[mn];
int vis[mn];
vector<int> st;
void dfs(int x) {
  if (vis[x] == -1) {
    int u = ((int)st.size()) - 1;
    ++cycnt;
    while (st[u] != x) {
      is_cycle[st[u]] = 1;
      cycc[st[u]] = cycnt;
      cyid[st[u]] = cycle[cycnt].size();
      cycle[cycnt].push_back(st[u]);
      u--;
    }
    is_cycle[st[u]] = 1;
    cycc[st[u]] = cycnt;
    cyid[st[u]] = cycle[cycnt].size();
    cycle[cycnt].push_back(st[u]);
    return;
  }
  vis[x] = -1;
  st.push_back(x);
  if (vis[a[x]] != 1) {
    dfs(a[x]);
  }
  if (vis[a[x]] == 1 && cycc[a[x]] && !cycc[x]) {
    cycc[x] = cycc[a[x]];
  }
  vis[x] = 1;
  st.pop_back();
}
struct node {
  int id, dist, from;
};
vector<int> vv[mn];
void bfs() {
  queue<node> q;
  for (int i = 1; i <= n; i++) {
    if (is_cycle[i]) q.push({i, 0, i});
  }
  while (!q.empty()) {
    node u = q.front();
    q.pop();
    for (auto &p : rg[u.id]) {
      if (is_cycle[p]) continue;
      q.push({p, u.dist + 1, u.from});
      to[p] = u.from;
      dist[p] = u.dist + 1;
      vv[u.from].push_back(u.dist + 1);
    }
  }
}
struct query {
  long long m;
  int y, id, cyclecnt;
  bool operator<(const query &p) const { return cyclecnt < p.cyclecnt; }
} Q[mn];
int ans[mn];
vector<int> cyclemod[mn];
int dfsc;
int pc[mn], pe[mn];
int dep[mn];
int maxid;
vector<int> v[mn];
void dfs2(int x, int banned, int depth, int cyclesize) {
  pc[x] = ++dfsc;
  dep[x] = depth;
  maxid = max(depth, maxid);
  v[depth].push_back(pc[x]);
  if (!is_cycle[x]) cyclemod[depth % cyclesize].push_back(depth - dep[to[x]]);
  for (auto &i : rg[x]) {
    if (i != banned) {
      dfs2(i, banned, depth + 1, cyclesize);
    }
  }
  pe[x] = dfsc;
}
void build(int cnt) {
  int cysize = cycle[cnt].size();
  for (int i = 0; i < ((int)cycle[cnt].size()); i++) {
    cyclemod[i].clear();
  }
  for (int i = 0; i <= maxid; i++) v[i].clear();
  maxid = 0;
  for (auto &i : cycle[cnt]) {
    if (is_cycle[i]) {
      dfs2(i, i, 0, ((int)cycle[cnt].size()));
      break;
    }
  }
  for (int j = 0; j < ((int)cycle[cnt].size()); j++) {
    sort(cyclemod[j].begin(), cyclemod[j].end());
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    rg[a[i]].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) dfs(i);
  }
  bfs();
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    scanf("%lld%d", &Q[i].m, &Q[i].y);
    Q[i].id = i;
    Q[i].cyclecnt = cycc[Q[i].y];
  }
  sort(Q + 1, Q + q + 1);
  int lastqcy = 0;
  for (int i = 1; i <= q; i++) {
    if (lastqcy != Q[i].cyclecnt) {
      build(Q[i].cyclecnt);
      lastqcy = Q[i].cyclecnt;
    }
    if (!is_cycle[Q[i].y]) {
      Q[i].m = min(Q[i].m, (long long)1e6);
      int di = dep[Q[i].y] + Q[i].m;
      ans[Q[i].id] = upper_bound(v[di].begin(), v[di].end(), pe[Q[i].y]) -
                     lower_bound(v[di].begin(), v[di].end(), pc[Q[i].y]);
    } else {
      int idx = (cyid[Q[i].y] + Q[i].m) % ((int)cycle[lastqcy].size());
      ans[Q[i].id] =
          upper_bound(cyclemod[idx].begin(), cyclemod[idx].end(), Q[i].m) -
          begin(cyclemod[idx]) + 1;
    }
  }
  for (int i = 1; i <= q; i++) printf("%d\n", ans[i]);
  return 0;
}
