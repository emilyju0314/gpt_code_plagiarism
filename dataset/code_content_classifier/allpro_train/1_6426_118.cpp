#include <bits/stdc++.h>
int main() {
  int n, x[200];
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &x[i]);
  std::sort(x, x + n);
  int t = 10, cnt, p;
  cnt = p = 0;
  for (int i = 0; i < n; i++) {
    t += x[i];
    if (t <= 720) {
      cnt++;
      if (t > 360) p = p + t - 360;
    } else
      break;
  }
  printf("%d %d\n", cnt, p);
  return 0;
}