#include <bits/stdc++.h>
using namespace std;
long long x[100005], y[100005];
int cx, cy;
int main() {
  long long a, b, c, d, i, j, e, f;
  bool flag = 1;
  scanf("%lld%lld", &a, &b);
  c = a + b;
  for (i = 1; i * i <= a; i++) {
    if (a % i == 0) x[++cx] = i;
  }
  for (i = 1; i * i <= b; i++) {
    if (b % i == 0) y[++cy] = i;
  }
  d = sqrt(c);
  for (i = d; i >= 1 && flag; i--) {
    if (c % i == 0) {
      e = c / i;
      int l = 1, r = cx;
      while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (x[mid] > i)
          r = mid - 1;
        else
          l = mid;
      }
      if (a / x[l] <= e) {
        flag = 0;
        break;
      }
      l = 1, r = cy;
      while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (y[mid] > i)
          r = mid - 1;
        else
          l = mid;
      }
      if (b / y[l] <= e) {
        flag = 0;
        break;
      }
    }
  }
  printf("%lld", (i + e) * 2);
  return 0;
}
