#include <bits/stdc++.h>
using namespace std;
const int iinf = 1e9 + 7;
const long long linf = 1ll << 60;
const double dinf = 1e10;
template <typename T>
inline void scf(T &x) {
  bool f = 0;
  x = 0;
  char c = getchar();
  while ((c < '0' || c > '9') && c != '-') c = getchar();
  if (c == '-') {
    f = 1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  if (f) x = -x;
  return;
}
template <typename T1, typename T2>
void scf(T1 &x, T2 &y) {
  scf(x);
  return scf(y);
}
template <typename T1, typename T2, typename T3>
void scf(T1 &x, T2 &y, T3 &z) {
  scf(x);
  scf(y);
  return scf(z);
}
template <typename T1, typename T2, typename T3, typename T4>
void scf(T1 &x, T2 &y, T3 &z, T4 &w) {
  scf(x);
  scf(y);
  scf(z);
  return scf(w);
}
const int N = 2e5 + 100;
const int lgN = 18;
const long long mod = (1ll << 30) - 1ll;
int n, q;
vector<pair<int, long long> > g[N];
long long d_rt[N];
int dep[N], par[N][lgN];
int id[N], rnk[N];
struct item {
  int u, cnt;
  long long d1, s1, d2, s2;
  item() {}
  item(int U, long long D1, long long D2) : u(U), d1(D1), d2(D2) {
    s1 = s2 = 0;
    cnt = 0;
  }
  item(int U, int CNT, long long D1, long long S1, long long D2, long long S2)
      : u(U), cnt(CNT), d1(D1), s1(S1), d2(D2), s2(S2) {}
  bool operator<(const item &a) const { return id[u] < id[a.u]; }
  bool operator<=(const item &a) const { return id[u] <= id[a.u]; }
  bool operator>(const item &a) const { return id[u] > id[a.u]; }
  bool operator>=(const item &a) const { return id[u] >= id[a.u]; }
  bool operator==(const item &a) const { return id[u] == id[a.u]; }
  bool operator!=(const item &a) const { return id[u] != id[a.u]; }
};
vector<item> all[N];
vector<int> pth[N];
vector<long long> dst[N];
bool vis[N];
inline void pre_dfs(const int &u = 1, const int &fa = 0) {
  par[u][0] = fa;
  dep[u] = dep[fa] + 1;
  for (int i = 0; i < (lgN - 1); i++) par[u][i + 1] = par[par[u][i]][i];
  for (auto e : g[u]) {
    int &v = e.first;
    if (v != fa) {
      d_rt[v] = d_rt[u] + e.second;
      pre_dfs(v, u);
    }
  }
  return;
}
inline void SWAP(int &x, int &y) {
  x ^= y;
  y ^= x;
  x ^= y;
  return;
}
inline int lca(int u, int v) {
  if (dep[u] < dep[v]) SWAP(u, v);
  int dlt = dep[u] - dep[v];
  for (int i = 0; i < (lgN); i++) {
    if (dlt & 1) u = par[u][i];
    dlt >>= 1;
  }
  if (u == v) return u;
  for (int i = (lgN - 1); i >= (0); i--)
    if (par[u][i] != par[v][i]) u = par[u][i], v = par[v][i];
  return par[u][0];
}
inline long long get_d(int u, int v) {
  return d_rt[u] + d_rt[v] - (d_rt[lca(u, v)] << 1);
}
inline void chk_max(int &x, const int &y) {
  if (y > x) x = y;
  return;
}
inline int centroid(const int &u) {
  static int sz[N], hs[N], q[N], par[N];
  int fnt, rar;
  fnt = rar = 0;
  q[rar++] = u;
  par[u] = 0;
  while (fnt != rar) {
    int &u = q[fnt++];
    sz[u] = 1;
    hs[u] = 0;
    for (auto e : g[u]) {
      int &v = e.first;
      if (!vis[v] && v != par[u]) {
        par[v] = u;
        q[rar++] = v;
      }
    }
  }
  for (int i = (rar - 1); i >= (0); i--) {
    int &u = q[i], &v = par[u];
    chk_max(hs[u], rar - sz[u]);
    if ((hs[u] << 1) <= rar) return u;
    sz[v] += sz[u];
    chk_max(hs[v], sz[u]);
  }
  return 0;
}
inline void SWAP(long long &x, long long &y) {
  x ^= y;
  y ^= x;
  x ^= y;
  return;
}
inline void SWAP(item &x, item &y) {
  SWAP(x.u, y.u);
  SWAP(x.d1, y.d1);
  SWAP(x.d2, y.d2);
  return;
}
inline void doit(const int &u, const int &fa, int rt, int rt_fa) {
  pth[u].push_back(rt);
  all[rt].push_back(item(u, get_d(u, rt), (rt_fa ? get_d(u, rt_fa) : 0)));
  for (auto e : g[u]) {
    int &v = e.first;
    if (!vis[v] && v != fa) doit(v, u, rt, rt_fa);
  }
  return;
}
inline void dfs(int u = 1, int fa = 0) {
  u = centroid(u);
  for (auto e : g[u]) {
    int &v = e.first;
    if (!vis[v]) doit(v, u, u, fa);
  }
  pth[u].push_back(u);
  all[u].push_back(item(u, 0, fa ? get_d(u, fa) : 0));
  vis[u] = 1;
  for (auto e : g[u]) {
    int &v = e.first;
    if (!vis[v]) dfs(v, u);
  }
  return;
}
inline long long query(const int &u, const int &x) {
  long long ret = 0;
  for (int i = ((int)pth[u].size() - 1); i >= (0); i--) {
    int &v = pth[u][i];
    if (id[all[v][0].u] <= x) {
      auto it = lower_bound(all[v].begin(), all[v].end(), item(rnk[x], 0, 0));
      if (it == all[v].end() || id[it->u] > x) it--;
      ret += (dst[u][i] - (i ? dst[u][i - 1] : 0)) * (long long)it->cnt;
      ret += it->s1 - it->s2;
    }
  }
  return ret;
}
int main() {
  scf(n, q);
  for (int i = (1); i <= (n); i++) scf(rnk[i]), id[rnk[i]] = i;
  for (int i = 0; i < (n - 1); i++) {
    int u, v;
    long long w;
    scf(u, v, w);
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  pre_dfs();
  dfs();
  for (int i = (1); i <= (n); i++) {
    sort(all[i].begin(), all[i].end());
    long long s1 = 0, s2 = 0;
    int cnt = 0;
    for (int _ = 0; _ < ((int)all[i].size()); _++) {
      item &t = all[i][_];
      s1 += t.d1;
      s2 += t.d2;
      cnt++;
      t.s1 = s1;
      t.s2 = s2;
      t.cnt = cnt;
    }
    for (int &v : pth[i]) dst[i].push_back(get_d(v, i));
  }
  long long ans = 0;
  while (q--) {
    int opr;
    scf(opr);
    if (opr == 1) {
      int l, r, v;
      scf(l, r, v);
      l = (int)((long long)l ^ (ans & mod));
      r = (int)((long long)r ^ (ans & mod));
      v = (int)((long long)v ^ (ans & mod));
      ans = query(v, r);
      if (l > 1) ans -= query(v, l - 1);
      printf("%I64d\n", ans);
    } else {
      int x;
      scf(x);
      x = (int)((long long)x ^ (ans & mod));
      int &u = rnk[x];
      for (int &v : pth[u]) {
        auto it =
            lower_bound(all[v].begin(), all[v].end(), item(rnk[x + 1], 0, 0));
        if (it == all[v].end() || id[it->u] > x + 1) it--;
        if (id[it->u] == x + 1) {
          int i = it - all[v].begin() - 1;
          long long s1 = 0, s2 = 0;
          int cnt = 0;
          if (i)
            s1 = all[v][i - 1].s1, s2 = all[v][i - 1].s2,
            cnt = all[v][i - 1].cnt;
          SWAP(all[v][i], all[v][i + 1]);
          s1 += all[v][i].d1;
          s2 += all[v][i].d2;
          cnt++;
          all[v][i].s1 = s1;
          all[v][i].s2 = s2;
          all[v][i].cnt = cnt;
          ++i;
          s1 += all[v][i].d1;
          s2 += all[v][i].d2;
          cnt++;
          all[v][i].s1 = s1;
          all[v][i].s2 = s2;
          all[v][i].cnt = cnt;
        } else
          break;
      }
      id[u] = x + 1;
      id[rnk[x + 1]] = x;
      SWAP(rnk[x], rnk[x + 1]);
    }
  }
  return 0;
}
