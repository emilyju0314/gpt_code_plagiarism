#include <bits/stdc++.h>
using namespace std;
const int mxn = 105, mxm = 1e5 + 5;
const int mod = 1e9 + 7;
int n, k;
vector<int> vecl, vecr;
vector<pair<int, int> > adj[mxn];
vector<int> subl, subr;
bool vis[mxn];
int cnte;
int id[mxn];
int fac[mxm];
vector<pair<pair<int, int>, int> > ntree;
bool used[mxn];
int dfn[mxn];
void dfs0(int u, int p = -1) {
  static int tim;
  dfn[u] = tim++;
  vis[u] = 1;
  if (u < (int)vecl.size())
    subl.push_back(u);
  else
    subr.push_back(u);
  for (int i = 0; i < (int)(adj[u].size()); ++i) {
    int v = adj[u][i].first;
    if (!vis[v])
      ++cnte, dfs0(v, u);
    else if (v != p) {
      if (dfn[u] < dfn[v]) ++cnte;
    }
  }
}
void dfs1(int u, int p = -1) {
  static int tim;
  dfn[u] = tim++;
  used[u] = 1;
  for (int i = 0; i < (int)(adj[u].size()); ++i) {
    int v = adj[u][i].first;
    int w = adj[u][i].second;
    if (!used[v])
      dfs1(v, u);
    else if (v != p) {
      if (dfn[u] < dfn[v]) {
        ntree.push_back(make_pair(make_pair(u, v), w));
      }
    }
  }
}
ostream &operator<<(ostream &out, vector<int> a) {
  out << "[";
  for (int i = 0; i < (int)(a.size()); ++i) {
    if (i) out << ", ";
    out << a[i];
  }
  out << "]";
  return out;
}
vector<int> add(vector<int> a, vector<int> b) {
  vector<int> c(max(a.size(), b.size()));
  for (int i = 0; i < (int)(a.size()); ++i) (c[i] += a[i]) %= mod;
  for (int i = 0; i < (int)(b.size()); ++i) (c[i] += b[i]) %= mod;
  return c;
}
vector<int> mul(vector<int> a, int c) {
  vector<int> b(a.size() + 1);
  for (int i = 0; i < (int)(b.size()); ++i)
    if (i) b[i] = (long long)a[i - 1] * c % mod;
  return b;
}
vector<int> merge(vector<int> a, vector<int> b) {
  vector<int> c(a.size() + b.size() - 1);
  for (int i = 0; i < (int)(a.size()); ++i)
    for (int j = 0; j < (int)(b.size()); ++j)
      (c[i + j] += (long long)a[i] * b[j] % mod) %= mod;
  return c;
}
pair<vector<int>, vector<int> > dfs2(int u, long long mask) {
  used[u] = 1;
  vector<int> f0 = {1}, f1 = {};
  for (int i = 0; i < (int)(adj[u].size()); ++i) {
    int v = adj[u][i].first;
    int w = adj[u][i].second;
    if (!used[v]) {
      pair<vector<int>, vector<int> > ret = dfs2(v, mask);
      vector<int> nf0 = merge(f0, add(ret.first, ret.second));
      vector<int> nf1 = {};
      if (!(mask >> v & 1)) nf1 = add(nf1, mul(merge(f0, ret.first), w));
      nf1 = add(nf1, merge(f1, add(ret.first, ret.second)));
      nf0.swap(f0);
      nf1.swap(f1);
    }
  }
  return make_pair(f0, mask >> u & 1 ? vector<int>() : f1);
}
int main() {
  for (int i = 0; i < (int)(mxm); ++i)
    fac[i] = i ? (long long)i * fac[i - 1] % mod : 1;
  scanf("%d %d", &n, &k);
  vector<pair<pair<int, int>, int> > E;
  for (int i = 0; i < (int)(k); ++i) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    vecl.push_back(u);
    vecr.push_back(v);
    E.push_back(make_pair(make_pair(u, v), w));
  }
  sort(vecl.begin(), vecl.end());
  vecl.erase(unique(vecl.begin(), vecl.end()), vecl.end());
  sort(vecr.begin(), vecr.end());
  vecr.erase(unique(vecr.begin(), vecr.end()), vecr.end());
  for (int i = 0; i < (int)(k); ++i) {
    int u = E[i].first.first;
    int v = E[i].first.second;
    int w = (E[i].second + mod - 1) % mod;
    u = lower_bound(vecl.begin(), vecl.end(), u) - vecl.begin();
    v = lower_bound(vecr.begin(), vecr.end(), v) - vecr.begin();
    adj[u].push_back(make_pair(v + vecl.size(), w));
    adj[v + vecl.size()].push_back(make_pair(u, w));
  }
  vector<int> ansvec = {1};
  for (int U = 0; U < (int)(vecl.size() + vecr.size()); ++U)
    if (!vis[U]) {
      subl.clear();
      subr.clear();
      cnte = 0;
      dfs0(U);
      for (int i = 0; i < (int)(subl.size()); ++i) id[subl[i]] = i;
      for (int i = 0; i < (int)(subr.size()); ++i) id[subr[i]] = i;
      if (subl.size() > subr.size()) swap(subl, subr);
      if ((cnte - subl.size() - subr.size() + 1) < subl.size()) {
        memset(used, 0, sizeof(used));
        ntree.clear();
        dfs1(subl[0]);
        vector<int> temp(subl.size() + 1);
        for (int mask = 0; mask < (int)(1 << ntree.size()); ++mask) {
          long long forb = 0;
          int cur = 1;
          bool cant = 0;
          for (int i = 0; i < (int)(ntree.size()); ++i)
            if (mask >> i & 1) {
              if (forb >> ntree[i].first.first & 1) cant = 1;
              if (forb >> ntree[i].first.second & 1) cant = 1;
              forb |= (long long)1 << ntree[i].first.first;
              forb |= (long long)1 << ntree[i].first.second;
              cur = (long long)cur * ntree[i].second % mod;
            }
          if (cant) continue;
          memset(used, 0, sizeof(used));
          pair<vector<int>, vector<int> > ret = dfs2(subl[0], forb);
          vector<int> f = add(ret.first, ret.second);
          for (int i = 0; i < (int)(f.size()); ++i) {
            int ni = i + __builtin_popcount(mask);
            (temp[ni] += (long long)cur * f[i] % mod) %= mod;
          }
        }
        ansvec = merge(ansvec, temp);
      } else {
        static int g[1 << 17][55];
        for (int mask = 0; mask < (int)(1 << subl.size()); ++mask)
          for (int i = 0; i < (int)(subr.size() + 1); ++i) g[mask][i] = 0;
        g[0][0] = 1;
        for (int mask = 0; mask < (int)(1 << subl.size()); ++mask)
          for (int i = 0; i < (int)(subr.size()); ++i)
            if (g[mask][i]) {
              (g[mask][i + 1] += g[mask][i]) %= mod;
              for (int tt = 0; tt < (int)(adj[subr[i]].size()); ++tt) {
                int v = adj[subr[i]][tt].first;
                int w = adj[subr[i]][tt].second;
                int j = id[v];
                if (!(mask >> j & 1))
                  (g[mask | 1 << j][i + 1] +=
                   (long long)w * g[mask][i] % mod) %= mod;
              }
            }
        vector<int> temp(subl.size() + 1);
        for (int mask = 0; mask < (int)(1 << subl.size()); ++mask)
          (temp[__builtin_popcount(mask)] += g[mask][subr.size()]) %= mod;
        ansvec = merge(ansvec, temp);
      }
    }
  int ans = 0;
  for (int i = 0; i < (int)(ansvec.size()); ++i)
    (ans += (long long)ansvec[i] * fac[n - i] % mod) %= mod;
  printf("%d\n", ans);
  return 0;
}
