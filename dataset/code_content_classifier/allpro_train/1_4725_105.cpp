#include <bits/stdc++.h>
using namespace std;
namespace Patchouli {
const int N = 114514;
const int inf = 998244353;
int s, t;
int head[N], ver[N], next[N], edge[N], cost[N], tot = 1;
int dis[N], pre[N], incf[N];
bool vis[N];
int deg[N];
int ans;
inline void add(int x, int y, int z, int c) {
  next[++tot] = head[x], head[x] = tot, ver[tot] = y, edge[tot] = z,
  cost[tot] = c;
  next[++tot] = head[y], head[y] = tot, ver[tot] = x, edge[tot] = 0,
  cost[tot] = -c;
}
inline bool SPFA() {
  queue<int> q;
  for (int i = 1; i <= t; ++i) dis[i] = inf;
  dis[s] = 0;
  vis[s] = true;
  incf[s] = inf;
  q.push(s);
  while (q.size()) {
    int x = q.front();
    q.pop();
    vis[x] = false;
    for (int i = head[x]; i; i = next[i]) {
      if (edge[i] && dis[x] + cost[i] < dis[ver[i]]) {
        dis[ver[i]] = dis[x] + cost[i];
        incf[ver[i]] = min(incf[x], edge[i]);
        pre[ver[i]] = i;
        if (!vis[ver[i]]) vis[ver[i]] = true, q.push(ver[i]);
      }
    }
  }
  return dis[t] ^ inf;
}
inline void update() {
  int x = t;
  while (x ^ s) {
    int i = pre[x];
    edge[i] -= incf[t];
    edge[i ^ 1] += incf[t];
    x = ver[i ^ 1];
  }
  ans += incf[t] * dis[t];
}
inline int read() {
  int a = 1, b = 0;
  char t;
  do {
    t = getchar();
    if (t == '-') a = -1;
  } while (t > '9' || t < '0');
  do {
    b = b * 10 - '0' + t;
    t = getchar();
  } while (t >= '0' && t <= '9');
  return a * b;
}
int QAQ() {
  int n = read(), m = read();
  s = n + 1, t = s + 1;
  add(n, 1, inf, 0);
  for (int i = 1; i <= m; ++i) {
    int x = read(), y = read(), c = read(), f = read();
    deg[y] += f;
    deg[x] -= f;
    if (c >= f) {
      add(y, x, f, 1);
      add(x, y, c - f, 1);
      add(x, y, inf, 2);
    } else {
      ans += f - c;
      add(y, x, c, 1);
      add(y, x, f - c, 0);
      add(x, y, inf, 2);
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (deg[i] > 0)
      add(s, i, deg[i], 0);
    else
      add(i, t, -deg[i], 0);
  }
  while (SPFA()) update();
  printf("%d\n", ans);
  return false;
}
}  // namespace Patchouli
int main() { return Patchouli::QAQ(); }
