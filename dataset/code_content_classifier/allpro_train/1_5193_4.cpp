// vvvvvvvvvvvv TEMPLATE vvvvvvvvvvvv
#include <bits/stdc++.h>
using namespace std; using ll = long long; using P = pair<ll, ll>;
const ll linf = 1e18; const double eps = 1e-12, pi = acos(-1);
#define FOR(i,a,b) for (ll i=(a),__last_##i=(b);i<__last_##i;i++)
#define RFOR(i,a,b) for (ll i=(b)-1,__last_##i=(a);i>=__last_##i;i--)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define __GET_MACRO3(_1, _2, _3, NAME, ...) NAME
#define each(i,a) for (auto&& i : a)
#define rep(...) __GET_MACRO3(__VA_ARGS__, FOR, REP)(__VA_ARGS__)
#define rrep(...) __GET_MACRO3(__VA_ARGS__, RFOR, RREP)(__VA_ARGS__)
#define pb push_back
#define eb emplace_back
#define all(a) begin(a),end(a)
#define chmin(x,v) x = min(x, v)
#define chmax(x,v) x = max(x, v)
template<typename T> ll min(ll a, const T&& b) { return a < b ? a : b; }
template<typename T> ll min(const T&& a, ll b) { return a < b ? a : b; }
template<typename T> ll max(ll a, const T&& b) { return a > b ? a : b; }
template<typename T> ll max(const T&& a, ll b) { return a > b ? a : b; }
template<typename Head> void out(Head h) { cout << h << endl; } template<typename Head, typename... Tail>void out(Head h, Tail... t) { cout << h << " "; out(t...); }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { each(x,v) is >> x; return is; }
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) { rep(i,v.size()) { if (i) os << " "; os << v[i]; } return os; }
ostream& operator<<(ostream& os, const vector<string>& v) { rep(i,v.size()) { if (i) os << endl; os << v[i]; } return os; }
template<typename T> ostream& operator<<(ostream& os, const vector<vector<T>>& v) { rep(i,v.size()) { if (i) os << endl; os << v[i]; } return os; }
template<typename T1, typename T2> ostream& operator<<(ostream& os, const pair<T1, T2>& p) { return os << "(" << p.first << ", " << p.second << ")"; }
struct yes_no : std::numpunct<char> { string_type do_truename() const { return "Yes"; } string_type do_falsename() const { return "No"; } };
void solve(); int main() {
  ios::sync_with_stdio(false); cin.tie(0); locale loc(locale(), new yes_no); cout.imbue(loc); cout << fixed << setprecision(10) << boolalpha;
  solve();
}
// ^^^^^^^^^^^^ TEMPLATE ^^^^^^^^^^^^

ll n, W;
vector<ll> a;
vector<vector<P>> G;
ll ans = 0;

template<class Edge>
class CentroidDecomposition {
  using Graph = vector<vector<typename Edge::type>>;
  const Graph G;
  const vector<ll> ids;
  void centroid_dfs(ll v, ll pv, vector<ll>& sz) const {
    sz[v] = 1;
    each(e, G[v]) {
      if (Edge::to(e) == pv) continue;
      centroid_dfs(Edge::to(e), v, sz);
      sz[v] += sz[Edge::to(e)];
    }
  }
  void build_tree(ll v, ll pv, ll pvid, vector<vector<typename Edge::type>>& nG, vector<ll>& nids) const {
    const ll vid = nG.size();
    nG.resize(nG.size()+1);
    nids.pb(ids[v]);
    each(e, G[v]) {
      if (Edge::to(e) == pv) {
        if (pvid >= 0) {
          typename Edge::type ne = e;
          Edge::to(ne) = pvid;
          nG[vid].pb(ne);
        }
      }
      else {
        typename Edge::type ne = e;
        Edge::to(ne) = nG.size();
        nG[vid].pb(ne);
        build_tree(Edge::to(e), v, vid, nG, nids);
      }
    }
  }
public:
  struct Result {
    ll centroid;
    vector<pair<vector<vector<typename Edge::type>>, vector<ll>>> trees;
  };
  CentroidDecomposition(Graph tree, vector<ll> ids) : G(move(tree)), ids(move(ids)) {}
  ll centroid() const {
    const ll n = G.size();
    vector<ll> sz(n);
    centroid_dfs(0, -1, sz);
    assert(sz[0] == n);
    rep(v, n) {
      ll mx = sz[0] - sz[v];
      each(e, G[v]) {
        if (sz[Edge::to(e)] < sz[v]) {
          chmax(mx, sz[Edge::to(e)]);
        }
      }
      if (mx <= n / 2) {
        return v;
      }
    }
    assert(false);
  }
  Result build() const {
    using Graph = vector<vector<typename Edge::type>>;
    vector<pair<Graph, vector<ll>>> res;
    ll g = centroid();
    each(e, G[g]) {
      Graph nG;
      vector<ll> nids;
      build_tree(Edge::to(e), g, -1, nG, nids);
      res.eb(nG, nids);
    }
    return {g, res};
  }
};

struct PEdge {
  using type = P;
  static ll to(const type& e) {
    return e.first;
  }
  static ll& to(type& e) {
    return e.first;
  }
};

void solve_dfs(ll v, ll pv, const vector<vector<P>>& G, const vector<ll>& ids, vector<ll>& dp) {
  each(e, G[v]) {
    ll to = e.first, cost = e.second;
    if (to == pv) continue;
    vector<ll> ndp(W+1, 0);
    rep(i, min(W+1, cost)) ndp[i] = -linf;
    rep(i, cost, W+1) {
      ndp[i] = dp[i-cost] + a[ids[to]];
    }
    solve_dfs(to, v, G, ids, ndp);
    rep(i, W+1) chmax(dp[i], ndp[i]);
  }
}

void solve(vector<vector<P>> G, vector<ll> ids) {
  vector<ll> tmp(W+1, 0);
  auto r = CentroidDecomposition<PEdge>(G, ids).build();
  tmp[0] = a[ids[r.centroid]];
  solve_dfs(r.centroid, -1, G, ids, tmp);
  each(x, tmp) chmax(ans, x);
  each(p, r.trees) {
    solve(p.first, p.second);
  }
}

void solve() {
  cin >> n >> W;
  a.resize(n); cin >> a;
  G.resize(n);
  rep(i, n-1) {
    ll u, v, c; cin >> u >> v >> c; --u, --v;
    G[u].eb(v, c);
    G[v].eb(u, c);
  }
  vector<ll> ids(n, 0);
  rep(i, n) ids[i] = i;
  solve(G, ids);
  cout << ans << endl;
}

