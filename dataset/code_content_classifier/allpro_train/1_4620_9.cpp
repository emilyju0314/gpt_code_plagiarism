#include <bits/stdc++.h>
using namespace std;
int in() {
  int n;
  scanf("%d", &n);
  return n;
}
long long Lin() {
  long long n;
  scanf("%lld", &n);
  return n;
}
double Din() {
  double n;
  scanf("%lf", &n);
  return n;
}
const long long inf = 1e17;
const long long mod = 1e9 + 7;
const int N = 1e5 + 5;
vector<pair<int, int> > g[N], dis;
bool used[N];
int nd, sz[N], tree[N];
int n, L, W;
void sum_upd(int x, int v) {
  ++x;
  while (x < N) {
    tree[x] += v;
    x += (x & -x);
  }
}
int sum_qry(int x) {
  int ans = 0;
  ++x;
  while (x > 0) {
    ans += tree[x];
    x -= (x & -x);
  }
  return ans;
}
void getsz(int u, int p) {
  ++nd, sz[u] = 1;
  for (auto xx : g[u]) {
    int v = xx.first;
    if (p != v && !used[v]) getsz(v, u), sz[u] += sz[v];
  }
}
int centroid(int u, int p) {
  for (auto xx : g[u]) {
    int v = xx.first;
    if (p != v && !used[v] && sz[v] > nd / 2) return centroid(v, u);
  }
  return u;
}
void upd_dis(int u, int p, int w, int l) {
  dis.push_back(make_pair(w, l));
  for (auto xx : g[u]) {
    int v = xx.first, nw = xx.second;
    if (p != v && !used[v]) upd_dis(v, u, w + nw, l + 1);
  }
}
long long query(int u, int w, int l) {
  dis.clear();
  upd_dis(u, u, w, l);
  sort(dis.begin(), dis.end());
  for (int i = 0; i < dis.size(); ++i) {
    sum_upd(dis[i].second, 1);
  }
  int j = dis.size() - 1;
  long long ans = 0LL;
  for (int i = 0; i < dis.size(); ++i) {
    while (j >= 0 && dis[i].first + dis[j].first > W) {
      sum_upd(dis[j].second, -1);
      --j;
    }
    ans += sum_qry(L - dis[i].second);
    if (dis[i].first <= W / 2 && dis[i].second <= L / 2) --ans;
  }
  while (j >= 0) {
    sum_upd(dis[j].second, -1);
    --j;
  }
  return ans / 2;
}
long long getans(int u) {
  long long ans = query(u, 0, 0);
  for (auto xx : g[u]) {
    int v = xx.first, w = xx.second;
    if (!used[v]) ans -= query(v, w, 1);
  }
  return ans;
}
long long divide(int u) {
  nd = 0;
  getsz(u, u);
  int center = centroid(u, u);
  used[center] = true;
  long long ans = getans(center);
  for (auto xx : g[center]) {
    int v = xx.first;
    if (!used[v]) ans += divide(v);
  }
  return ans;
}
int solve() {
  n = in(), L = in(), W = in();
  for (int i = 2; i <= n; i++) {
    int u = in(), w = in();
    g[u].push_back(make_pair(i, w));
    g[i].push_back(make_pair(u, w));
  }
  printf("%lld\n", divide(1));
  return 0;
}
int main() {
  int test = 1;
  while (test--) {
    solve();
  }
  return 0;
}
