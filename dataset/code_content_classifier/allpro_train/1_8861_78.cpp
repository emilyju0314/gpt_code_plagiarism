#include <bits/stdc++.h>
using namespace std;
int n;
double x, ans, t;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lf", &x);
    t = (t * (i - 1) + x) / i;
    ans = max(ans, t);
  }
  printf("%.16lf\n", ans);
  return 0;
}