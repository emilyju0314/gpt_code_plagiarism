#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 10;
const int mod = 1e9 + 7;
long long fac[N];
long long g[N][N];
long long f(long long n, long long k) {
  if (!k) return g[n][k] = fac[n];
  if (k == 1) return g[n][k] = fac[n] * n % mod;
  if (~g[n][k]) return g[n][k];
  return g[n][k] =
             ((k - 1) * f(n + 1, k - 2) % mod + n * f(n, k - 1) % mod) % mod;
}
int n, fp[N], b[N];
int main() {
  for (int i = fac[0] = 1; i < N; i++) fac[i] = fac[i - 1] * i % mod;
  memset(g, -1, sizeof(g));
  f(0, N - 1);
  for (; ~scanf("%d", &n);) {
    memset(fp, 0, sizeof(fp));
    memset(b, 0, sizeof(b));
    for (int a, i = 1; i <= n; i++) {
      scanf("%d", &a);
      b[a] = 1;
      if (~a) fp[i] = 1;
    }
    int m = 0, k = 0;
    for (int i = 1; i <= n; i++)
      if (!b[i]) {
        m++;
        if (fp[i]) k++;
      }
    cout << g[k][m - k] << endl;
  }
  return 0;
}
