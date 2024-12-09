#include <bits/stdc++.h>
using namespace std;
const long long MOD = (long long)1e9 + 7;
const int SIZ = 1e6 + 40;
long long fac[SIZ + 3], invfac[SIZ + 3], pow2[SIZ + 3];
int prn[SIZ + 3];
bool prnvis[SIZ + 3];
int cas, x, y, nprn;
long long QPow(long long cur1, long long cur2) {
  long long ret = 1;
  while (cur2) {
    if (cur2 & 1) ret = ret * cur1 % MOD;
    cur1 = cur1 * cur1 % MOD;
    cur2 >>= 1;
  }
  return ret;
}
void Process() {
  for (int i = 2; i <= SIZ; i++) {
    if (!prnvis[i]) prn[++nprn] = i;
    for (int j = 1; j <= nprn && 1ll * i * prn[j] <= SIZ; j++) {
      prnvis[i * prn[j]] = true;
      if (i % prn[j] == 0) break;
    }
  }
  fac[0] = 1;
  invfac[0] = 1;
  for (int i = 1; i <= SIZ; i++)
    fac[i] = fac[i - 1] * i % MOD, invfac[i] = QPow(fac[i], MOD - 2);
  pow2[0] = 1;
  for (int i = 1; i <= SIZ; i++) pow2[i] = pow2[i - 1] * 2 % MOD;
}
long long C(int cur1, int cur2) {
  return fac[cur2] * invfac[cur1] % MOD * invfac[cur2 - cur1] % MOD;
}
int main() {
  Process();
  scanf("%d", &cas);
  while (cas--) {
    scanf("%d%d", &x, &y);
    long long ans = 1;
    for (int i = 1; i <= nprn && prn[i] <= x; i++) {
      if (!prnvis[x]) {
        ans = ans * C(1, y) % MOD;
        break;
      }
      int cnt = 0;
      while (x % prn[i] == 0) cnt++, x /= prn[i];
      ans = ans * C(cnt, y + cnt - 1) % MOD;
    }
    printf("%lld\n", ans * pow2[y - 1] % MOD);
  }
  return 0;
}
