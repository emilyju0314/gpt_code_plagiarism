#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")
struct MCMF {
  int fst[(30000 + 10)], nxt[(410000 + 10)], vv[(410000 + 10)],
      from[(410000 + 10)], cost[(410000 + 10)], cap[(410000 + 10)],
      flow[(410000 + 10)], e;
  int d[(30000 + 10)], a[(30000 + 10)], p[(30000 + 10)], in[(30000 + 10)];
  void init() {
    memset(fst, -1, sizeof fst);
    e = 0;
  }
  void add(int u, int v, int c, int d) {
    from[e] = u, vv[e] = v, nxt[e] = fst[u], cost[e] = d, cap[e] = c,
    flow[e] = 0, fst[u] = e++;
    from[e] = v, vv[e] = u, nxt[e] = fst[v], cost[e] = -d, cap[e] = 0,
    flow[e] = 0, fst[v] = e++;
  }
  int spfa(int s, int t, int &mf, int &mc) {
    memset(d, 0x3f, sizeof d);
    d[s] = p[s] = 0;
    a[s] = 0x3f3f3f3f;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      in[u] = 0;
      for (int i = fst[u]; ~i; i = nxt[i]) {
        int v = vv[i], c = cost[i];
        if (cap[i] > flow[i] && d[v] > d[u] + c) {
          d[v] = d[u] + c;
          a[v] = min(a[u], cap[i] - flow[i]);
          p[v] = i;
          if (!in[v]) in[v] = 1, q.push(v);
        }
      }
    }
    if (d[t] == 0x3f3f3f3f) return 0;
    mf += a[t], mc += a[t] * d[t];
    int u = t;
    while (u != s) {
      flow[p[u]] += a[t];
      flow[p[u] ^ 1] -= a[t];
      u = from[p[u]];
    }
    return 1;
  }
  int gao(int s, int t, int tot) {
    int ret = 0, mf = 0, mc = 0;
    while (spfa(s, t, mf, mc))
      ;
    if (tot != mf) return -1;
    return mc;
  }
};
struct dinic {
  int fst[(30000 + 10)], vv[(410000 + 10)], nxt[(410000 + 10)], e,
      cap[(410000 + 10)], flow[(410000 + 10)];
  int s, t;
  int d[(30000 + 10)], cur[(30000 + 10)];
  void init() {
    memset(fst, -1, sizeof fst);
    e = 0;
  }
  void add(int u, int v, int w) {
    vv[e] = v, nxt[e] = fst[u], cap[e] = w, flow[e] = 0, fst[u] = e++;
    vv[e] = u, nxt[e] = fst[v], cap[e] = 0, flow[e] = 0, fst[v] = e++;
  }
  bool bfs() {
    queue<int> que;
    memset(d, -1, sizeof d);
    que.push(s);
    d[s] = 0;
    while (!que.empty()) {
      int u = que.front();
      que.pop();
      for (int i = fst[u]; ~i; i = nxt[i]) {
        int v = vv[i];
        if (d[v] == -1 && cap[i] > flow[i]) {
          d[v] = d[u] + 1;
          que.push(v);
        }
      }
    }
    return d[t] != -1;
  }
  int dfs(int u, int a) {
    if (u == t || a == 0) return a;
    int f, ret = 0;
    for (int &i = cur[u]; ~i; i = nxt[i]) {
      int v = vv[i];
      if (d[v] == d[u] + 1 && (f = dfs(v, min(cap[i] - flow[i], a))) > 0) {
        ret += f;
        a -= f;
        flow[i] += f;
        flow[i ^ 1] -= f;
        if (a == 0) break;
      }
    }
    return ret;
  }
  int gao(int S, int T) {
    s = S, t = T;
    int ans = 0;
    while (bfs()) {
      memcpy(cur, fst, sizeof fst);
      ans += dfs(s, 0x3f3f3f3f);
    }
    return ans;
  }
} go;
char s[100];
int m, n;
int g[10][10], id[10][10];
int num[10];
bool vis[10];
int P[10];
int inu[(410000 + 10)], inv[(410000 + 10)];
struct edge {
  int u, v;
  edge(){};
  edge(int uu, int vv) { u = uu, v = vv; }
} e[(410000 + 10)];
int tot;
int get(int x) {
  int ans = 0;
  while (x) {
    ++ans;
    x /= 10;
  }
  return ans;
}
vector<edge> ans[10][10];
void out() {
  for (int i = 0; i < tot; ++i) {
    int tu = get(e[i].u), tv = get(e[i].v);
    if (tu > tv) swap(tu, tv);
    ans[tu][tv].push_back(e[i]);
  }
  for (int i = 1; i < n; ++i) {
    edge tmp = ans[inu[i]][inv[i]].back();
    ans[inu[i]][inv[i]].pop_back();
    printf("%d %d\n", tmp.u, tmp.v);
  }
}
bool solve() {
  go.init();
  int s = 0, t = m * m + m + 1;
  int tid = m;
  for (int i = 1; i <= m; ++i) {
    for (int j = i; j <= m; ++j) {
      id[i][j] = ++tid;
      go.add(tid, t, g[i][j]);
      go.add(i, tid, 0x3f3f3f3f);
      go.add(j, tid, 0x3f3f3f3f);
    }
  }
  for (int i = 1; i <= m; ++i) go.add(s, i, num[i] - 1);
  if (go.gao(s, t) == n - m) {
    for (int u = 1; u <= m; ++u) {
      int tmp = P[u - 1];
      for (int j = 1; j <= m; ++j) {
        for (int i = go.fst[u]; ~i; i = go.nxt[i]) {
          int v = go.vv[i];
          if (v == id[u][j])
            while (go.flow[i] > 0)
              e[tot++] = edge(++tmp, P[j - 1]), go.flow[i]--;
          if (v == id[j][u])
            while (go.flow[i] > 0)
              e[tot++] = edge(++tmp, P[j - 1]), go.flow[i]--;
        }
      }
    }
    out();
    return 1;
  }
  return 0;
}
bool dfs(int u) {
  if (u > m) {
    if (solve()) return 1;
    return 0;
  }
  for (int i = 1; i <= m; ++i) {
    if (vis[i]) continue;
    vis[i] = 1;
    for (int j = 1; j <= m; ++j) {
      if (i != j && vis[j] && g[min(i, j)][max(i, j)]) {
        int uu = min(i, j), vv = max(i, j);
        e[tot++] = edge(P[i - 1], P[j - 1]);
        g[uu][vv]--;
        if (dfs(u + 1)) return 1;
        g[uu][vv]++;
      }
    }
    vis[i] = 0;
  }
  return 0;
}
int main() {
  P[0] = 1;
  for (int i = 1; i <= 7; ++i) P[i] = P[i - 1] * 10;
  scanf("%d", &n);
  m = get(n);
  for (int i = 1; i <= n; ++i) ++num[get(i)];
  for (int i = 1; i < n; ++i) {
    scanf("%s", s);
    int u = strlen(s);
    scanf("%s", s);
    int v = strlen(s);
    if (u > v) swap(u, v);
    inu[i] = u;
    inv[i] = v;
    g[u][v]++;
  }
  vis[1] = 1;
  if (!dfs(2)) puts("-1");
}
