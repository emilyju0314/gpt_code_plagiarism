#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N], h[N], dw[N], up[N], sz[N], pw[N] = {1}, inv[N], MOD, B, X, n;
long long in[N], out[N];
bool mark[N];
vector<int> g[N];
map<int, int> cnt, tnc;
int mul(int a, int b) { return 1ll * a * b % MOD; }
int sum(int a, int b) { return a + b - (a + b >= MOD ? MOD : 0); }
int Pow(int a, int b) {
  int res = 1;
  for (; b; b >>= 1, a = mul(a, a))
    if (b & 1) res = mul(res, a);
  return res;
}
void dfs_size(int v, int p = 0) {
  sz[v] = 1;
  for (int u : g[v])
    if (u != p && !mark[u]) dfs_size(u, v), sz[v] += sz[u];
  return;
}
int centr(int v, int m, int p = 0) {
  for (int u : g[v])
    if (u != p && !mark[u] && sz[u] * 2 > m) return centr(u, m, v);
  return v;
}
void dfs_calc(int v, int p = 0) {
  h[v] = h[p] + 1;
  dw[v] = sum(dw[p], mul(pw[h[v] - 1], a[v]));
  up[v] = sum(mul(up[p], B), a[v]);
  cnt[dw[v]]++, tnc[mul(sum(X, MOD - up[v]), inv[h[v]])]++;
  for (int u : g[v])
    if (u != p && !mark[u]) dfs_calc(u, v);
}
void Clear(int v, int p = 0) {
  cnt[dw[v]]--, tnc[mul(sum(X, MOD - up[v]), inv[h[v]])]--;
  for (int u : g[v])
    if (u != p && !mark[u]) Clear(u, v);
}
void Add(int v, int p = 0) {
  cnt[dw[v]]++, tnc[mul(sum(X, MOD - up[v]), inv[h[v]])]++;
  for (int u : g[v])
    if (u != p && !mark[u]) Add(u, v);
}
void Solve(int v, int p = 0, int Up = 0, int Dw = 0) {
  Up = sum(mul(Up, B), a[v]);
  Dw = sum(Dw, mul(pw[h[v] - 2], a[v]));
  in[v] += tnc[Dw], out[v] += cnt[mul(sum(X, MOD - Up), inv[h[v] - 1])];
  for (int u : g[v])
    if (u != p && !mark[u]) Solve(u, v, Up, Dw);
}
void Decompose(int v) {
  queue<int> q;
  q.push(v);
  while (!q.empty()) {
    v = q.front(), q.pop();
    dfs_size(v), dfs_calc(v = centr(v, sz[v]));
    mark[v] = 1;
    for (int u : g[v])
      if (!mark[u]) Clear(u), Solve(u), Add(u), q.push(u);
    out[v] += cnt[X], in[v] += tnc[0];
    cnt.clear(), tnc.clear();
  }
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> MOD >> B >> X;
  for (int i = 1; i < N; i++) pw[i] = mul(pw[i - 1], B);
  inv[N - 1] = Pow(pw[N - 1], MOD - 2);
  for (int i = N - 2; i >= 0; i--) inv[i] = mul(inv[i + 1], B);
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v), g[v].push_back(u);
  }
  Decompose(1);
  long long p = 0;
  for (int v = 1; v <= n; v++)
    p += in[v] * (n - out[v]) + (n - in[v]) * out[v] +
         2 * (in[v] * (n - in[v]) + out[v] * (n - out[v]));
  cout << 1ll * n * n * n - p / 2 << "\n";
  return 0;
}
