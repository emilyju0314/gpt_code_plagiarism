#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1 << 19;
const double pi = acos(-1);
int n, r;
double a[MAXN], tot;
int z, g;
int main() {
  scanf("%d%d", &n, &r);
  n = 1 << n;
  for (int(i) = (0); (i) < (n); (i)++) {
    scanf("%lf", a + i);
    tot += a[i];
  }
  printf("%.8f\n", tot / n);
  for (int(i) = (0); (i) < (r); (i)++) {
    scanf("%d%d", &z, &g);
    tot -= a[z];
    a[z] = g;
    tot += a[z];
    printf("%.8f\n", tot / n);
  }
  return 0;
}
