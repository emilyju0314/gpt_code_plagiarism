#include <bits/stdc++.h>
int main() {
  int a[3], b[3], c[3], cnt = 0;
  for (int i = 0; i < 3; i++) scanf("%d", &a[i]);
  for (int i = 0; i < 3; i++) scanf("%d", &b[i]);
  for (int i = 0; i < 3; i++) {
    c[i] = a[i] - b[i];
    if (c[i] < 0) c[i] = 0;
    c[i] /= 2;
  }
  for (int i = 0; i < 3; i++)
    if (a[i] < b[i]) cnt++;
  if (cnt == 0) puts("Yes");
  if (cnt == 3) puts("No");
  if (cnt == 1) {
    for (int i = 0; i < 3; i++) {
      if (a[i] < b[i]) {
        if (b[i] <= a[i] + c[(i + 1) % 3] + c[(i + 2) % 3])
          puts("Yes");
        else if (b[i] <=
                 a[i] +
                     (c[(i + 1) % 3] + (a[(i + 2) % 3] - b[(i + 2) % 3])) / 2)
          puts("Yes");
        else if (b[i] <=
                 a[i] +
                     (c[(i + 2) % 3] + (a[(i + 1) % 3] - b[(i + 1) % 3])) / 2)
          puts("Yes");
        else
          puts("No");
      }
    }
  }
  if (cnt == 2) {
    for (int i = 0; i < 3; i++) {
      if (a[i] >= b[i]) {
        if ((b[(i + 1) % 3] - a[(i + 1) % 3]) +
                (b[(i + 2) % 3] - a[(i + 2) % 3]) <=
            c[i])
          puts("Yes");
        else
          puts("No");
      }
    }
  }
  return 0;
}
