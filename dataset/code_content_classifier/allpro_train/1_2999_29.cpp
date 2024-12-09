#include <bits/stdc++.h>
using namespace std;
int n, a[10000];
bool squ(int x) {
  int d = sqrt(x);
  return d * d == x;
}
int main() {
  int i, ans = -0x7fffffff;
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d", a + i);
  for (i = 0; i < n; i++)
    if (!squ(a[i])) ans = max(ans, a[i]);
  printf("%d\n", ans);
  return 0;
}
