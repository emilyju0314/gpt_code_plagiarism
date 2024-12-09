#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  while (scanf("%d%d", &m, &n) != EOF) {
    double ans = 0;
    for (int i = m; i >= 1; i--) {
      ans += (pow(1.0 * i / m, n) - pow(1.0 * (i - 1) / m, n)) * i;
    }
    printf("%.4lf\n", ans);
  }
  return 0;
}
