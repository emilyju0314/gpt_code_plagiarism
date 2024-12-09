#include <bits/stdc++.h>
using namespace std;
int a, b;
int main() {
  int cas;
  scanf("%d", &cas);
  while (cas--) {
    scanf("%d %d", &a, &b);
    if (b == 0) {
      puts("1.000000");
      continue;
    }
    if (b != 0 && a == 0) {
      puts("0.500000");
      continue;
    }
    double ans;
    if (a >= 4 * b) {
      ans = 1.0 * (a - b) / a;
    } else {
      ans = 1.0 * (8 * b + a) / (16 * b);
    }
    printf("%.10lf\n", ans);
  }
  return 0;
}
