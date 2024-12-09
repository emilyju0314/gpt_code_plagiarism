#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%i", &n);
  int d[101];
  for (int i = 2; i <= n; i++) scanf("%i", &d[i]);
  int a, b;
  scanf("%i", &a);
  scanf("%i", &b);
  int count = 0;
  for (int i = a + 1; i <= b; i++) count += d[i];
  printf("%i", count);
  return 0;
}
