#include <bits/stdc++.h>
using namespace std;
const long long is_query = -(1LL << 62);
struct Line {
  long long m, b;
  mutable function<const Line*()> succ;
  bool operator<(const Line& rhs) const {
    if (rhs.b != is_query) return m < rhs.m;
    const Line* s = succ();
    if (!s) return 0;
    long long x = rhs.m;
    return b - s->b < (s->m - m) * x;
  }
};
struct HullDynamic : public multiset<Line> {
  bool bad(iterator y) {
    auto z = next(y);
    if (y == begin()) {
      if (z == end()) return 0;
      return y->m == z->m && y->b <= z->b;
    }
    auto x = prev(y);
    if (z == end()) return y->m == x->m && y->b <= x->b;
    return 1.00 * (x->b - y->b) * (z->m - y->m) >=
           1.00 * (y->b - z->b) * (y->m - x->m);
  }
  void insert_line(long long m, long long b) {
    auto y = insert({m, b});
    y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
    if (bad(y)) {
      erase(y);
      return;
    }
    while (next(y) != end() && bad(next(y))) erase(next(y));
    while (y != begin() && bad(prev(y))) erase(prev(y));
  }
  long long eval(long long x) {
    auto l = *lower_bound((Line){x, is_query});
    return l.m * x + l.b;
  }
};
const int N = 1e5 + 7;
HullDynamic D[N];
vector<long long> adj[N];
long long a[N], b[N], sz[N], idx[N], dp[N], st[N], en[N], tme, q[N];
void dfs(int u, int p) {
  sz[u] = 1;
  st[u] = ++tme;
  q[tme] = u;
  if (adj[u].size() == 1 && u != 1) {
    idx[u] = u;
    en[u] = tme;
    D[u].insert_line(-b[u], 0);
    return;
  }
  long long id = 0;
  for (auto v : adj[u]) {
    if (v != p) {
      dfs(v, u);
      sz[u] += sz[v];
      if (sz[v] > sz[id]) id = v;
    }
  }
  idx[u] = idx[id];
  en[u] = tme;
  for (int i = st[u] + 1; i <= en[u]; i++) {
    if (i >= st[id] && i <= en[id]) {
      i = en[id];
      continue;
    }
    long long v = q[i];
    D[idx[u]].insert_line(-b[v], -dp[v]);
  }
  dp[u] = -D[idx[u]].eval(a[u]);
  D[idx[u]].insert_line(-b[u], -dp[u]);
  return;
}
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> b[i];
  for (int i = 1; i < n; i++) {
    long long u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, 0);
  for (int i = 1; i <= n; i++) cout << dp[i] << " ";
}
