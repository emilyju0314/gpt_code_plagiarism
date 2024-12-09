#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<long long int> x;
long long int ans;
long long int gcd(long long int a, long long int b) {
  return b ? gcd(b, a % b) : a;
}
void dfs(int u, map<long long int, int> vals, int p) {
  map<long long int, int> nvals;
  nvals[x[u]]++;
  for (auto e : vals) nvals[gcd(e.first, x[u])] += e.second;
  for (auto e : nvals) ans = (ans + e.first * e.second) % 1000000007;
  for (auto e : g[u])
    if (e != p) dfs(e, nvals, u);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  g.resize(n);
  x.resize(n);
  for (int i = 0; i < n; i++) cin >> x[i];
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(0, {}, -1);
  cout << ans << endl;
  return 0;
}
