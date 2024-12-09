#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char ch = getchar();
  int f = 1, x = 0;
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
int a[200001];
int main() {
  int n = read(), top = 0;
  long long ans = 0;
  for (register int i = 1; i <= n; ++i) {
    int a1 = read(), b1 = read(), a2 = read(), b2 = read();
    if (a1 + b1 >= a2 + b2) {
      a[++top] = a1 + b1;
      a[++top] = a2 + b2;
      ans += a1 + a2;
    } else if (a1 > b2)
      ans += a1 - b2;
    else if (a2 < b1)
      ans += a2 - b1;
  }
  sort(a + 1, a + 1 + top);
  n <<= 1;
  for (register int i = 1; i <= n; i += 2) ans -= a[i];
  printf("%lld\n", ans);
  return 0;
}
