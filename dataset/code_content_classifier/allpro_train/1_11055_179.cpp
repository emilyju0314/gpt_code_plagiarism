#include <bits/stdc++.h>
using namespace std;
int n, a, b;
int chia(int pt, int s) { return s / pt; }
int main() {
  scanf("%d %d %d", &n, &a, &b);
  if (n == a + b) {
    printf("1");
    return 0;
  }
  int x, y, ans = 1;
  for (int i = 1; i < n; i++) {
    int j = n - i;
    x = chia(i, a);
    y = chia(j, b);
    int so = min(x, y);
    if (ans < so) ans = so;
  }
  printf("%d", ans);
  return 0;
}
