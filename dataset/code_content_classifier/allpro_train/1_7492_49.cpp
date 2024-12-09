#include <bits/stdc++.h>
using namespace std;
const long long int INF = 1e9;
const long long int INFF = 1e18;
const long long int M = 1e9 + 7;
long long int par[100005];
long double ex[100005];
vector<long long int> adj[100005];
long long int subtreeSz[100005];
long long int fac[100005];
void dfs(long long int u, long long int parent) {
  subtreeSz[u] = 1;
  for (auto v : adj[u]) {
    if (v != parent) {
      dfs(v, u);
      subtreeSz[u] += subtreeSz[v];
    }
  }
}
void dfs2(long long int u, long long int parent) {
  long long int s = (long long int)((adj[u]).size());
  for (auto v : adj[u]) {
    if (v != parent) {
      ex[v] = ex[u] + 1 + (long double)((subtreeSz[u] - 1) - subtreeSz[v]) / 2;
      dfs2(v, u);
    }
  }
}
void solve() {
  long long int n;
  cin >> n;
  fac[0] = 1;
  for (int i = 1; i <= n; i++) {
    fac[i] = fac[i - 1] * i;
  }
  cout << "\n";
  for (int i = 2; i <= n; i++) {
    cin >> par[i];
    adj[par[i]].push_back(i);
  }
  ex[1] = 1;
  dfs(1, 0);
  dfs2(1, 0);
  for (int i = 1; i <= n; i++) cout << fixed << setprecision(2) << ex[i] << " ";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  int tt = t;
  while (t--) {
    solve();
  }
  return 0;
}
