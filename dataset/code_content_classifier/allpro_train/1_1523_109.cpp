#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, p, q;
  scanf("%d%d", &n, &m);
  p = 2 * n + 1;
  q = 1;
  while (1) {
    if (p <= m) printf("%d ", p++);
    if (q <= m) printf("%d ", q++);
    if ((p > m && q > m) || p == 3 * n + 1 || q == n + 1) break;
  }
  p = 3 * n + 1;
  q = n + 1;
  while (1) {
    if (p <= m) printf("%d ", p++);
    if (q <= m) printf("%d ", q++);
    if (p == 4 * n + 1 || q == 2 * n + 1) break;
    if (p > m && q > m) break;
  }
  return 0;
}
