#include <bits/stdc++.h>
using namespace std;
const int Maxn = 100010;
const int inf = 2147483647;
const double pi = acos(-1.0);
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x * f;
}
int n, a[Maxn];
int main() {
  int s = 0;
  n = read();
  for (int i = 1; i <= n; i++) a[i] = read(), s ^= a[i];
  if (!(n & 1) && s) return puts("NO"), 0;
  puts("YES");
  if (!(n & 1)) n--;
  if (n & 1) {
    printf("%d\n", n - 2);
    for (int i = 1; i <= n - 2; i += 2) printf("%d %d %d\n", i, i + 1, i + 2);
    for (int i = 1; i <= n - 4; i += 2) printf("%d %d %d\n", i, i + 1, n);
  }
}
