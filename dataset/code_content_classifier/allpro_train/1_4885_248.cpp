#include <bits/stdc++.h>
int main() {
  char a[1000], b[1000];
  int n, i, n1, d = 0;
  scanf("%s", &a);
  scanf("%s", &b);
  n = strlen(a);
  n1 = n;
  for (i = 0; i < n; i++) {
    if (a[i] != b[n1 - 1]) d++;
    n1--;
  }
  if (d == 0)
    printf("YES");
  else
    printf("NO");
}
