#include <bits/stdc++.h>
int main() {
  int d, h, v, e;
  double tmp;
  scanf("%d %d %d %d", &d, &h, &v, &e);
  tmp =
      (double)(10000 * (e - ((double)v * 4 / (double)(3.14159265359 * d * d))) +
               h);
  if (tmp > 0)
    printf("NO");
  else {
    tmp = -1 * h / (double)(e - (v * 4 / (double)(3.14159265359 * d * d)));
    printf("YES\n");
    printf("%f", tmp);
  }
  return 0;
}
