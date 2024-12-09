#include <bits/stdc++.h>
using namespace std;
long long dp[100010], tdp[100010], rem[60][60];
long long cnt[100010], inv[100010], fac[100010], W;
char str[100010];
const long long mod = 1e9 + 7;
int c_pos(char c) {
  if (c >= 'A' && c <= 'Z')
    return c - 'A' + 1;
  else
    return c - 'a' + 1 + 26;
}
long long fpow(long long a, long long n) {
  long long ans = 1;
  while (n > 0) {
    if (n & 1) ans = ans * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return ans;
}
void get_w(int n) {
  fac[0] = 1;
  int m = n / 2;
  for (int i = 1; i <= n; ++i) fac[i] = i * fac[i - 1] % mod;
  W = fac[m] * fac[m] % mod;
  for (int i = 1; i <= 52; ++i) {
    if (cnt[i] == 0) continue;
    inv[i] = fpow(fac[cnt[i]], mod - 2);
    W = W * inv[i] % mod;
  }
}
void init() {
  scanf("%s", str + 1);
  int len = strlen(str + 1);
  for (int i = 1; i <= len; ++i) ++cnt[c_pos(str[i])];
  get_w(len);
  dp[0] = 1;
  int m = len / 2;
  for (int i = 1; i <= 52; ++i) {
    if (cnt[i] == 0) continue;
    for (int j = m; j >= cnt[i]; --j) dp[j] = (dp[j] + dp[j - cnt[i]]) % mod;
  }
  for (int i = 1; i <= 52; ++i) {
    if (cnt[i] == 0) continue;
    for (int j = 1; j <= 52; ++j) {
      if (cnt[j] == 0) continue;
      for (int k = 0; k <= m; ++k) tdp[k] = dp[k];
      for (int k = cnt[i]; k <= m; ++k)
        tdp[k] = (tdp[k] - tdp[k - cnt[i]] + mod) % mod;
      if (i != j)
        for (int k = cnt[j]; k <= m; ++k)
          tdp[k] = (tdp[k] - tdp[k - cnt[j]] + mod) % mod;
      rem[i][j] = tdp[m];
    }
  }
}
int main() {
  init();
  int q;
  scanf("%d", &q);
  while (q--) {
    int x, y;
    scanf("%d%d", &x, &y);
    int px = c_pos(str[x]), py = c_pos(str[y]);
    printf("%lld\n", rem[px][py] * W * 2 % mod);
  }
  return 0;
}
