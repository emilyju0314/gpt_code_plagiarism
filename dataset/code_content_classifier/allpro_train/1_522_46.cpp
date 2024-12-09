#include <bits/stdc++.h>
using namespace std;
const int Mod = 998244353;
int n, m, sa, sb, a[200005], w[200005], f[3005][3005], g[3005][3005], r[20000];
int power(int b, int e) {
  if (!e) return 1;
  int tmp = power(b, e >> 1);
  tmp = 1ll * tmp * tmp % Mod;
  if (e & 1) tmp = 1ll * tmp * b % Mod;
  return tmp;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> w[i];
  for (int i = 1; i <= n; i++)
    if (a[i])
      sa += w[i];
    else
      sb += w[i];
  for (int i = -3000; i <= 9000; i++) r[i + 3000] = power(sa + sb + i, Mod - 2);
  for (int i = 0; i <= m; i++) f[0][i] = g[0][i] = 1;
  for (int i = 1; i <= m; i++)
    for (int j = 0; j <= m; j++) {
      int inv = r[j * 2 + i - m + 3000];
      f[i][j] = (1ll * (sa + j + 1) * f[i - 1][j + 1] +
                 1ll * (sb - m + i + j) * f[i - 1][j]) %
                Mod * inv % Mod;
      g[i][j] = (1ll * (sa + j) * g[i - 1][j + 1] +
                 1ll * (sb - m + i + j - 1) * g[i - 1][j]) %
                Mod * inv % Mod;
    }
  for (int i = 1; i <= n; i++)
    if (a[i])
      cout << 1ll * w[i] * f[m][0] % Mod << '\n';
    else
      cout << 1ll * w[i] * g[m][0] % Mod << '\n';
  return 0;
}
