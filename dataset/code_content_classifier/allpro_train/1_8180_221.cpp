#include <bits/stdc++.h>
using namespace std;
struct par {
  int l, r;
} c[50];
int main() {
  int n, x;
  scanf("%d%d", &n, &x);
  int i;
  for (i = 0; i < n; ++i) scanf("%d%d", &c[i].l, &c[i].r);
  int t = 1, iter = 0;
  int prevend = 0;
  int num = 0;
  for (i = 0; i < n - 1; ++i) {
    num += (c[i + 1].l - c[i].r - 1) % x;
    num += c[i].r - c[i].l + 1;
  }
  num += c[i].r - c[i].l + 1;
  num += (c[0].l - 1) % x;
  printf("%d\n", num);
  return 0;
}
