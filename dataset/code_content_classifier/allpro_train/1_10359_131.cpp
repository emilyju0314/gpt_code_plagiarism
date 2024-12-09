#include <bits/stdc++.h>
using namespace std;
const int L = 16;
long long f[L][2][2];
int q;
inline long long dp(long long lim, int mx) {
  for (int i = 0; i < L; ++i)
    f[i][0][0] = f[i][0][1] = f[i][1][0] = f[i][1][1] = 0;
  f[L - 1][!mx][1] = 1;
  for (int i = L - 1; i >= 1; --i)
    for (int s = 0; s < 2; ++s) {
      for (int x = 0; x <= mx; ++x)
        f[i - 1][s || x == mx][0] +=
            f[i][s][0] * (mx / 4 != i - 1 || (x >> mx % 4) & 1);
      for (int x = 0, v = i - 1 << 2 >= 61 ? 0 : (lim >> ((i - 1) << 2)) & 15;
           x <= v && x <= mx; ++x)
        f[i - 1][s || x == mx][x == v] +=
            f[i][s][1] * (mx / 4 != i - 1 || (x >> mx % 4) & 1);
    }
  return f[0][1][0] + f[0][1][1];
}
long long calc(long long lim) {
  long long ret = 0;
  for (int i = 0; i < L; ++i) ret += dp(lim, i);
  return ret;
}
int main() {
  scanf("%d", &q);
  for (long long l, r; q--;)
    scanf("%llx%llx", &l, &r),
        printf("%lld\n", calc(r) - (l ? calc(l - 1) : 0));
  return 0;
}
