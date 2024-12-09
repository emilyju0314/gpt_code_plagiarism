#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7, K = 10, MX = 50;
vector<pair<int, int>> adj[N];
int id[K][K];
vector<int> in[N];
bool adj2[MX][MX];
int cnt[MX];
int cliques = 0;
void make_clique(vector<int> v) {
  cliques++;
  for (int x : v) cnt[x]++;
  for (int i = 0; i < v.size(); i++)
    for (int j = 0; j < i; j++) adj2[v[i]][v[j]] = adj2[v[j]][v[i]] = 1;
}
int n, m, k;
vector<vector<int>> perms;
vector<int> cur;
void gen(int x) {
  if (x > k) {
    perms.push_back(cur);
    return;
  }
  cur.push_back(0);
  for (int i = 1; i <= x; i++) {
    cur.back()++;
    gen(x + 1);
  }
  cur.pop_back();
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;
  gen(1);
  int sz = 0;
  for (int i = 1; i <= k; i++)
    for (int j = 1; j <= i; j++) id[i][j] = ++sz;
  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({w, v});
  }
  for (int i = 1; i <= n; i++) {
    sort(adj[i].begin(), adj[i].end());
    int d = adj[i].size();
    for (int j = 0; j < d; j++) {
      int v = adj[i][j].second;
      in[v].push_back(id[d][j + 1]);
    }
  }
  for (int v = 1; v <= n; v++) {
    sort(in[v].begin(), in[v].end());
    in[v].erase(unique(in[v].begin(), in[v].end()), in[v].end());
    make_clique(in[v]);
  }
  for (int i = 1; i <= k; i++) {
    vector<int> v;
    for (int j = 1; j <= i; j++) v.push_back(id[i][j]);
    make_clique(v);
  }
  int ans = 0;
  for (vector<int> p : perms) {
    bool bad = false;
    int sum = 0;
    for (int i = 0; i < p.size(); i++) {
      int u = id[i + 1][p[i]];
      for (int j = 0; j < i; j++) {
        int v = id[j + 1][p[j]];
        if (adj2[u][v]) bad = true;
      }
      sum += cnt[u];
    }
    if (sum != cliques) bad = true;
    ans += !bad;
  }
  cout << ans << endl;
}
