#include <bits/stdc++.h>
using namespace std;
int a[200000 + 10], p[200000 + 10];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  p[0] = -1;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    if (!i) continue;
    p[i] = a[i] == a[i - 1] ? p[i - 1] : i - 1;
  }
  int l, r, x;
  for (int i = 0; i < m; ++i) {
    scanf("%d%d%d", &l, &r, &x);
    if (a[r - 1] != x)
      printf("%d\n", r);
    else if (p[r - 1] >= l - 1)
      printf("%d\n", p[r - 1] + 1);
    else
      printf("-1\n");
  }
}
