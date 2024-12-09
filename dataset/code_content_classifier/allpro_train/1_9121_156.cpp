#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
const int M = 5e3 + 10;
const int INF = 1e9;
int n, m, A, B, head[N], cnt, ans[M], dis[N], num[N], t[N];
bool inq[N], vis[N];
queue<int> q;
struct edge {
  int nxt, to, val, id;
} ed[M << 1];
vector<int> g[2][N];
inline void addedge(int x, int y, int w, int num) {
  ed[++cnt].to = y;
  ed[cnt].nxt = head[x];
  ed[cnt].val = w;
  ed[cnt].id = num;
  head[x] = cnt;
}
inline bool SPFA() {
  for (register int i = 1; i <= n; i++) dis[i] = INF;
  q.push(n);
  dis[n] = 0;
  inq[n] = true;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    inq[u] = false;
    for (register int i = head[u]; i; i = ed[i].nxt) {
      int v = ed[i].to;
      if (t[v] != 2) continue;
      if (dis[v] > dis[u] + ed[i].val) {
        dis[v] = dis[u] + ed[i].val;
        num[v] = num[u] + 1;
        if (num[v] > n) return false;
        if (!inq[v]) q.push(v), inq[v] = true;
      }
    }
  }
  return true;
}
inline void Check(int u, int num) {
  t[u]++;
  vis[u] = true;
  for (register int i = 0; i < (int)g[num][u].size(); i++)
    if (!vis[g[num][u][i]]) Check(g[num][u][i], num);
}
int main() {
  scanf("%d%d", &n, &m);
  for (register int i = 1; i <= m; i++) {
    scanf("%d%d", &A, &B);
    addedge(A, B, -1, i);
    addedge(B, A, 2, i);
    g[0][A].push_back(B), g[1][B].push_back(A);
  }
  Check(1, 0);
  memset(vis, 0, sizeof(vis));
  Check(n, 1);
  if (!SPFA()) {
    puts("No");
    return 0;
  }
  puts("Yes");
  for (register int i = 1; i <= n; i++)
    for (register int j = head[i]; j; j = ed[j].nxt)
      if (dis[ed[j].to] < dis[i] && t[i] == 2 && t[ed[j].to] == 2)
        ans[ed[j].id] = dis[i] - dis[ed[j].to];
      else if (t[i] != 2 || t[ed[j].to] != 2)
        ans[ed[j].id] = 1;
  for (register int i = 1; i <= m; i++) printf("%d\n", ans[i]);
  return 0;
}
