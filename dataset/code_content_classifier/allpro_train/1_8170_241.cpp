#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const long long inf = 2e18;
long long v[N], c[N];
long long f[N];
int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) scanf("%I64d", &v[i]);
  for (int i = 1; i <= n; i++) scanf("%I64d", &c[i]);
  for (int p = 1; p <= q; p++) {
    long long a, b;
    scanf("%I64d%I64d", &a, &b);
    for (int i = 1; i <= n; i++) f[i] = -inf;
    pair<long long, int> One = make_pair(-inf, 0), Two = make_pair(-inf, 0);
    for (int i = 1; i <= n; i++) {
      long long pre = f[c[i]];
      f[c[i]] = max(f[c[i]], b * v[i]);
      if (pre != -inf) {
        f[c[i]] = max(f[c[i]], pre + a * v[i]);
      }
      if (One.first != -inf) {
        if (One.second == c[i]) {
          if (Two.first != -inf) f[c[i]] = max(f[c[i]], Two.first + b * v[i]);
        } else
          f[c[i]] = max(f[c[i]], One.first + b * v[i]);
      }
      if (f[c[i]] > One.first) {
        if (c[i] != One.second) Two = One;
        One.first = f[c[i]];
        One.second = c[i];
      } else if (c[i] != One.second && f[c[i]] > Two.first) {
        Two.first = f[c[i]];
        Two.second = c[i];
      }
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, f[c[i]]);
    printf("%I64d\n", ans);
  }
  return 0;
}
