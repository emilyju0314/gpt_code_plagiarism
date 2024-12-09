#include <bits/stdc++.h>
using namespace std;
const int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
const double pi = acos(-1);
const int INF = 0x3f3f3f3f;
int n, m, k;
struct egde {
  int to, next, w;
} e[N];
int head[N], tot;
void add(int u, int v, int w) {
  e[++tot] = {v, head[u], w};
  head[u] = tot;
}
const int Depth = 20;
queue<int> q;
int d[N];
int f[N][Depth + 10];
int up[N];
void bfs(int root) {
  queue<int> q;
  d[root] = 0;
  f[root][0] = root;
  up[root] = 0;
  q.push(root);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 1; i <= Depth; ++i) {
      f[u][i] = f[f[u][i - 1]][i - 1];
    }
    for (int i = head[u]; i; i = e[i].next) {
      int v = e[i].to;
      if (v == f[u][0]) continue;
      d[v] = d[u] + 1;
      f[v][0] = u;
      up[v] = -e[i].w;
      q.push(v);
    }
  }
}
int lca(int u, int v) {
  if (d[u] < d[v]) swap(u, v);
  for (int i = Depth; i >= 0; --i) {
    if (d[f[u][i]] >= d[v]) u = f[u][i];
  }
  if (u == v) return u;
  for (int i = Depth; i >= 0; --i) {
    if (f[u][i] != f[v][i]) {
      u = f[u][i];
      v = f[v][i];
    }
  }
  return f[u][0];
}
int cnt1[N], cnt2[N];
void dfs(int u) {
  for (int i = head[u]; i; i = e[i].next) {
    int v = e[i].to;
    if (v == f[u][0]) continue;
    dfs(v);
    cnt1[u] += cnt1[v];
    cnt2[u] += cnt2[v];
  }
}
long long qpow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
int main() {
  ios::sync_with_stdio(0);
  memset(head, -1, sizeof(head));
  cin >> n;
  for (int i = 1, u, v, w; i < n; ++i) {
    cin >> u >> v >> w;
    add(u, v, w);
    add(v, u, -w);
  }
  bfs(1);
  cin >> k;
  int last = 1, now;
  for (int i = 1; i <= k; ++i) {
    cin >> now;
    if (last == now) continue;
    int top = lca(last, now);
    cnt1[last]++;
    cnt1[top]--;
    cnt2[now]++;
    cnt2[top]--;
    last = now;
  }
  dfs(1);
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (!up[i]) continue;
    if (up[i] == -1) {
      ans = (ans + qpow(2, cnt1[i]) - 1) % mod;
    } else {
      ans = (ans + qpow(2, cnt2[i]) - 1) % mod;
    }
  }
  cout << ((ans + mod) % mod) << endl;
  return 0;
}
