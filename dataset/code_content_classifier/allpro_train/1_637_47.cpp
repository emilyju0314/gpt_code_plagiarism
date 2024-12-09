#include <bits/stdc++.h>
int findL(long long n) {
  long long beg = 0, end = n, h;
  while (beg <= end) {
    h = (beg + end) / 2;
    if (2 * h * h <= n * n)
      beg = h + 1;
    else
      end = h - 1;
  }
  if (2 * h * h > n * n) h--;
  return (int)h;
}
int main(void) {
  int n;
  scanf("%d", &n);
  if (n == 0) {
    printf("1\n");
    return 0;
  }
  if (n == 1) {
    printf("4\n");
    return 0;
  }
  int l = findL(n);
  int plus =
      (l * (long long)l + (l + 1) * (long long)(l + 1) <= n * (long long)n);
  printf("%d\n", (l * 2 - 1 + (plus ? 2 : 1)) * 4);
  return 0;
}
