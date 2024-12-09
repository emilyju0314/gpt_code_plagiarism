#include <bits/stdc++.h>
using namespace std;
const int N = 5010;
const int mod = 1e9 + 7;
int n, A, B, k;
long long ans;
long long f[N], b[N];
int main() {
  scanf("%d%d%d%d", &n, &A, &B, &k);
  f[A] = 1;
  for (int i = 1; i <= k; ++i) {
    for (int j = 1; j <= n; ++j) {
      int cha = abs(j - B) - 1;
      if (cha <= 0) continue;
      (b[max(1, j - cha)] += f[j]) %= mod;
      (b[j] += -f[j] + mod) %= mod;
      (b[j + 1] += f[j]) %= mod;
      (b[min(n, j + cha) + 1] += -f[j] + mod) %= mod;
    }
    for (int j = 1; j <= n + 1; ++j) (f[j] = f[j - 1] + b[j]) %= mod, b[j] = 0;
  }
  for (int i = 1; i <= n; ++i) (ans += f[i]) %= mod;
  printf("%lld\n", ans);
  return 0;
}
