#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a[100005], t, i = 0, j, k, x, y, z, count = 0, p, flag = 0, ans = 0,
                          sum = 0, l, n, m, max1, min1, pos, tmp, q;
  t = 1;
  while (t--) {
    scanf("%lld%lld", &n, &m);
    for (i = 0; 1; i++) {
      if (i % 2 == 0) {
        if (n >= (i + 1))
          n -= (i + 1);
        else {
          ans = -1;
          break;
        }
      } else {
        if (m >= (i + 1))
          m -= (i + 1);
        else {
          ans = 1;
          break;
        }
      }
    }
    if (ans == -1)
      printf("Vladik");
    else
      printf("Valera");
  }
  return 0;
}
