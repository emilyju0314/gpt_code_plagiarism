#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007ll;
long long n, q, t, ma, a[301], to[301], f[100001];
bool m[301], in[301], vis[301];
void dfs(long long u, long long d, long long s) {
  ma = d, vis[u] = true;
  if (to[u]) dfs(to[u], d + 1, s + a[u]);
  t -= (ma - d) * a[u], a[u] += s;
}
int main() {
  cin >> n >> q >> t, f[0] = 1;
  for (int i = 1; i <= n; cin >> a[i], ++i)
    ;
  for (int i = 1; i <= q; ++i) {
    long long b, c;
    cin >> b >> c;
    m[b] = m[c] = true, in[c] = true, to[b] = c;
  }
  for (int i = 1; i <= n; ++i)
    if (m[i] && !in[i]) ma = 0, dfs(i, 0, 0);
  if (t < 0) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 1; i <= n; ++i)
    if (m[i] && !vis[i]) {
      cout << 0 << endl;
      return 0;
    }
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j <= t - a[i]; ++j) (f[j + a[i]] += f[j]) %= mod;
  cout << f[t] << endl;
  return 0;
}
