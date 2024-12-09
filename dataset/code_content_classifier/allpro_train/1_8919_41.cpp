#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7fffffff;
const double eps = 1e-10;
const double pi = acos(-1.0);
inline int read() {
  int x = 0, f = 1;
  char ch;
  ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = 0;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch & 15);
    ch = getchar();
  }
  if (f)
    return x;
  else
    return -x;
}
const int N = 2e5 + 10;
int n, m;
char a[N], b[N];
int l, ra, rb;
int main() {
  n = read();
  m = read();
  scanf("%s%s", a + 1, b + 1);
  if (n - 1 > m) {
    printf("NO\n");
    return 0;
  }
  for (l = 1; l <= n; l++) {
    if (a[l] != '*') {
      if (a[l] != b[l]) {
        printf("NO\n");
        return 0;
      }
    } else
      break;
  }
  if (l > n) {
    if (n != m)
      printf("NO\n");
    else
      printf("YES\n");
    return 0;
  }
  for (rb = m, ra = n; rb >= 1 && ra > l; rb--, ra--)
    if (a[ra] != b[rb]) {
      printf("NO\n");
      return 0;
    }
  for (int i = l + 1; i <= ra; i++)
    if (b[l] < 'a' || b[l] > 'z') {
      printf("NO\n");
      return 0;
    }
  printf("YES\n");
  return 0;
}
