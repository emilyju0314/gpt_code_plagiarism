#include <bits/stdc++.h>
using namespace std;
const int N = 31;
int n, u, r;
int a[N][N], b[N], k[N], p[N];
long long ans = LLONG_MIN;
void dfs(int dep, bool o1) {
  if (!((u - dep) & 1)) {
    long long s = 0;
    for (int i = 1; i <= n; ++i) s += (long long)a[dep][i] * k[i];
    ans = max(ans, s);
  }
  if (dep++ == u) return;
  if (o1) {
    for (int i = 1; i <= n; ++i) a[dep][i] = a[dep - 1][i] ^ b[i];
    dfs(dep, 0);
  }
  for (int i = 1; i <= n; ++i) a[dep][i] = a[dep - 1][p[i]] + r;
  dfs(dep, 1);
}
int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> u >> r;
  for (int i = 1; i <= n; ++i) cin >> a[0][i];
  for (int i = 1; i <= n; ++i) cin >> b[i];
  for (int i = 1; i <= n; ++i) cin >> k[i];
  for (int i = 1; i <= n; ++i) cin >> p[i];
  dfs(0, 1);
  cout << ans << endl;
  return 0;
}
