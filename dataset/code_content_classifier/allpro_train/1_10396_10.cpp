#include <bits/stdc++.h>
using namespace std;
void test() { cerr << "\n"; }
template <typename T, typename... Args>
void test(T x, Args... args) {
  cerr << x << " ";
  test(args...);
}
const int MAXN = (int)1e6 + 5;
const int MOD = (int)1e9 + 7;
struct Line {
  long long k, b;
  long long f(long long x) { return k * x + b; }
  Line operator-(const Line &a) const { return {k - a.k, b - a.b}; }
  Line operator+(const Line &a) const { return {k + a.k, b + a.b}; }
  double operator*(const Line &a) const {
    return (double)k * a.b - (double)a.k * b;
  }
};
bool cmp(const Line &a, const Line &b) { return a.k < b.k; }
struct Hull {
  vector<Line> ve;
  int cnt;
  Hull() { init(); }
  bool empty() { return cnt == 0; }
  void init() {
    ve.clear();
    cnt = 0;
  }
  void add(const Line &p) {
    ve.push_back(p);
    cnt++;
  }
  void pop() {
    ve.pop_back();
    cnt--;
  }
  bool checkld(const Line &a, const Line &b, const Line &c) {
    return (long double)(a.b - b.b) / (long double)(b.k - a.k) >
           (long double)(a.b - c.b) / (long double)(c.k - a.k);
  }
  bool checkll(const Line &a, const Line &b, const Line &c) {
    return (a.b - b.b) * (c.k - a.k) > (a.b - c.b) * (b.k - a.k);
  }
  void insert(const Line &p) {
    if (cnt && ve.back().k == p.k) {
      if (p.b <= ve.back().b)
        return;
      else
        pop();
    }
    while (cnt >= 2 && checkld(ve[cnt - 2], ve[cnt - 1], p)) pop();
    add(p);
  }
  long long query(long long x) {
    if (empty()) return 0;
    while (cnt > 1 && ve[cnt - 2].f(x) > ve[cnt - 1].f(x)) pop();
    ;
    return ve.back().f(x);
  }
} hull;
Hull minkowski_sum(Hull ha, Hull hb) {
  if (ha.empty()) return hb;
  if (hb.empty()) return ha;
  Hull res;
  auto &a = ha.ve, &b = hb.ve;
  vector<Line> ve;
  res.add(a[0] + b[0]);
  for (int i = 0, j = 0; i + 1 < a.size() || j + 1 < b.size();) {
    if (j + 1 == b.size() ||
        (i + 1 < a.size() && (a[i + 1] - a[i]) * (b[j + 1] - b[j]) < 0)) {
      res.add(a[++i] + b[j]);
    } else {
      res.add(a[i] + b[++j]);
    }
  }
  return res;
}
vector<pair<int, Line> > ed[MAXN];
vector<Line> line;
int tot;
void rebuild(int u, int pre) {
  vector<pair<int, Line> > tmp;
  for (auto &e : ed[u]) {
    int v = e.first;
    if (v == pre) continue;
    rebuild(v, u);
    tmp.push_back(e);
  }
  int rt = u;
  ed[u].clear();
  for (int i = 0; i < (int)tmp.size(); i++) {
    if (i && i + 1 < (int)tmp.size()) {
      ed[rt].push_back({++tot, {0, 0}});
      ed[tot].push_back({rt, {0, 0}});
      rt = tot;
    }
    ed[rt].push_back(tmp[i]);
    ed[tmp[i].first].push_back({rt, tmp[i].second});
  }
}
int sz[MAXN], root, proot;
bool vis[MAXN];
void findRoot(int u, int pre, int sum) {
  sz[u] = 1;
  for (auto &e : ed[u]) {
    int v = e.first;
    if (v == pre || vis[v]) continue;
    findRoot(v, u, sum);
    sz[u] += sz[v];
    if (!root || max(sz[v], sum - sz[v]) < max(sz[root], sum - sz[root])) {
      proot = u;
      root = v;
    }
  }
}
void dfs(int u, int pre, Line d, vector<Line> &ve) {
  ve.push_back(d);
  for (auto &e : ed[u]) {
    int v = e.first;
    if (vis[v] || v == pre) continue;
    dfs(e.first, u, d + e.second, ve);
  }
}
void gao(int u, int v) {
  Line w;
  for (auto &e : ed[u]) {
    if (e.first == v) {
      w = e.second;
      break;
    }
  }
  vector<Line> v1, v2;
  dfs(u, v, w, v1);
  dfs(v, u, {0, 0}, v2);
  sort(v1.begin(), v1.end(), cmp);
  sort(v2.begin(), v2.end(), cmp);
  Hull h1, h2;
  for (auto x : v1) h1.insert(x);
  for (auto x : v2) h2.insert(x);
  h1 = minkowski_sum(h1, h2);
  for (auto x : h1.ve) line.push_back(x);
}
void solve(int u, int v) {
  if (u == 0) return;
  gao(u, v);
  vis[v] = 1;
  root = 0;
  int s1 = sz[u], s2 = sz[v];
  findRoot(u, -1, s1);
  solve(root, proot);
  vis[u] = 1;
  vis[v] = 0;
  root = 0;
  findRoot(v, -1, s2);
  solve(root, proot);
}
long long ans[1000006];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i < n; i++) {
    int u, v, a, b;
    cin >> u >> v >> a >> b;
    ed[u].push_back({v, {a, b}});
    ed[v].push_back({u, {a, b}});
  }
  tot = n;
  rebuild(1, -1);
  root = 0;
  findRoot(1, -1, tot);
  solve(root, proot);
  sort(line.begin(), line.end(), cmp);
  Hull hull;
  for (auto l : line) hull.insert(l);
  for (int i = m - 1; i >= 0; i--) {
    ans[i] = hull.query(i);
  }
  for (int i = 0; i < m; i++) cout << ans[i] << " ";
  return 0;
}
