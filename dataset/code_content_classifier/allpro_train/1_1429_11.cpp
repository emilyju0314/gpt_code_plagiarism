#include <bits/stdc++.h>
int main() {
  long long int r, g, b;
  long long int max, min, mid;
  long long int sum, t;
  scanf("%lld", &r);
  max = r;
  min = r;
  scanf("%lld", &g);
  if (max < g) max = g;
  if (min > g) min = g;
  scanf("%lld", &b);
  if (max < b) max = b;
  if (min > b) min = b;
  sum = r + g + b;
  mid = sum - (max + min);
  t = sum / 3;
  if (min + mid > t)
    printf("%lld", t);
  else
    printf("%lld", min + mid);
  return 0;
}
