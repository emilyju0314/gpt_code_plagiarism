#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while ((c < '0' || c > '9') && (c != '-')) c = getchar();
  if (c == '-') f = -1, c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x * f;
}
const int N = 3e5 + 10, mod = 1e9 + 7;
int n, a[N], ans, pw[N];
int main() {
  n = read();
  for (register int i = (1); i <= (n); i++) a[i] = read();
  sort(a + 1, a + 1 + n);
  pw[0] = 1;
  for (register int i = (1); i <= (n); i++) pw[i] = 1ll * pw[i - 1] * 2 % mod;
  for (register int i = (1); i <= (n); i++)
    ans = (ans + 1ll * (mod - a[i]) * pw[n - i]) % mod;
  for (register int i = (1); i <= (n); i++)
    ans = (ans + 1ll * a[i] * pw[i - 1]) % mod;
  printf("%d\n", ans);
}
