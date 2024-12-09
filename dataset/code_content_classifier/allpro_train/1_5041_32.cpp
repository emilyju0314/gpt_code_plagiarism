#include <bits/stdc++.h>
int main() {
  int t, n;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    int temp, last, small, large, flag = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &temp);
      if (flag) continue;
      if (!i) {
        small = 0;
        large = temp;
      } else {
        if (temp > small + large)
          small = temp - large;
        else if (temp < small + large)
          large = temp - small;
        if (large < 0) flag = 1;
      }
    }
    if (!flag)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
