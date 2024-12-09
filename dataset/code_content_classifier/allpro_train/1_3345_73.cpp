#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool chkmin(T &a, const T &b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T>
inline bool chkmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 100;
long long t[N];
int main() {
  long long n, m, a, d;
  cin >> n >> m >> a >> d;
  for (int i = 1; i <= m; i++) {
    scanf("%lld", &t[i]);
  }
  sort(t + 1, t + 1 + m);
  if (a * n > t[m]) t[++m] = a * n;
  long long lsti = 0, l = 1, r;
  long long ans = 0;
  for (int i = 1; i <= m; i++) {
    if (t[i] == t[i - 1] || lsti >= t[i]) continue;
    r = min(n, t[i] / a);
    if (l <= r) {
      l = min(n, lsti / a) + 1;
      if (l <= r) {
        if (d < a)
          ans += r - l + 1, lsti = r * a + d;
        else {
          ans += (r - l) / (d / a + 1) + 1;
          long long lev = (r - l) % (d / a + 1) + 1;
          lsti = (r - lev + 1) * a + d;
        }
      }
    }
    if (lsti >= t[i]) continue;
    ans++;
    lsti = t[i] + d;
  }
  printf("%lld\n", ans);
}
