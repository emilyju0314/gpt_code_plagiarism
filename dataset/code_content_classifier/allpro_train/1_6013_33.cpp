#include <bits/stdc++.h>
using namespace std;
bool o1;
long long n, k, ans, jc[100010], ny[100010], pw[100010], a[100010], P = 1e9 + 7;
char s[100010];
long long ksm(long long x, long long y) {
  long long rst = 1;
  for (; y; y >>= 1, x = x * x % P)
    if (y & 1) rst = rst * x % P;
  return rst;
}
long long C(long long x, long long y) {
  return jc[x] * ny[y] % P * ny[x - y] % P;
}
bool o2;
int main() {
  pw[0] = jc[0] = ny[0] = 1;
  for (long long i = 1; i <= 100000; i++)
    pw[i] = pw[i - 1] * 10ll % P, jc[i] = jc[i - 1] * i % P,
    ny[i] = ksm(jc[i], P - 2);
  cin >> n >> k >> s;
  if (!k) {
    for (long long i = 0; i < n; i++) ans = (ans * 10ll % P + s[i] - 48) % P;
    cout << ans;
    return 0;
  }
  a[0] = C(n - 2, k - 1);
  for (long long i = 0; i < n - k; i++)
    a[i] = (a[i - 1] + pw[i] * C(n - i - 2, k - 1) % P) % P;
  for (long long i = n - k; i <= n; i++) a[i] = a[i - 1];
  for (long long i = 0; i < n - k; i++)
    (a[i] += pw[i] * C(n - i - 2, k) % P) %= P;
  for (long long i = 0; i < n; i++)
    (ans += (s[i] - 48) * a[n - i - 1] % P) %= P;
  cout << ans;
  return 0;
}
