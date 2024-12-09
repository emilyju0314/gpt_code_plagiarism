#include <bits/stdc++.h>
using namespace std;
vector<int> adj[200200];
bool rev[200200];
int pa[200200], son[200200][2], val[200200], sz[200200], flag[200200];
int mx[200200];
int B[200200 << 1], N;
void update(int u, int d) {
  for (; u <= N; u += u & -u) B[u] += d;
}
int calc(int u, int ans = 0) {
  for (; u; u -= u & -u) ans += B[u];
  return ans;
}
void push_up(int first) {
  sz[first] = sz[son[first][0]] + sz[son[first][1]] + 1;
}
void push_down(int first) {
  if (rev[first]) {
    swap(son[first][0], son[first][1]);
    rev[son[first][0]] ^= 1;
    rev[son[first][1]] ^= 1;
    rev[first] = 0;
  }
  if (flag[first]) {
    flag[son[first][0]] = mx[son[first][0]] = flag[first];
    flag[son[first][1]] = mx[son[first][1]] = flag[first];
    flag[first] = 0;
  }
}
bool isroot(int first) {
  return son[pa[first]][0] != first && son[pa[first]][1] != first;
}
void down(int first) {
  if (!isroot(first)) down(pa[first]);
  push_down(first);
}
void rot(int first, int d) {
  int second = pa[first], z = pa[second];
  son[second][!d] = son[first][d];
  pa[son[first][d]] = second;
  pa[first] = pa[second];
  if (son[z][0] == second)
    son[z][0] = first;
  else if (son[z][1] == second)
    son[z][1] = first;
  pa[second] = first;
  son[first][d] = second;
  push_up(second);
}
void splay(int first) {
  down(first);
  while (!isroot(first)) {
    if (isroot(pa[first]))
      rot(first, son[pa[first]][0] == first);
    else {
      int second = pa[first], z = pa[second];
      int d = (son[z][0] == second);
      son[second][d] == first ? rot(first, !d) : rot(second, d);
      rot(first, d);
    }
  }
  push_up(first);
}
void access(int first, int val) {
  for (int second = 0; first; first = pa[first]) {
    splay(first);
    update(mx[first], -(sz[son[first][0]] + 1));
    flag[first] = mx[first] = val;
    update(mx[first], sz[son[first][0]] + 1);
    son[first][1] = second;
    push_up(second = first);
  }
}
void dfs(int u, int f = 0) {
  pa[u] = f;
  mx[u] = u;
  for (int v : adj[u]) {
    if (v == f) continue;
    dfs(v, u);
    mx[u] = max(mx[u], mx[v]);
  }
  for (int v : adj[u]) {
    if (v == f) continue;
    if (mx[u] == mx[v]) {
      son[u][1] = v;
      sz[u] = sz[v] + 1;
    }
  }
  update(mx[u], 1);
}
int query(int u) {
  splay(u);
  push_down(u);
  return calc(mx[u]) - sz[son[u][0]];
}
int main() {
  int n, m;
  cin >> n >> m;
  N = n + m;
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(n);
  int cur = n;
  char s[11];
  int u, v;
  while (m--) {
    scanf("%s %d", s, &u);
    if (s[0] == 'u') {
      access(u, cur);
      splay(u);
      rev[u] ^= 1;
      update(cur, -1);
      push_down(u);
      son[u][1] = 0;
      push_up(u);
      update(mx[u] = ++cur, 1);
    } else if (s[0] == 'w') {
      printf("%d\n", query(u));
    } else {
      scanf("%d", &v);
      printf("%d\n", query(u) < query(v) ? u : v);
    }
  }
  return 0;
}
