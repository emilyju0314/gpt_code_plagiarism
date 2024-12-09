#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e5 + 123, inf = 1e9;
const long long INF = 1e18;
vector<pair<int, int> > g[N];
int n, m, k, pr[N], sz[N];
bool good[N];
int getp(int v) {
  if (pr[v] == v) return v;
  return pr[v] = getp(pr[v]);
}
bool Merge(int v, int u) {
  v = getp(v);
  u = getp(u);
  if (v == u) return 0;
  if (sz[v] < sz[u]) swap(v, u);
  sz[v] += sz[u];
  pr[u] = v;
  return 1;
}
long long mn() {
  vector<long long> d(n, INF);
  set<pair<long long, long long> > st;
  d[0] = 0;
  st.insert({0, 0});
  while (!st.empty()) {
    int v = st.begin()->second;
    st.erase(st.begin());
    for (auto it : g[v])
      if (d[it.first] > d[v] + it.second) {
        st.erase({d[it.first], it.first});
        d[it.first] = d[v] + it.second;
        st.insert({d[it.first], it.first});
      }
  }
  long long res = INF;
  for (int i = 0; i < n; i++)
    if (good[i]) res = min(res, d[i]);
  return res;
}
long long mst() {
  long long res = 0;
  vector<long long> d(n, INF);
  vector<int> pr(n);
  set<pair<long long, long long> > st;
  for (int i = 0; i < n; i++)
    if (good[i]) {
      d[i] = 0;
      pr[i] = i;
      st.insert({d[i], i});
    }
  while (!st.empty()) {
    int v = st.begin()->second;
    st.erase(st.begin());
    for (auto it : g[v]) {
      if (d[it.first] > d[v] + it.second) {
        st.erase({d[it.first], it.first});
        d[it.first] = d[v] + it.second;
        pr[it.first] = pr[v];
        st.insert({d[it.first], it.first});
      }
    }
  }
  vector<pair<long long, pair<int, int> > > vec;
  for (int v = 0; v < n; v++)
    for (auto it : g[v])
      vec.push_back({d[v] + d[it.first] + it.second, {pr[v], pr[it.first]}});
  sort(vec.begin(), vec.end());
  for (auto it : vec) {
    int v = it.second.first;
    int u = it.second.second;
    if (Merge(v, u)) res += it.first;
  }
  return res;
}
int main() {
  for (int i = 0; i < N; i++) pr[i] = i, sz[i] = 1;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int v, u, w;
    scanf("%d%d%d", &v, &u, &w);
    --v, --u;
    g[v].push_back({u, w});
    g[u].push_back({v, w});
  }
  scanf("%d", &k);
  while (k--) {
    int x;
    scanf("%d", &x);
    --x;
    good[x] = 1;
  }
  printf("%lld", mst() + mn());
  return 0;
}
