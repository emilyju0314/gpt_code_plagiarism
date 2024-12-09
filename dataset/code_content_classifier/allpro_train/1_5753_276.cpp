#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int ans = 0;
  while (!(n == 0 || m == 0)) {
    if (n >= m) {
      if (n >= 2) {
        n -= 2;
        m -= 1;
        ans += 1;
      } else
        break;
    } else {
      if (m >= 2) {
        m -= 2;
        n -= 1;
        ans += 1;
      } else
        break;
    }
  }
  printf("%d\n", ans);
  return 0;
}
