#include <bits/stdc++.h>
using namespace std;
int n, s[300010], a[300010], b[300010], h[300010], i, now, t;
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]), s[i] = n;
  for (i = 1; i <= n; i++) scanf("%d", &b[i]);
  s[0] = n;
  t = 0;
  now = n;
  while (s[t]) {
    if (now == 0) break;
    if (now < s[t]) t++;
    if (now + b[now] - a[now + b[now]] < s[t + 1])
      s[t + 1] = now + b[now] - a[now + b[now]], h[t + 1] = now;
    now--;
    if (s[t + 1] == 0) {
      t++;
      break;
    }
  }
  if (s[t] == 0) {
    printf("%d\n", t);
    for (i = 2; i <= t; i++) printf("%d ", h[i]);
    printf("0\n");
  } else
    printf("-1\n");
}
