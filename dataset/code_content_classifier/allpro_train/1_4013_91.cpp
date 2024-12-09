#include <bits/stdc++.h>
using namespace std;
int n;
double ans, s, t;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lf", &t);
    ans += t * (2 * s + 1);
    s = (s + 1) * t;
  }
  printf("%.8lf\n", ans);
  return 0;
}
