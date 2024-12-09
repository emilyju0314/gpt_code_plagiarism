#include <bits/stdc++.h>
using namespace std;
class DebugStream {
} LOG;
template <typename T>
DebugStream &operator<<(DebugStream &s, const T &) {
  return s;
}
const int maxN = 1e3 + 9, maxV = 1e6 + 9, MOD = 1e9 + 7, SQ = 335, lg = 20,
          bs = 29;
int n, leaf[maxN], par[maxN];
map<int, int> adj[maxN];
void prec(int nd, int an) {
  adj[nd].erase(an);
  par[nd] = an;
  for (pair<long long, long long> sn : adj[nd]) prec(sn.first, nd);
  if (adj[nd].size() == 0)
    leaf[nd] = nd;
  else
    leaf[nd] = leaf[adj[nd].begin()->first];
}
vector<pair<long long, long long> > lvs;
vector<int> toad;
void addop(int u, int v, int c) {
  lvs.emplace_back(u + 1, v + 1);
  toad.push_back(c);
}
void doop(int a, int b, int c, int X) {
  addop(a, b, X);
  addop(a, c, X);
  addop(b, c, -X);
}
void cover(int lf, int nd, int vl) {
  for (; lf != nd; lf = par[lf]) adj[par[lf]][lf] += vl;
}
void dfs(int nd, set<int> opts) {
  for (auto sn : adj[nd]) opts.insert(leaf[sn.first]);
  for (auto sn : adj[nd]) {
    opts.erase(leaf[sn.first]);
    auto need = sn.second;
    auto be = *opts.begin(), ce = *opts.rbegin();
    doop(leaf[sn.first], be, ce, need);
    cover(leaf[sn.first], sn.first, -need);
    dfs(sn.first, set<int>({be}));
    opts.insert(leaf[sn.first]);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1, u, v, c; i < n; i++) {
    cin >> u >> v >> c;
    u--, v--;
    c /= 2;
    adj[u][v] = c;
    adj[v][u] = c;
  }
  for (int i = 0; i < n; i++) {
    if (adj[i].size() == 2) {
      cout << "NO\n";
      return 0;
    }
  }
  if (n == 2) {
    cout << "YES\n1\n";
    cout << "1 2 " << adj[0].begin()->second * 2 << '\n';
    return 0;
  }
  int rt = 0;
  if (adj[0].size() == 1) rt = adj[0].begin()->first;
  prec(rt, -1);
  dfs(rt, set<int>());
  cout << "YES\n";
  cout << lvs.size() << '\n';
  for (int i = 0; i < lvs.size(); i++)
    cout << lvs[i].first << ' ' << lvs[i].second << ' ' << toad[i] << '\n';
}
