#include <bits/stdc++.h>
using namespace std;
long long n;
long long T;
long long wei(long long a) {
  long long t = 0;
  while (a) {
    t++;
    a >>= 1;
  }
  return t;
}
long long suan(long long now, long long xuyao) {
  if (xuyao == 1) return now;
  long long A = wei(now);
  long long ss = 0;
  for (long long i = A - 1; i >= 2; i -= 2) {
    long long a = (1ll << (i - 1)) & now, b = (1ll << (i - 2)) & now;
    if (!a && !b) continue;
    if (a && !b) ss += (1ll << (i - 1)) + (1ll << (i - 2));
    if (!a && b) ss += 1ll << (i - 1);
    if (a && b) ss += 1ll << (i - 2);
  }
  ss += 1ll << A;
  return xuyao == 2 ? ss : now ^ ss;
}
signed main() {
  cin >> T;
  while (T--) {
    cin >> n;
    long long gg = (n - 1) / 3 + 1;
    long long sum = 0;
    for (long long i = 1; i <= 63; i += 2) {
      sum += 1ll << (i - 1);
      if (sum >= gg) {
        sum -= 1ll << (i - 1);
        gg -= sum + 1;
        gg += 1ll << (i - 1);
        cout << suan(gg, (n - 1) % 3 + 1) << '\n';
        break;
      }
    }
  }
  return 0;
}
