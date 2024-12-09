#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int f[N], I[N], B[N][N], A[N];
int T, n, mod;
void init() {
  f[0] = 1;
  for (int i = (1); i <= (500); i++) f[i] = 1ll * i * f[i - 1] % mod;
  B[0][0] = 1;
  for (int i = (1); i <= (500); i++) {
    I[i] = f[i];
    for (int k = (1); k <= (i - 1); k++)
      I[i] = (I[i] - 1ll * I[k] * f[i - k] % mod + mod) % mod;
    for (int j = (1); j <= (i); j++)
      for (int k = (1); k <= (i); k++)
        B[i][j] = (B[i][j] + 1ll * B[i - k][j - 1] * f[k]) % mod;
    A[i] = f[i];
    for (int k = (1); k <= (i - 1); k++)
      A[i] = (A[i] - 2ll * I[k] * f[i - k] % mod + mod) % mod;
    for (int k = (2); k <= (i - 1); k++)
      A[i] = (A[i] - 1ll * B[i][k] * A[k] % mod + mod) % mod;
  }
}
int main() {
  scanf("%d%d", &T, &mod);
  init();
  while (T--) {
    scanf("%d", &n);
    printf("%d\n", n == 2 ? 2 : A[n]);
  }
  return 0;
}
