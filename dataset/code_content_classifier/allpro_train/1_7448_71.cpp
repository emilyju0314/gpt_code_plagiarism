#include <bits/stdc++.h>
using namespace std;
long long int n, m;
pair<long long int, long long int> a[1000005];
pair<long long int, long long int> p[1000005];
pair<long long int, long long int> e[1000005];
long long int ans[1000005];
long long int pref[1000005];
long long int suff[1000005];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  for (long long int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
  for (long long int i = 1; i <= n; i++) {
    p[i] = {a[i].first - a[i].second, i};
  }
  sort(p + 1, p + n + 1);
  for (long long int i = 1; i <= n; i++)
    pref[i] = pref[i - 1] + a[p[i].second].first;
  for (long long int i = n; i > 0; i--)
    suff[i] = suff[i + 1] + a[p[i].second].second;
  for (long long int i = 1; i <= n; i++) {
    long long int idx = p[i].second;
    ans[idx] += a[idx].first * (n - i) + (i - 1) * a[idx].second + pref[i - 1] +
                suff[i + 1];
  }
  for (long long int i = 1; i <= m; i++) {
    long long int u, v;
    cin >> u >> v;
    long long int mi = min(a[u].first + a[v].second, a[v].first + a[u].second);
    ans[u] -= mi;
    ans[v] -= mi;
  }
  for (long long int i = 1; i <= n; i++) cout << ans[i] << " ";
  return 0;
}
