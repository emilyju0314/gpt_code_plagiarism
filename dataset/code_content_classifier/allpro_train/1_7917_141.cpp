#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:260777216")
using namespace std;
int n, m, c, d, k;
int main() {
  scanf("%d%d%d%d%d", &c, &d, &n, &m, &k);
  int need = m * n - k;
  int ans = 0;
  while (need > 0) {
    double q = (double)c / n;
    double q2 = d;
    if (need < n) {
      if (d * need < c)
        ans += d * need;
      else
        ans += c;
      need = 0;
      continue;
    }
    if (q <= q2) {
      need -= n;
      ans += c;
    } else {
      need--;
      ans += d;
    }
  }
  printf("%d\n", ans);
  return 0;
}
