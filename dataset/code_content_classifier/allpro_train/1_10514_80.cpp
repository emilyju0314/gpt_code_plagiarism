#include <bits/stdc++.h>
using namespace std;
FILE *in;
FILE *out;
int n, cnt;
int a[1024][2];
long long dyn[128][1024];
long long tri[1024][1024];
long long recurse(int idx, int sum) {
  if (idx >= n) return (sum == 0);
  if (dyn[idx][sum] != -1) return dyn[idx][sum];
  long long ans = 0;
  int nsum = sum + a[idx][0];
  for (int stay = 0; stay <= min(nsum, a[idx][1]); stay++) {
    ans += recurse(idx + 1, nsum - stay) * tri[stay][nsum];
    if (ans >= 1000000007LL) ans %= 1000000007LL;
  }
  return dyn[idx][sum] = ans;
}
void calcTriangle() {
  tri[0][0] = 1;
  for (int n = 1; n < 1024; n++) {
    tri[0][n] = 1;
    for (int k = 1; k <= n; k++)
      tri[k][n] = (tri[k - 1][n - 1] + tri[k][n - 1]) % 1000000007LL;
  }
}
long long inverse(long long number) {
  long long num = 1;
  for (int i = 1; i <= number; i++) num = (num * i) % 1000000007LL;
  int pwr = 1000000007LL - 2;
  long long ret = 1;
  while (pwr) {
    if (pwr & 1) ret = (ret * num) % 1000000007LL;
    num = (num * num) % 1000000007LL;
    pwr >>= 1;
  }
  return ret;
}
int main(void) {
  in = stdin;
  out = stdout;
  calcTriangle();
  fscanf(in, "%d", &n);
  for (int i = 0; i < n; i++) fscanf(in, "%d", &a[i][0]);
  for (int i = 0; i < n; i++) fscanf(in, "%d", &a[i][1]);
  for (int i = 0; i < n; i++) cnt += a[i][0];
  memset(dyn, -1, sizeof(dyn));
  long long ans = recurse(0, 0);
  for (int i = 1; i <= cnt; i++) ans = (ans * i) % 1000000007LL;
  for (int i = 0; i < n; i++) ans = (ans * inverse(a[i][0])) % 1000000007LL;
  fprintf(out, "%d\n", (int)ans);
  return 0;
}
