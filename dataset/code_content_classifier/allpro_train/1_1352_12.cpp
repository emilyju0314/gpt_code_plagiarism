#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int N = 100010;
const int MAX = 1000000100;
const int mod = 100000000;
const int MOD1 = 1000000007;
const int MOD2 = 1000000009;
const double EPS = 0.00000001;
const long long MOD = 998244353;
const int INF = 1000000010;
const double pi = acos(-1.0);
long long mx[5], mi[5];
long long X[5][2], f[7], MX = 1e18;
long long get(long long x, long long y) {
  if ((x < 0 && y < 0) || (x > 0 && y > 0)) {
    long long bo = 0;
    if (x % 2 && y % 2) bo = 1;
    if (x < 0 && y < 0)
      return x / 2 + y / 2 - bo;
    else
      return x / 2 + y / 2 + bo;
  } else
    return (x + y) / 2;
}
int pd(long long x) {
  f[3] = max(X[1][0] - x, X[2][0] + x);
  f[4] = min(X[1][1] - x, X[2][1] + x);
  f[5] = max(X[3][0] - x, X[4][0] + x);
  f[6] = min(X[3][1] - x, X[4][1] + x);
  if (f[3] > f[4] || f[5] > f[6]) return 0;
  if (f[4] > f[3] || f[6] > f[5]) return 1;
  if ((f[3] % 2 + 2) % 2 == (f[5] % 2 + 2) % 2) return 1;
  return 0;
}
int check(long long x) {
  int i;
  for (i = 1; i < 5; i++) {
    X[i][0] = mx[i] - x;
    X[i][1] = mi[i] + x;
    if (X[i][0] > X[i][1]) return 0;
  }
  f[1] = get(X[1][0], -X[2][1]);
  f[2] = get(X[1][1], -X[2][0]);
  f[3] = get(X[3][0], -X[4][1]);
  f[4] = get(X[3][1], -X[4][0]);
  f[1] = max(f[1], max(f[3], -MX));
  f[2] = min(f[2], min(f[4], MX));
  if (f[1] > f[2]) return 0;
  for (long long j = f[1]; j <= f[2]; j++)
    if (pd(j)) return 1;
  return 0;
}
int main() {
  int i, n, t;
  long long x, y, z, mxx = 3 * 1e18;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (i = 1; i < 5; i++) {
      mi[i] = mxx;
      mx[i] = -mxx;
    }
    for (i = 1; i <= n; i++) {
      scanf("%I64d%I64d%I64d", &x, &y, &z);
      mi[1] = min(mi[1], x + y + z);
      mx[1] = max(mx[1], x + y + z);
      mi[2] = min(mi[2], -x + y + z);
      mx[2] = max(mx[2], -x + y + z);
      mi[3] = min(mi[3], x + y - z);
      mx[3] = max(mx[3], x + y - z);
      mi[4] = min(mi[4], -x + y - z);
      mx[4] = max(mx[4], -x + y - z);
    }
    long long l = -1, r = mxx, mid = (l + r) >> 1;
    while (l + 1 < r)
      if (check(mid)) {
        r = mid;
        mid = (l + r) >> 1;
      } else {
        l = mid;
        mid = (l + r) >> 1;
      }
    check(r);
    for (long long j = f[1]; j <= f[2]; j++)
      if (pd(j)) {
        x = j;
        if (f[3] == f[4] || f[5] == f[6]) {
          if (f[3] == f[4]) {
            y = f[3];
            if ((f[5] % 2 + 2) % 2 == (f[3] % 2 + 2) % 2)
              z = f[5];
            else
              z = f[5] + 1;
          } else {
            z = f[5];
            if ((f[5] % 2 + 2) % 2 == (f[3] % 2 + 2) % 2)
              y = f[3];
            else
              y = f[3] + 1;
          }
        } else {
          y = f[3];
          if ((f[5] % 2 + 2) % 2 == (f[3] % 2 + 2) % 2)
            z = f[5];
          else
            z = f[5] + 1;
        }
        break;
      }
    printf("%I64d %I64d %I64d\n", x, get(y, z), get(y, -z));
  }
  return 0;
}
