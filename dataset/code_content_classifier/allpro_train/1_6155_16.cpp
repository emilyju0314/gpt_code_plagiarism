#include <bits/stdc++.h>
using namespace std;
const int MaxN = 10004, MaxC = 0x3F3F3F3F, NA = -1;
int a[MaxN];
int n, d;
int main(void) {
  int i, k, res;
  while (scanf(" %d %d", &n, &d) != EOF) {
    for (i = 0; i < n; i++) scanf(" %d", &a[i]);
    res = 0;
    for (i = 1; i < n; i++)
      if (a[i] <= a[i - 1]) {
        k = (a[i - 1] - a[i]) / d + 1;
        a[i] += d * k;
        assert(a[i] > a[i - 1]);
        res += k;
      }
    printf("%d\n", res);
  }
  return 0;
}
