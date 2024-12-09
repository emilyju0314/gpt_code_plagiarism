#include <bits/stdc++.h>
using namespace std;
const int nMax = 1e5;
int main() {
  double m, r;
  scanf("%lf%lf", &m, &r);
  double R = sqrt(r * r + r * r);
  double total = 2 * r * m;
  for (int i = 2; i <= m; i++) total += ((i * 2 * r) * (m - i + 1) * 2);
  total -= ((r * 2) * (m - 1) * m);
  total += ((R) * (m - 1) * m);
  if (total >= 3) {
    total -= ((r * 2) * (m - 2) * 2);
    total += ((R) * (m - 2) * 2);
    total -= ((r * 2) * (m - 2) * (m - 3));
    total += ((R) * (m - 2) * (m - 3));
  }
  printf("%.11lf\n", total / m / m);
  return 0;
}
