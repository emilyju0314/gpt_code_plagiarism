#include <bits/stdc++.h>
const int MAXN = 2e5 + 10;
const double eps = 1e-8;
const long long inf = 1e18;
using namespace std;
struct edge {
  int t, v;
  edge *next;
} e[MAXN << 2], *h[MAXN], *o = e;
void add(int x, int y, int vul) {
  o->t = y;
  o->v = vul;
  o->next = h[x];
  h[x] = o++;
}
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return x * f;
}
typedef struct node {
  int v;
  long long d;
  friend bool operator<(node aa, node bb) { return aa.d > bb.d; }
} node;
long long dis[MAXN];
priority_queue<node> que;
int n, m, s;
void dij() {
  for (int i = 1; i <= n; i++) dis[i] = inf;
  dis[s] = 0;
  que.push((node){s, 0});
  while (!que.empty()) {
    node t = que.top();
    que.pop();
    for (edge *j = h[t.v]; j; j = j->next) {
      if (dis[j->t] > dis[t.v] + j->v) {
        dis[j->t] = dis[t.v] + j->v;
        que.push((node){j->t, dis[j->t]});
      }
    }
  }
}
vector<int> vec[MAXN], v1[MAXN];
int du[MAXN], f[MAXN][21], dep[MAXN];
queue<int> q;
int Lca(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  int tmp = dep[u] - dep[v];
  for (int i = 0; i <= 20; i++)
    if (tmp & (1 << i)) u = f[u][i];
  if (u == v) return u;
  for (int i = 20; i >= 0; i--) {
    if (f[u][i] != f[v][i]) u = f[u][i], v = f[v][i];
  }
  return f[u][0];
}
int size[MAXN];
void dfs(int x) {
  size[x] = 1;
  for (edge *j = h[x]; j; j = j->next) dfs(j->t), size[x] += size[j->t];
}
int main() {
  n = read();
  m = read();
  s = read();
  int u, v, k;
  for (int i = 1; i <= m; i++)
    u = read(), v = read(), k = read(), add(u, v, k), add(v, u, k);
  dij();
  for (int i = 1; i <= n; i++) {
    for (edge *j = h[i]; j; j = j->next) {
      if (dis[i] + j->v == dis[j->t])
        vec[i].push_back(j->t), du[j->t]++, v1[j->t].push_back(i);
    }
  }
  memset(h, 0, sizeof(h));
  o = e;
  q.push(s);
  f[s][0] = 0;
  dep[s] = 1;
  while (!q.empty()) {
    int t = q.front();
    q.pop();
    for (int i = 0; i < vec[t].size(); i++) {
      du[vec[t][i]]--;
      if (!du[vec[t][i]]) {
        q.push(vec[t][i]);
        v = vec[t][i];
        int lca = t;
        for (int j = 0; j < v1[v].size(); j++) lca = Lca(lca, v1[v][j]);
        f[v][0] = lca;
        dep[v] = dep[lca] + 1;
        add(lca, v, 0);
        for (int j = 1; j <= 20; j++) f[v][j] = f[f[v][j - 1]][j - 1];
      }
    }
  }
  dfs(s);
  int maxx = 0;
  for (int i = 1; i <= n; i++)
    if (i != s) maxx = max(maxx, size[i]);
  printf("%d\n", maxx);
}
