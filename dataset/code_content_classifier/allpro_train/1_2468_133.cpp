#include <bits/stdc++.h>
using namespace std;
int n, m, A[503];
double cev;
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &A[i]);
  }
  for (int i = 1; i <= m; i++) {
    double x, y, cost, z;
    scanf("%lf %lf %lf", &x, &y, &cost);
    z = A[(int)x] + A[(int)y];
    cev = max(cev, z / cost);
  }
  printf("%.15lf", cev);
  return 0;
}
