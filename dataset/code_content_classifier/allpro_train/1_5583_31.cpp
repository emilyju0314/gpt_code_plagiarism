#include <bits/stdc++.h>
using namespace std;
int mod = 1000000007;
const int N = 2e5;
vector<int> g[N];
int a[N];
int mpow(int base, int exp);
void ipgraph(int n, int m);
void dfs(int u, int par);
int fac[1000];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int i, n;
  cin >> n;
  mod = n;
  if (n == 4) {
    cout << "YES\n1 3 2 4\n";
    return 0;
  }
  if (n < 4) {
    cout << "YES\n";
    for (i = 0; i < n; i++) cout << i + 1 << endl;
    return 0;
  }
  for (i = 2; i < n; i++)
    if (n % i == 0) {
      cout << "NO\n";
      return 0;
    }
  cout << "YES\n1\n";
  for (i = 2; i < n; i++) {
    cout << (i * 1LL * mpow(i - 1, mod - 2)) % mod << endl;
  }
  cout << n << endl;
  return 0;
}
int mpow(int base, int exp) {
  base %= mod;
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((long long)result * base) % mod;
    base = ((long long)base * base) % mod;
    exp >>= 1;
  }
  return result;
}
void ipgraph(int n, int m) {
  int i, u, v;
  while (m--) {
    cin >> u >> v;
    g[u - 1].push_back(v - 1);
    g[v - 1].push_back(u - 1);
  }
}
void dfs(int u, int par) {
  for (int v : g[u]) {
    if (v == par) continue;
    dfs(v, u);
  }
}
