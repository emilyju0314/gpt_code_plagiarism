#include <bits/stdc++.h>
using namespace std;
inline void smin(long long &x, long long y) { x = min(x, y); }
inline void smax(long long &x, long long y) { x = max(x, y); }
const long long N = 45 + 10;
long long n, k, m, t[N], s = 0;
long long ANS(long long x, long long y) {
  long long res = 0;
  for (long long i = 1; i <= k; i++) {
    if (x - (y * t[i]) < 0) {
      for (long long j = 1; j <= y; j++) {
        if (x >= t[i])
          x -= t[i], res++;
        else
          return res;
      }
    } else {
      x -= (y * t[i]);
      res += y;
    }
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k >> m;
  for (long long i = 1; i <= k; i++) cin >> t[i], s += t[i];
  sort(t + 1, t + k + 1);
  long long ans = -1;
  for (long long i = 0; i <= n; i++) {
    if (s * i > m) break;
    long long add = (k + 1) * i + ANS(m - (s * i), n - i);
    smax(ans, add);
  }
  cout << ans << '\n';
}
