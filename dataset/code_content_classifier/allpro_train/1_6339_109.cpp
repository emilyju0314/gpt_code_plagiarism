#include <bits/stdc++.h>
using namespace std;
const int maxn = 10000 + 10;
const int maxm = 100000 + 10;
int n, m;
struct E {
  int f, t, v;
  bool operator<(const E &a) const { return v < a.v; }
} Ea[maxm];
int head[maxn * 2];
struct Ed {
  int f, t, nxt;
} e[maxm * 2];
int edge = 1;
int dep[maxn * 2];
int con[maxn * 2];
inline void addedge(int f, int t) {
  e[edge].f = f, e[edge].t = t, e[edge].nxt = head[f], head[f] = edge++;
}
bool bfs() {
  memset(dep, 0, sizeof dep);
  queue<int> q;
  while (q.size()) q.pop();
  for (int i = 1; i <= n; ++i)
    if (con[i] == -1) q.push(i);
  bool flag = false;
  while (q.size()) {
    int u = q.front();
    q.pop();
    for (int i = head[u]; i; i = e[i].nxt) {
      int v = e[i].t;
      if (!dep[v]) {
        dep[v] = dep[u] + 1;
        if (con[v] == -1)
          flag = true;
        else
          dep[con[v]] = dep[v] + 1, q.push(con[v]);
      }
    }
  }
  return flag;
}
bool dfs(int u) {
  for (int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].t;
    if (dep[v] != dep[u] + 1) continue;
    dep[v] = 0;
    if (con[v] == -1 || dfs(con[v])) {
      con[u] = v;
      con[v] = u;
      return true;
    }
  }
  return false;
}
inline int check(int x) {
  memset(con, -1, sizeof(con));
  memset(head, 0, sizeof(head));
  edge = 1;
  for (int i = 1; i <= x; i++) addedge(Ea[i].f, Ea[i].t);
  int ans = 0;
  while (bfs()) {
    for (int i = 1; i <= n; ++i)
      if (con[i] == -1 && dfs(i)) ans++;
  }
  return ans == n;
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d %d %d", &Ea[i].f, &Ea[i].t, &Ea[i].v);
    Ea[i].t += n;
  }
  sort(Ea + 1, Ea + m + 1);
  int ok = 0;
  int l = 1, r = m;
  while (l + 1 < r) {
    int mid = (l + r) / 2;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  if (check(l)) {
    ok = 1;
    printf("%d\n", Ea[l].v);
  } else if (check(r)) {
    ok = 1;
    printf("%d\n", Ea[r].v);
  }
  if (!ok) puts("-1");
  return 0;
}
