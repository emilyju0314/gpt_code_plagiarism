#include <bits/stdc++.h>
using namespace std;
const long long inf = 4e18;
const long long N = 2e5 + 10;
template <typename T>
bool ckmin(T& a, T b) {
  return b < a && (a = b, true);
}
template <typename T>
bool ckmax(T& a, T b) {
  return b > a && (a = b, true);
}
struct dsu {
  vector<long long> componentSize, parent;
  long long n;
  dsu(long long _n) : n(_n) {
    componentSize.resize(n, 1);
    parent.resize(n);
    iota(parent.begin(), parent.end(), 0);
  }
  long long find(long long x) {
    return parent[x] = (parent[x] == x ? x : find(parent[x]));
  }
  inline bool unite(long long u, long long v) {
    u = find(u), v = find(v);
    if (u == v) return false;
    if (componentSize[u] < componentSize[v]) swap(u, v);
    parent[v] = u;
    componentSize[u] += componentSize[v];
    return true;
  }
  inline bool connected(long long u, long long v) { return find(u) == find(v); }
  inline bool isParent(long long u) { return u == parent[u]; }
  vector<long long> get(vector<long long>& t) {
    vector<long long> ret;
    vector<long long> best(n, inf);
    for (long long i = 0; i < n; i++) {
      long long p = find(i);
      ckmin(best[p], t[i]);
    }
    for (long long i = 0; i < n; i++) {
      if (best[i] != inf) ret.push_back(best[i]);
    }
    sort(begin(ret), end(ret));
    return ret;
  }
};
void testCase() {
  long long n, k;
  cin >> n >> k;
  vector<array<long long, 2>> a(n);
  vector<long long> t(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i][0] >> a[i][1] >> t[i];
  }
  dsu d(n);
  for (long long r = 0; r < 2; r++) {
    map<long long, vector<long long>> m;
    for (long long i = 0; i < n; i++) {
      m[a[i][r ^ 1]].push_back(i);
    }
    for (auto& [c, v] : m) {
      sort(begin(v), end(v),
           [&](long long x, long long y) { return a[x][r] < a[y][r]; });
      for (long long i = 1; i < (long long)v.size(); i++) {
        long long x = v[i - 1], y = v[i];
        if (a[x][r] + k >= a[y][r]) {
          d.unite(x, y);
        }
      }
    }
  }
  vector<long long> b = d.get(t);
  n = (long long)b.size();
  long long ans = n;
  for (long long i = 0, j = 0; i < n; i++) {
    while (j < n and b[j] <= i) j++;
    if ((n - j) <= (i + 1)) ckmin(ans, i);
  }
  cout << ans << '\n';
}
int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  long long t_c = 1;
  cin >> t_c;
  while (t_c--) testCase();
}
