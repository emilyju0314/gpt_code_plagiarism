#include <bits/stdc++.h>
using namespace std;
using LL = long long;
struct DSU {
  int sz;
  vector<int> par;
  int find(int u) {
    if (u != par[u]) par[u] = find(par[u]);
    return par[u];
  }
  DSU(int n) {
    sz = n;
    par.resize(n);
    iota(par.begin(), par.end(), 0);
  }
  bool merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return false;
    par[u] = v;
    return true;
  }
};
const int N = 2000;
int x[N], y[N];
LL c[N], k[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> k[i];
  }
  vector<tuple<LL, int, int>> edges;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      int dist = abs(x[i] - x[j]) + abs(y[i] - y[j]);
      edges.emplace_back(dist * (k[i] + k[j]), i, j);
    }
    edges.emplace_back(c[i], i, n);
  }
  DSU dsu(n + 1);
  sort(edges.begin(), edges.end());
  vector<int> power;
  vector<pair<int, int>> used;
  LL total = 0;
  for (auto& e : edges) {
    int u, v;
    LL w;
    tie(w, u, v) = e;
    if (dsu.merge(u, v)) {
      total += w;
      if (v == n)
        power.emplace_back(u);
      else
        used.emplace_back(u, v);
    }
  }
  cout << total << endl;
  cout << power.size() << endl;
  for (int i : power) cout << (i + 1) << ' ';
  cout << endl;
  cout << used.size() << endl;
  for (auto& e : used) {
    cout << (e.first + 1) << ' ';
    cout << (e.second + 1) << '\n';
  }
  return 0;
}
