#include <bits/stdc++.h>
using namespace std;
map<int, int> a;
int f[10005];
long long g[1500][1500], c[100005], s[10005];
long long mul(long long x, int y) {
  long long z = 1;
  while (y) {
    if (y & 1) z = (z * x) % 1000000007;
    y /= 2;
    x = (x * x) % 1000000007;
  }
  return z;
}
int main() {
  int h = 0, t = 1;
  f[1] = 0;
  while (h < t) {
    int i = f[++h];
    if (i > 100000000) continue;
    f[++t] = i * 10 + 4;
    f[++t] = i * 10 + 7;
  }
  for (int i = 2; i <= t; i++) a[f[i]] = i - 1;
  int n, k, x, y;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    if (a.find(x) == a.end())
      y = 0;
    else
      y = a[x];
    s[y]++;
  }
  int sum = 0;
  g[0][0] = 1;
  for (int i = 1; i <= t; i++)
    if (s[i]) {
      sum++;
      g[sum][0] = 1;
      for (int j = 1; j <= sum; j++) {
        g[sum][j] = g[sum - 1][j];
        g[sum][j] = (g[sum][j] + g[sum - 1][j - 1] * s[i]) % 1000000007;
      }
    }
  long long z = 1;
  c[0] = 1;
  for (int i = s[0]; i; i--) {
    c[i] = z;
    z = z * i % 1000000007;
    z = z * mul(s[0] - i + 1, 1000000007 - 2) % 1000000007;
    z = (z + 1000000007) % 1000000007;
  }
  long long ans = 0;
  for (int i = 0; i <= ((sum) < (k) ? (sum) : (k)); i++)
    ans = (ans + g[sum][i] * c[k - i]) % 1000000007;
  printf("%d\n", (ans + 1000000007) % 1000000007);
  return 0;
}
