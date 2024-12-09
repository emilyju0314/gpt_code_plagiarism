#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
const long long LIM = 1e18;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;
const double PI = atan(1.0) * 4;
int n, k;
long long s, t, c[N + 10], v[N + 10], g[N + 10];
int check(long long x) {
  long long rec = 0;
  int loc = 0;
  for (int i = 1; i <= k; i++) {
    long long len = g[i] - g[i - 1];
    if (len > x) return 0;
    long long c = min(x - len, len);
    long long needt = len * 2 - c;
    rec += needt;
    if (rec > t) return 0;
  }
  return 1;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  ;
  cin >> n >> k >> s >> t;
  for (int i = 1; i <= n; i++) cin >> c[i] >> v[i];
  for (int i = 1; i <= k; i++) cin >> g[i];
  sort(g + 1, g + 1 + k);
  g[++k] = s;
  g[0] = 0;
  long long l = 1, r = 1e9 + 10;
  while (l < r) {
    long long mid = (l + r) / 2;
    if (check(mid))
      r = mid;
    else
      l = mid + 1;
  }
  long long maxc = INF;
  for (int i = 1; i <= n; i++)
    if (v[i] >= l) maxc = min(maxc, c[i]);
  cout << (maxc == INF ? -1 : maxc);
  return 0;
}
