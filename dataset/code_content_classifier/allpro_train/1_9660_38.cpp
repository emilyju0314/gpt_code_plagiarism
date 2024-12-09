#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 10;
int a[N], b[N], GCD[N], f[N], va[N];
inline int re() {
  int x = 0;
  char c = getchar();
  bool p = 0;
  for (; c < '0' || c > '9'; c = getchar()) p |= c == '-';
  for (; c >= '0' && c <= '9'; c = getchar()) x = x * 10 + c - '0';
  return p ? -x : x;
}
int gcd(int x, int y) { return !y ? x : gcd(y, x % y); }
inline int maxn(int x, int y) { return x > y ? x : y; }
inline int minn(int x, int y) { return x < y ? x : y; }
int main() {
  int i, j, n, m, d;
  long long s = 0;
  n = re();
  m = n << 1;
  for (i = 1; i <= n; i++) a[i - 1] = a[i - 1 + n] = re(), GCD[i] = gcd(i, n);
  for (d = 1; d < n; d++)
    if (!(n % d)) {
      for (i = 0; i < d; i++) {
        b[i] = -1e9;
        for (j = i; j < m; j += d) b[i] = maxn(b[i], a[j]);
        for (j = i; j < m; j += d) f[j] = (a[j] == b[i]);
      }
      for (i = 1; i < m; i++)
        if (f[i]) f[i] += f[i - 1];
      for (i = 1; i < n; i++) va[i] = va[i - 1] + (GCD[i] == d);
      for (i = n; i < m; i++) s += va[minn(n - 1, f[i])];
    }
  printf("%I64d", s);
  return 0;
}
