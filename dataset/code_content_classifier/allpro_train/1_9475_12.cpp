#include <bits/stdc++.h>
int a[1002];
int n, s, i, f = 1;
int main() {
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &s);
    a[s]++;
  }
  for (i = 0; i < 1001; i++)
    if (a[i] > (n + 1) / 2) f = 0;
  if (f)
    printf("YES");
  else
    printf("NO");
  return 0;
}
