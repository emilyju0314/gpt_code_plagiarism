#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vd = vector<double>;
using vs = vector<string>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using vpii = vector<pii>;
using vvpii = vector<vpii>;
using vpll = vector<pll>;
using vvpll = vector<vpll>;
using vpdd = vector<pdd>;
using vvpdd = vector<vpdd>;
template <typename T>
void ckmin(T& a, const T& b) {
  a = min(a, b);
}
template <typename T>
void ckmax(T& a, const T& b) {
  a = max(a, b);
}
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
namespace __input {
template <class T1, class T2>
void re(pair<T1, T2>& p);
template <class T>
void re(vector<T>& a);
template <class T, size_t SZ>
void re(array<T, SZ>& a);
template <class T>
void re(T& x) {
  cin >> x;
}
void re(double& x) {
  string t;
  re(t);
  x = stod(t);
}
template <class Arg, class... Args>
void re(Arg& first, Args&... rest) {
  re(first);
  re(rest...);
}
template <class T1, class T2>
void re(pair<T1, T2>& p) {
  re(p.first, p.second);
}
template <class T>
void re(vector<T>& a) {
  for (int i = 0; i < (int((a).size())); i++) re(a[i]);
}
template <class T, size_t SZ>
void re(array<T, SZ>& a) {
  for (int i = 0; i < (SZ); i++) re(a[i]);
}
}  // namespace __input
using namespace __input;
namespace __output {
template <class T1, class T2>
void pr(const pair<T1, T2>& x);
template <class T, size_t SZ>
void pr(const array<T, SZ>& x);
template <class T>
void pr(const vector<T>& x);
template <class T>
void pr(const set<T>& x);
template <class T1, class T2>
void pr(const map<T1, T2>& x);
template <class T>
void pr(const T& x) {
  cout << x;
}
template <class Arg, class... Args>
void pr(const Arg& first, const Args&... rest) {
  pr(first);
  pr(rest...);
}
template <class T1, class T2>
void pr(const pair<T1, T2>& x) {
  pr("{", x.first, ", ", x.second, "}");
}
template <class T, bool pretty = true>
void prContain(const T& x) {
  if (pretty) pr("{");
  bool fst = 1;
  for (const auto& a : x) pr(!fst ? pretty ? ", " : " " : "", a), fst = 0;
  if (pretty) pr("}");
}
template <class T>
void pc(const T& x) {
  prContain<T, false>(x);
  pr("\n");
}
template <class T, size_t SZ>
void pr(const array<T, SZ>& x) {
  prContain(x);
}
template <class T>
void pr(const vector<T>& x) {
  prContain(x);
}
template <class T>
void pr(const set<T>& x) {
  prContain(x);
}
template <class T1, class T2>
void pr(const map<T1, T2>& x) {
  prContain(x);
}
void ps() { pr("\n"); }
template <class Arg>
void ps(const Arg& first) {
  pr(first);
  ps();
}
template <class Arg, class... Args>
void ps(const Arg& first, const Args&... rest) {
  pr(first, " ");
  ps(rest...);
}
}  // namespace __output
using namespace __output;
namespace __algorithm {
template <typename T>
void dedup(vector<T>& v) {
  sort((v).begin(), (v).end());
  v.erase(unique((v).begin(), (v).end()), v.end());
}
template <typename T>
typename vector<T>::iterator find(vector<T>& v, const T& x) {
  auto it = lower_bound((v).begin(), (v).end(), x);
  return it != v.end() && *it == x ? it : v.end();
}
template <typename T>
size_t index(vector<T>& v, const T& x) {
  auto it = find(v, x);
  assert(it != v.end() && *it == x);
  return it - v.begin();
}
template <typename C, typename T, typename OP>
vector<T> prefixes(const C& v, T id, OP op) {
  vector<T> r(int((v).size()) + 1, id);
  for (int i = 0; i < (int((v).size())); i++) r[i + 1] = op(r[i], v[i]);
  return r;
}
template <typename C, typename T, typename OP>
vector<T> suffixes(const C& v, T id, OP op) {
  vector<T> r(int((v).size()) + 1, id);
  for (int i = (int((v).size())) - 1; i >= 0; i--) r[i] = op(v[i], r[i + 1]);
  return r;
}
}  // namespace __algorithm
using namespace __algorithm;
struct monostate {
  friend istream& operator>>(istream& is,
                             const __attribute__((unused)) monostate& ms) {
    return is;
  }
  friend ostream& operator<<(ostream& os,
                             const __attribute__((unused)) monostate& ms) {
    return os;
  }
} ms;
template <typename W = monostate>
struct wedge {
  int u, v, i;
  W w;
  wedge<W>(int _u = -1, int _v = -1, int _i = -1) : u(_u), v(_v), i(_i) {}
  int operator[](int loc) const { return u ^ v ^ loc; }
  friend void re(wedge& e) {
    re(e.u, e.v, e.w);
    --e.u, --e.v;
  }
  friend void pr(const wedge& e) { pr(e.u, "<-", e.w, "->", e.v); }
};
namespace __io {
void setIn(string second) { freopen(second.c_str(), "r", stdin); }
void setOut(string second) { freopen(second.c_str(), "w", stdout); }
void setIO(string second = "") {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed;
  cout.precision(15);
  if (int((second).size())) {
    setIn(second + ".in"), setOut(second + ".out");
  }
}
}  // namespace __io
using namespace __io;
template <typename E>
struct tree {
  int V;
  vector<E> edges;
  vector<vector<E>> adj;
  vi subt_sz;
  vb erased;
  tree() {}
  tree(int _V) : V(_V) {
    edges.resize(V - 1);
    adj.resize(V), subt_sz.resize(V), erased.resize(V);
  }
  tree(const vector<E>& __edges) : tree(int((__edges).size()) + 1) {
    edges = __edges;
    init();
  }
  void init() {
    for (int i = 0; i < (int((edges).size())); i++) {
      auto& e = edges[i];
      e.i = i;
      assert(0 <= e.u && e.u < V && 0 <= e.v && e.v < V);
      adj[e.u].push_back(e);
      adj[e.v].push_back(e);
    }
  }
  friend void re(tree& t) {
    re(t.edges);
    t.init();
  }
  friend void pr(const tree& t) { pr("{V=", t.V, " ", t.edges, "}"); }
  void erase(int v) { erased[v] = true; }
  void calc_subt_sz(int v, int p = -1) {
    subt_sz[v] = 1;
    for (auto& e : adj[v])
      if (int u = e[v]; !erased[u] && u != p) {
        calc_subt_sz(u, v);
        subt_sz[v] += subt_sz[u];
      }
  }
  int centroid(int v) {
    calc_subt_sz(v);
    int c = v;
  FIND:
    for (auto& e : adj[c])
      if (int u = e[c]; !erased[u]) {
        if (subt_sz[u] < subt_sz[c] && 2 * subt_sz[u] >= subt_sz[v]) {
          c = u;
          goto FIND;
        }
      }
    return c;
  }
};
using E = wedge<int>;
tree<E> tr;
vi w;
vd tot, der;
void go(int r, int v, int p = -1, double d = 0.) {
  double tmp = w[v] * sqrt(d);
  tot[r] += tmp * d;
  der[r] += tmp;
  for (auto& e : tr.adj[v])
    if (e[v] != p) {
      go(r, e[v], v, d + e.w);
    }
}
pair<double, int> best = {DBL_MAX, -1};
void solve(int v) {
  v = tr.centroid(v);
  double cd = 0.;
  pair<double, int> n{0., -1};
  for (auto& e : tr.adj[v]) {
    int u = e[v];
    tot[u] = der[u] = 0.;
    go(u, u, v, e.w);
    cd += tot[u];
    ckmax(n, make_pair(der[u], u));
  }
  ckmin(best, make_pair(cd, v + 1));
  tr.erase(v);
  if (n.second != -1 && !tr.erased[n.second]) solve(n.second);
}
int main() {
  setIO();
  int N;
  re(N);
  w.resize(N);
  re(w);
  tr = tree<E>(N);
  re(tr);
  tot.resize(N), der.resize(N);
  solve(0);
  ps(best.second, best.first);
  return 0;
}
