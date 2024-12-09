#include <bits/stdc++.h>
using namespace std;
long long int fac[200009], invfac[200009];
long long int expmod(long long int base, long long int pow) {
  if (pow == 0) return 1;
  if (pow == 1) return base;
  long long int res = expmod(base, pow / 2);
  res = (res * res) % 1000000007;
  if (pow % 2 == 1) res = (res * base) % 1000000007;
  return res;
}
long long int ncr(int p, int q) {
  long long int ans = fac[p];
  ans *= invfac[q];
  ans %= 1000000007;
  ans *= invfac[p - q];
  ans %= 1000000007;
  return ans;
}
long long int memoize(int zro, int one, int needchar) {
  if (zro == 0 && one == 1 && needchar == 1) return 1;
  if (zro == 1 && one == 0 && needchar == 0) return 1;
  if (zro == 1 && one == 0 && needchar == 1) return 0;
  if (zro == 0 && one == 1 && needchar == 0) return 0;
  if (zro < 0 || one < 0) return 0;
  if (needchar == 0)
    return (ncr(zro + one - 1, zro) + memoize(zro - 1, one, 1)) % 1000000007;
  else if (needchar == 1)
    return memoize(zro - 1, one, 0);
}
void pre() {
  fac[0] = 1;
  for (int i = int(1); i <= int(200005); i++) {
    fac[i] = fac[i - 1] * i;
    fac[i] %= 1000000007;
  }
  invfac[0] = 1;
  for (int i = int(1); i <= int(200005); i++) {
    invfac[i] = invfac[i - 1] * expmod(i, 1000000007 - 2);
    invfac[i] %= 1000000007;
  }
}
int main() {
  pre();
  int zero, one, need;
  scanf("%d", &zero);
  scanf("%d", &one);
  scanf("%d", &need);
  long long int ans = memoize(zero, one, need);
  printf("%lld\n", ans);
  return 0;
}
