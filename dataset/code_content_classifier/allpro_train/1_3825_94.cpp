#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long w = 0, f = 1;
  char c = ' ';
  while (c < '0' || c > '9') c = getchar(), f = c == '-' ? -1 : f;
  while (c >= '0' && c <= '9') w = w * 10 + c - 48, c = getchar();
  return w * f;
}
long long n, a[200005], b[200005], q, ans;
map<long long, long long> mp[200005];
signed main() {
  n = read();
  for (long long i = 1; i <= n; i++) a[i] = read(), ans += a[i];
  q = read();
  while (q--) {
    long long s = read(), t = read(), u = read();
    if (mp[s][t]) {
      b[mp[s][t]]--;
      if (b[mp[s][t]] < a[mp[s][t]]) ans++;
    }
    mp[s][t] = u, b[u]++;
    if (b[u] <= a[u]) ans--;
    printf("%lld\n", ans);
  }
  return 0;
}
