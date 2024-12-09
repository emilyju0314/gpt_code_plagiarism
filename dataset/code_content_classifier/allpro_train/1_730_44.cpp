#include <bits/stdc++.h>
using namespace std;
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
vector<long long> adj[200005];
long long link[200005];
long long sz[200005];
vector<long long> f(200005), vis(200005);
void init(long long n) {
  for (long long i = 0; i < n + 1; i++) link[i] = i;
  for (long long i = 0; i < n + 1; i++) sz[i] = 1;
}
long long fnd(long long x) {
  if (link[x] == x) return x;
  return link[x] = fnd(link[x]);
}
void unite(long long a, long long b) {
  a = fnd(a);
  b = fnd(b);
  if (a == b) return;
  if (sz[a] < sz[b]) swap(a, b);
  link[b] = a;
  sz[a] += sz[b];
}
void dfs(long long x) {
  vis[x] = 1;
  for (auto y : adj[x]) {
    if (vis[y] == 1) {
      f[fnd(y)] = 1;
    } else if (!vis[y]) {
      dfs(y);
    }
  }
  vis[x] = 2;
}
void solve() {
  long long n, m;
  cin >> n >> m;
  init(n);
  for (long long i = 0; i < m; i++) {
    long long u, v;
    cin >> u >> v;
    unite(u, v);
    adj[u].push_back(v);
  }
  for (long long i = 1; i <= n; i++) {
    if (!vis[i]) dfs(i);
  }
  long long ans = 0;
  for (long long i = 1; i <= n; i++) {
    if (link[i] == i) {
      if (f[i])
        ans += sz[i];
      else
        ans += sz[i] - 1;
    }
  }
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long tests;
  tests = 1;
  for (long long i = 0; i < tests; i++) {
    solve();
  }
}
