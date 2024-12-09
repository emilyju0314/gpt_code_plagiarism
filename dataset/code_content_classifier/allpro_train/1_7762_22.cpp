#include <bits/stdc++.h>
using namespace std;
const int N = 50 * 3 + 12;
int inq[N], d[N], x[N][N], f[N][N], c[N][N], n, S, T, par[N];
vector<int> ed[N];
bool fb() {
  queue<int> q;
  memset(inq, 0, sizeof(inq));
  memset(par, 0, sizeof(par));
  for (int i = 1; i <= T; ++i) d[i] = 1e8;
  q.push(S);
  d[S] = 0;
  inq[S] = 1;
  int u, tg;
  while (!q.empty()) {
    u = q.front();
    q.pop();
    inq[u] = 0;
    for (int v : ed[u]) {
      if (v != u) {
        if (x[u][v] > f[u][v]) {
          tg = 0;
          if (f[u][v] >= 0)
            tg = c[u][v];
          else
            tg = 0 - c[u][v];
          if (d[v] > d[u] + tg) {
            d[v] = d[u] + tg;
            par[v] = u;
            q.push(v);
            inq[v] = 1;
          }
        }
      }
    }
  }
  if (d[T] < int(1e8))
    return 1;
  else
    return 0;
}
int res;
int sol(int delta) {
  int v;
  v = T;
  while (v != S) {
    if (f[par[v]][v] < 0)
      delta = min(delta, 0 - f[par[v]][v]);
    else
      delta = min(delta, x[par[v]][v] - f[par[v]][v]);
    v = par[v];
  }
  v = T;
  while (v != S) {
    f[par[v]][v] += delta;
    f[v][par[v]] -= delta;
    v = par[v];
  }
  res += delta * d[T];
  return delta;
}
int a[N], b[N], p, q;
void add(int u, int v) {
  ed[u].push_back(v);
  ed[v].push_back(u);
}
struct node {
  int type, l, r, val;
} in[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= q; ++i) {
    int type, l, r, val;
    cin >> type >> l >> r >> val;
    in[i] = {type, l, r, val};
  }
  S = n + n + n + 1;
  T = n + n + n + 2;
  for (int i = 1; i <= n; ++i) {
    add(i, S);
    x[S][i] = 1;
    int L, R;
    L = 1;
    R = n;
    for (int j = 1; j <= q; ++j) {
      if (i >= in[j].l && i <= in[j].r) {
        if (in[j].type == 1)
          L = max(L, in[j].val);
        else
          R = min(R, in[j].val);
      }
    }
    if (R < L) {
      cout << -1;
      return 0;
    }
    for (int j = L; j <= R; ++j) {
      add(i, n + j);
      x[i][n + j] = 1;
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      add(i + n, j + n + n);
      x[i + n][j + n + n] = 1;
      c[i + n][j + n + n] = 2 * j - 1;
      c[j + n + n][i + n] = 2 * j - 1;
    }
  }
  for (int i = 1; i <= n; ++i) {
    add(i + n + n, T);
    x[i + n + n][T] = 1e9;
  }
  int sz = n;
  while (fb()) {
    sz -= sol(sz);
    if (sz <= 0) break;
  }
  cout << res;
  return 0;
}
