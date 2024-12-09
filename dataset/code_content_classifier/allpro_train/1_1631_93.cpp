#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
int q;

/// --- Union Find Library {{{ ///

struct UF {
  int n;
  vector<int> par, rank;
  UF(int n): n(n), par(n, -1), rank(n, 0) {}
  int find(int x) {
    return par[x] < 0 ? x : par[x] = find(par[x]);
  }
  int size(int x) {
    return -par[find(x)];
  }
  bool same(int a, int b) {
    return find(a) == find(b);
  }
  void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if(a == b) return;
    if(rank[a] > rank[b]) swap(a, b);
    par[b] += par[a];
    par[a] = b;
    if(rank[a] == rank[b]) rank[b]++;
  }
};

/// }}}--- ///

using P = tuple<int, int, int>;
const int N = 4000;
vector<int> tree[N];
vector<pair<int, int>> treetwo[N];

int g[N][N];
int par[N][13];
int dist[N][13];
int dep[N];

void dfs(int i, int p = -1, int d = 0) {
  par[i][0] = p;
  dep[i] = d;
  if(p != -1) dist[i][0] = g[i][p];
  for(int j : tree[i]) if(j != p) {
    dfs(j, i, d + 1);
  }
}

void build() {
  dfs(0);
  for(int i = 1; i < 13; i++) {
    for(int j = 0; j < n; j++) {
      int p = par[j][i - 1];
      int d = dist[j][i - 1];
      if(p != -1) {
        par[j][i] = par[p][i - 1];
        dist[j][i] = max(d, dist[p][i - 1]);
      } else par[j][i] = -1;
    }
  }
}

int lca(int a, int b) {
  if(dep[a] > dep[b]) swap(a, b);
  // cerr << "dep ab = "<< dep[a] << " , " << dep[b] << endl;
  for(int i = 12; i >= 0; i--) {
    int p = par[b][i];
    if(p != -1 && dep[p] >= dep[a]) b = p;
  }
  if(a == b) return a;
  // cerr << "dep ab = "<< dep[a] << " , " << dep[b] << endl;
  // cerr << "ab = "<< a << " , " << b << endl;
  for(int i = 12; i >= 0; i--) {
    int pa = par[a][i];
    int pb = par[b][i];
    if(pa != pb) a = pa, b = pb;
  }
  return par[a][0];
}

int calc(int top, int a) {
  int res = 0;
  for(int i = 12; i >= 0; i--) {
    int p = par[a][i];
    if(p != -1 && dep[p] >= dep[top]) res = max(res, dist[a][i]), a = p;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  cin >> n >> m;

  vector<P> es;
  for(int i = 0; i < m; i++) {
    int a, b, c; cin >> a >> b >> c;
    a--; b--;
    es.emplace_back(c, a, b);
  }
  sort(begin(es), end(es));

  UF treeone(n);
  ll cost = 0;

  // kruskal
  for(int i = 0; i < m; i++) {
    int a = get<1>(es[i]), b = get<2>(es[i]), c = get<0>(es[i]);
    if(!treeone.same(a, b)) {
      treeone.unite(a, b);
      tree[a].emplace_back(b);
      tree[b].emplace_back(a);
      treetwo[a].emplace_back(b, c);
      treetwo[b].emplace_back(a, c);
      g[a][b] = c;
      g[b][a] = c;
      cost += c;
    }
  }
  // doubling
  build();

  cin >> q;
  for(int i = 0; i < q; i++) {
    int s, t; cin >> s >> t;
    s--; t--;
    int l = lca(s, t);
    // cerr << "s = " << s + 1 << " , t = " << t + 1 << " , lca = " << l + 1 << endl;
    ll ans = cost;
    if(s == l) ans -= calc(s, t);
    else if(t == l) ans -= calc(t, s);
    else ans -= max(calc(l, s), calc(l, t));
    cout << ans << endl;
  }

}
