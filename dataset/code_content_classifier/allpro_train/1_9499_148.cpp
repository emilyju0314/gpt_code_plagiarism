#include <bits/stdc++.h>
using namespace std;
inline int in() {
  int32_t x;
  scanf("%d", &x);
  return x;
}
inline long long lin() {
  long long x;
  scanf("%lld", &x);
  return x;
}
inline string get() {
  char ch[1000010];
  scanf("%s", ch);
  return ch;
}
const int MAX_LG = 40;
const long long maxn = 1e5 + 100;
const long long base = 29;
const long long mod = 1e9 + 7;
const long long INF = 1e18 + 100;
struct edge {
  long long v, u, c, id;
  edge() {}
  edge(long long v, long long u, long long c, long long id)
      : v(v), u(u), c(c), id(id) {}
  inline bool operator<(const edge &b) const { return c < b.c; }
} e[maxn];
long long sz[maxn];
long long pr[maxn];
vector<pair<long long, long long> > g[maxn];
long long pre[maxn];
inline long long root(long long x) {
  return pr[x] == x ? x : pr[x] = root(pr[x]);
}
bool mark[maxn];
long long res;
long long Sz[maxn];
vector<long long> q;
inline void dfs(long long v) {
  mark[v] = true;
  Sz[v] = sz[v];
  for (auto u : g[v]) {
    if (!mark[u.first]) {
      dfs(u.first);
      pre[u.first] = u.second;
      Sz[v] += Sz[u.first];
    }
  }
  q.push_back(v);
}
long long ans[maxn];
int32_t main() {
  long long n = in();
  for (long long i = 0; i < n - 1; i++) {
    e[i] = {in(), in(), in(), i};
  }
  for (long long i = 1; i <= n; i++) sz[i] = 1, pr[i] = i;
  sort(e, e + n - 1);
  for (long long i = 0; i < n - 1; i++) {
    long long j = i;
    while (j < n - 1 && e[j].c == e[i].c) j++;
    for (long long pt = i; pt < j; pt++) {
      long long rootA = root(e[pt].v);
      long long rootB = root(e[pt].u);
      g[rootA].push_back({rootB, e[pt].id});
      g[rootB].push_back({rootA, e[pt].id});
    }
    for (long long pt = i; pt < j; pt++) {
      long long rootA = root(e[pt].v);
      if (mark[rootA]) continue;
      pre[rootA] = -1;
      q.clear();
      dfs(rootA);
      long long tot = Sz[rootA];
      for (auto v : q) {
        if (pre[v] == -1) continue;
        ans[pre[v]] = 2 * Sz[v] * (tot - Sz[v]);
        res = max(res, ans[pre[v]]);
      }
    }
    for (long long pt = i; pt < j; pt++) {
      long long rootA = root(e[pt].v);
      long long rootB = root(e[pt].u);
      g[rootA].clear();
      g[rootB].clear();
      mark[rootA] = mark[rootB] = false;
    }
    for (long long pt = i; pt < j; pt++) {
      long long rootA = root(e[pt].v);
      long long rootB = root(e[pt].u);
      pr[rootA] = rootB;
      if (rootA != rootB) {
        sz[rootB] += sz[rootA];
        sz[rootA] = 0;
      }
    }
    i = j - 1;
  }
  cout << res << " " << count(ans, ans + n - 1, res) << "\n";
  for (long long i = 0; i < n - 1; i++)
    if (ans[i] == res) cout << i + 1 << "\n";
}
