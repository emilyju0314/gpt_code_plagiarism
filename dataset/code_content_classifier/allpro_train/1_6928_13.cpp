#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
const int mod = 1000000007;
int n, ans;
int a[N], p[N], f[N], g[N];
long long s[N];
long long gcd(long long x, long long y) {
  if (!y) return x;
  return gcd(y, x % y);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), s[i] = a[i];
  for (int i = 2; i <= n; i++) scanf("%d", &p[i]);
  for (int i = n; i > 1; i--) s[p[i]] += s[i];
  for (int i = 1; i <= n; i++) {
    long long t = s[1] / gcd(s[1], s[i]);
    if (t <= n) f[t]++;
  }
  for (int i = n; i >= 1; i--)
    for (int j = i * 2; j <= n; j += i) f[j] += f[i];
  g[1] = 1;
  for (int i = 1; i <= n; i++)
    if (f[i] == i) {
      (ans += g[i]) %= mod;
      for (int j = 2 * i; j <= n; j += i) (g[j] += g[i]) %= mod;
    }
  printf("%d\n", ans);
  return 0;
}
