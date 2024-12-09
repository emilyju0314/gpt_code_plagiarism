#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 * 100 + 10;
int n, m, vnum, add, par[MAXN], d[MAXN], deg[MAXN], mrk[MAXN];
set<int> adj[MAXN];
bool in_C[MAXN];
vector<pair<int, int> > Bcorrect;
vector<int> lev[MAXN], child[MAXN], cycle[MAXN];
void read() {
  ios ::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int v, u;
    cin >> v >> u;
    v--;
    u--;
    adj[v].insert(u);
    adj[u].insert(v);
    deg[u]++;
    deg[v]++;
  }
}
void dfs(int x, int p) {
  par[x] = p;
  mrk[x] = 1;
  set<int>::iterator it;
  for (it = adj[x].begin(); it != adj[x].end(); it++) {
    int cur = (*it);
    if (!mrk[cur])
      dfs(cur, x);
    else if (mrk[cur] == 1 && par[x] != cur)
      Bcorrect.push_back(make_pair(cur, x));
  }
  mrk[x] = 2;
}
void merge() {
  for (int i = 0; i < Bcorrect.size(); i++) {
    int cur = Bcorrect[i].second, root = Bcorrect[i].first;
    while (cur != root) {
      for (set<int>::iterator it = adj[cur].begin(); it != adj[cur].end();
           it++) {
        int nb = (*it);
        adj[nb].erase(cur);
        if (nb != root && nb != par[root]) {
          adj[nb].insert(root);
          adj[root].insert(nb);
        }
      }
      cycle[root].push_back(cur);
      cur = par[cur];
      in_C[root] = 1;
    }
    cycle[root].push_back(root);
  }
  for (int i = 0; i < n; i++) mrk[i] = 0;
}
void another_dfs(int x, int L) {
  lev[L].push_back(x);
  mrk[x] = 1;
  for (set<int>::iterator it = adj[x].begin(); it != adj[x].end(); it++)
    if (!mrk[(*it)]) {
      another_dfs((*it), L + 1);
      child[x].push_back((*it));
    }
}
void solve() {
  for (int L = n; L >= 0; L--)
    for (int mem = 0; mem < lev[L].size(); mem++) {
      int cnt = 0, cur = lev[L][mem];
      vnum++;
      for (int i = 0; i < child[cur].size(); i++) {
        int ch = child[cur][i];
        if (child[ch].size() % 2 == 1) cnt++;
        d[cur] += d[ch];
      }
      d[cur] -= cnt / 2;
      if (cnt % 2 == 1)
        d[cur] += (child[cur].size() - cnt) / 2;
      else if (cnt % 2 == 0)
        d[cur] += (child[cur].size() - cnt + 1) / 2;
    }
}
int calc_cycle() {
  int C = 0;
  for (int i = 0; i < n; i++) {
    int odd = 0, deg3 = 0;
    if (in_C[i]) {
      for (int j = 0; j < cycle[i].size(); j++) {
        if (deg[cycle[i][j]] % 2 == 1) odd++;
        if (deg[cycle[i][j]] > 2) deg3++;
      }
      if (odd >= 2)
        C += odd / 2;
      else if (deg3 <= 1)
        C++;
    }
  }
  return C;
}
int main() {
  read();
  dfs(0, -1);
  merge();
  another_dfs(0, 0);
  solve();
  if (vnum == 1) {
    if (in_C[0])
      cout << 1 << ' ' << m << endl;
    else
      cout << 0 << ' ' << m << endl;
    return 0;
  }
  cout << d[0] + calc_cycle() << ' ' << m << endl;
  return 0;
}
