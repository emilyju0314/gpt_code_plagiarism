#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
using namespace std;
int a, b, c, d, n, m, k;
int mas[2001];
inline int gcd(int a, int b) {
  for (; b; swap(a, b)) a %= b;
  return a;
}
int main() {
  scanf("%d", &n);
  a = 0;
  for (int _n((n)-1), i(0); i <= _n; i++) {
    scanf("%d", &mas[i]);
    a = gcd(a, mas[i]);
  }
  if (a > 1) {
    printf("-1\n");
    exit(0);
  }
  a = 0;
  for (int _n((n)-1), i(0); i <= _n; i++) {
    if (mas[i] != 1) ++a;
  }
  c = 1000000000;
  for (int _n((n)-1), i(0); i <= _n; i++) {
    if (mas[i] == 1) {
      c = 0;
      break;
    }
    int cur = 0, d = mas[i];
    for (int _n(n - 1), j(i + 1); j <= _n; j++) {
      ++cur;
      d = gcd(d, mas[j]);
      if (d == 1) break;
    }
    if (d == 1) c = min(c, cur - 1);
  }
  printf("%d\n", a + c);
}
