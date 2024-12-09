#include <bits/stdc++.h>
using namespace std;
const int mn = 1e5 + 5;
int n, m, k;
int a[mn], p[mn];
vector<int> g[mn];
int x[mn];
int join(int u) {
  if (u != p[u]) return p[u] = join(p[u]);
  return p[u];
}
int uni(int u, int v) {
  u = join(u);
  v = join(v);
  if (u == v) return 0;
  if (p[u] < p[v]) {
    p[v] = u;
    x[u] += x[v];
  } else {
    p[u] = v;
    x[v] += x[u];
  }
  return 1;
}
pair<int, pair<int, int> > ed[mn];
bool cmp(pair<int, pair<int, int> > a, pair<int, pair<int, int> > b) {
  return a.first > b.first;
}
int kq;
int spe[mn];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= k; i++) {
    cin >> spe[i];
    x[spe[i]] = 1;
  }
  for (int i = 1; i <= n; i++) p[i] = i;
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    ed[i] = {w, {u, v}};
  }
  sort(ed + 1, ed + m + 1);
  for (int i = 1; i <= m; i++) {
    int u = ed[i].second.first;
    int v = ed[i].second.second;
    int w = ed[i].first;
    kq = max(kq, w);
    uni(u, v);
    if (x[join(u)] == k) break;
  }
  for (int i = 1; i <= k; i++) cout << kq << " ";
  return 0;
}
