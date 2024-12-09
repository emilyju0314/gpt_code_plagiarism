#include <bits/stdc++.h>
using namespace std;
long long n, m, d, l, r;
long long a[100002];
int main() {
  int i, j, k;
  scanf("%I64d %I64d", &n, &d);
  for (i = 1; i <= n; i++) {
    scanf("%I64d", &a[i]);
  }
  long long ans = 0;
  r = 1;
  for (i = 1; i <= n; i++) {
    for (j = r; j <= n; j++) {
      if (a[j] - a[i] > d) {
        break;
      }
    }
    j--;
    r = j;
    long long u = j - i - 1;
    if (u >= 0) ans += (1 + u) * u / 2;
  }
  printf("%I64d\n", ans);
  return 0;
}
