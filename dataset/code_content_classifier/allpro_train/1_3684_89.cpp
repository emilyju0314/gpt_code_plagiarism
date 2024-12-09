#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, long long>> vec[200005], mi[200005];
vector<pair<long long, pair<long long, long long>>> v;
map<pair<long long, long long>, long long> mp1, mp2;
long long n, m, an = 0;
long long par[200005];
long long ra[200005];
long long dsu(long long x) {
  if (x == par[x]) return x;
  par[x] = dsu(par[x]);
  return par[x];
}
void help() {
  sort(v.begin(), v.end());
  for (long long i = 0; i <= n; i++) {
    par[i] = i;
  }
  long long c = 0, id = 0;
  while (c != n - 1) {
    long long ww = v[id].first;
    long long st = v[id].second.first;
    long long en = v[id].second.second;
    long long a = dsu(st), b = dsu(en);
    if (a != b) {
      mi[st].push_back({en, ww});
      mi[en].push_back({st, ww});
      mp1[{st, en}] = 1;
      if (ra[a] > ra[b]) {
        par[b] = a;
      } else if (ra[a] < ra[b]) {
        par[a] = b;
      } else {
        par[a] = b;
        ra[b]++;
      }
      c++;
      an += ww;
    }
    id++;
  }
}
long long lev[200005], pa[200005][32], mt[200005][32];
void dfs(long long x, long long p, long long le) {
  lev[x] = le;
  for (long long i = 1; i <= 31; i++) {
    if (pa[x][i - 1] != -1) {
      pa[x][i] = pa[pa[x][i - 1]][i - 1];
      mt[x][i] = max(mt[x][i - 1], mt[pa[x][i - 1]][i - 1]);
    }
  }
  for (long long i = 0; i < mi[x].size(); i++) {
    if (mi[x][i].first != p) {
      pa[mi[x][i].first][0] = x;
      mt[mi[x][i].first][0] = mi[x][i].second;
      dfs(mi[x][i].first, x, le + 1);
    }
  }
}
long long lca(long long u, long long v) {
  long long x = lev[u], y = lev[v];
  if (x < y) swap(u, v);
  long long d = abs(x - y);
  long long an = 0;
  for (long long i = 31; i >= 0; i--) {
    if (((1 << i) & d)) {
      an = max(mt[u][i], an);
      u = pa[u][i];
    }
  }
  if (u == v) return an;
  for (long long i = 31; i >= 0; i--) {
    if (pa[u][i] != pa[v][i]) {
      an = max(an, mt[u][i]);
      an = max(an, mt[v][i]);
      u = pa[u][i];
      v = pa[v][i];
    }
  }
  an = max(an, mt[u][0]);
  an = max(an, mt[v][0]);
  return an;
}
signed main() {
  cin >> n >> m;
  memset(pa, -1, sizeof(pa));
  vector<pair<long long, long long>> tt;
  for (long long i = 0; i < m; i++) {
    long long x, y, z;
    cin >> x >> y >> z;
    tt.push_back({x, y});
    vec[x].push_back({y, z});
    vec[y].push_back({x, z});
    v.push_back({z, {x, y}});
    mp2[{x, y}] = z;
  }
  help();
  dfs(1, 1, 0);
  for (long long i = 0; i < m; i++) {
    long long st = tt[i].first;
    long long en = tt[i].second;
    if (mp1[{st, en}])
      cout << an;
    else {
      long long tem = lca(st, en);
      long long wt = mp2[{st, en}];
      cout << an - tem + wt;
    }
    cout << "\n";
  }
  return 0;
}
