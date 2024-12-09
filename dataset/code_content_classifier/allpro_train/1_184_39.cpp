#include <bits/stdc++.h>
const double PI = acos(-1.0);
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    printf("%.12lf\n", cos(PI / 4.0 / n) / sin(PI / 2.0 / n));
  }
  return 0;
}
