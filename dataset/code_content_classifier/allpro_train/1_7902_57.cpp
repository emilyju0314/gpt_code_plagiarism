#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
const int M = 1e6 + 5;
const long long Mod = 1e9 + 7;
namespace FASTIO {
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}
void print(int x) {
  if (x < 0) {
    x = -x;
    putchar('-');
  }
  if (x > 9) print(x / 10);
  putchar(x % 10 + '0');
}
}  // namespace FASTIO
using namespace FASTIO;
long long f[25];
void init() {
  f[1] = 1;
  for (register int i = 2; i <= 20; ++i) f[i] = f[i - 1] * i;
}
long long C(int n, int m) { return f[n] / f[m] / f[n - m]; }
int main() {
  init();
  int n;
  n = read();
  if (n == 2)
    printf("1\n");
  else {
    long long ans = C(n, n / 2);
    ans = ans * f[(n / 2) - 1] * f[(n / 2) - 1] / 2;
    printf("%lld\n", ans);
  }
  return 0;
}
