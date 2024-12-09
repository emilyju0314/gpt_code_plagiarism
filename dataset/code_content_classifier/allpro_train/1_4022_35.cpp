#include <bits/stdc++.h>
using namespace std;
long long read() {
  char ch = getchar();
  long long x = 0, op = 1;
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') op = -1;
  for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + ch - '0';
  return x * op;
}
int n, m, tot, p[1000005 / 10], phi[1000005], sum[1000005], sum1[1000005],
    sum2[1000005], sum3[1000005], ans;
bool vis[1000005];
void upd(int &x, long long y) {
  x += y;
  x -= x >= 1000000007 ? 1000000007 : 0;
}
void init(int n) {
  phi[1] = 1;
  for (int i = (2); i <= (n); i++) {
    if (!vis[i]) p[++tot] = i, phi[i] = i - 1;
    for (int j = 1; j <= tot && i * p[j] <= n; j++) {
      vis[i * p[j]] = 1;
      if (i % p[j] == 0) {
        phi[i * p[j]] = phi[i] * p[j];
        break;
      }
      phi[i * p[j]] = phi[i] * (p[j] - 1);
    }
  }
  for (int g = (1); g <= (n); g++)
    for (int x = g; x <= n; x += g) upd(sum[x], g * phi[x / g]);
}
void Main() {
  n = read(), m = read();
  if (n > m) swap(n, m);
  ans = 0;
  upd(ans, (long long)n * m % 1000000007 * sum1[n] % 1000000007);
  upd(ans, 1000000007 - (long long)(n + m) * sum2[n] % 1000000007);
  upd(ans, sum3[n]);
  cout << ans << '\n';
}
int main() {
  init(1000000);
  for (int i = (1); i <= (1000000); i++) {
    int val =
        ((long long)i * (i + 1) * (2ll * i + 1) / 3 % 1000000007 + 1000000007 -
         3ll * i * i % 1000000007 + 2ll * sum[i] % 1000000007) %
        1000000007;
    sum1[i] = (sum1[i - 1] + val) % 1000000007;
    sum2[i] =
        (sum2[i - 1] + (long long)(i - 1) * val % 1000000007) % 1000000007;
    sum3[i] = (sum3[i - 1] +
               (long long)(i - 1) * (i - 1) % 1000000007 * val % 1000000007) %
              1000000007;
  }
  int T = read();
  while (T--) Main();
  return 0;
}
