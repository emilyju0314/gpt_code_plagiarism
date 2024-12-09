#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
long long f[200005] = {1}, d[200005], c[200005];
vector<int> g[200005];
void dfs(int x, int p) {
  c[x] = d[x] = 1;
  int e = 0;
  for (int i : g[x])
    if (i != p) {
      dfs(i, x);
      c[x] += c[i];
      d[x] = d[x] * d[i] % 998244353;
      e++;
    }
  d[x] = d[x] * (x == 1 ? c[x] : (e + 1)) % 998244353 * f[e] % 998244353;
}
int main() {
  ios::sync_with_stdio(false);
  int n, u, v;
  cin >> n;
  for (int i = 1; i < n; i++)
    cin >> u >> v, g[u].push_back(v), g[v].push_back(u);
  for (int i = 1; i <= n; i++) f[i] = f[i - 1] * i % 998244353;
  dfs(1, 1);
  cout << d[1];
}
