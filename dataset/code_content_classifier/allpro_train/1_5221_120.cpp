#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10, lg = 20;
vector<pair<int, int>> adj[maxn];
int par[maxn][lg], st[maxn], h[maxn];
long long W[maxn][lg];
long long R = 0;
int T = -1;
vector<int> ST;
bool cmp(int v, int u) { return st[v] < st[u]; }
set<int> S;
void dfs(int v, int p = -1, int w = -1) {
  T++;
  st[v] = T;
  ST.push_back(v);
  fill(par[v], par[v] + lg, -1);
  fill(W[v], W[v] + lg, -1);
  par[v][0] = p;
  W[v][0] = w;
  for (int i = 1; i < lg; i++) {
    if (par[v][i - 1] == -1) break;
    par[v][i] = par[par[v][i - 1]][i - 1];
    W[v][i] = W[v][i - 1] + W[par[v][i - 1]][i - 1];
  }
  for (auto P : adj[v]) {
    int u = P.first, we = P.second;
    if (u == p) continue;
    h[u] = h[v] + 1;
    dfs(u, v, we);
  }
}
long long get_par(int &v, int d) {
  long long ans = 0;
  for (int i = 0; i < lg; i++) {
    if (d & (1 << i)) {
      ans += W[v][i];
      v = par[v][i];
    }
  }
  return ans;
}
long long lca(int v, int u) {
  if (h[v] > h[u]) swap(v, u);
  long long ans = get_par(u, h[u] - h[v]);
  if (u == v) return ans;
  for (int i = lg - 1; i >= 0; i--) {
    if (par[v][i] != par[u][i]) {
      ans += W[v][i] + W[u][i];
      v = par[v][i];
      u = par[u][i];
    }
  }
  return ans + W[v][0] + W[u][0];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    adj[a].push_back({b, c});
    adj[b].push_back({a, c});
  }
  dfs(0);
  int q;
  cin >> q;
  while (q--) {
    char c;
    cin >> c;
    if (c == '+') {
      int x;
      cin >> x;
      x--;
      if (S.size() == 0) {
        S.insert(st[x]);
      } else if (S.size() == 1) {
        R = lca(ST[*(S.begin())], x) * 2;
        S.insert(st[x]);
      } else {
        auto itr1 = S.lower_bound(st[x]);
        auto itr2 = S.upper_bound(st[x]);
        if (itr1 == S.begin()) {
          itr1 = S.end();
          itr1--;
        } else
          itr1--;
        if (itr2 == S.end()) itr2 = S.begin();
        R -= lca(ST[*itr1], ST[*itr2]);
        R += lca(ST[*itr1], x) + lca(x, ST[*itr2]);
        S.insert(st[x]);
      }
    } else if (c == '-') {
      int x;
      cin >> x;
      x--;
      if (S.size() == 1) {
        S.erase(st[x]);
      } else if (S.size() == 2) {
        S.erase(st[x]);
        R = 0;
      } else {
        auto itr1 = S.find(st[x]);
        auto itr2 = S.upper_bound(st[x]);
        if (itr1 == S.begin()) {
          itr1 = S.end();
          itr1--;
        } else
          itr1--;
        if (itr2 == S.end()) itr2 = S.begin();
        R -= lca(ST[*itr1], x) + lca(x, ST[*itr2]);
        R += lca(ST[*itr1], ST[*itr2]);
        S.erase(st[x]);
      }
    } else {
      cout << R / 2 << '\n';
    }
  }
}
