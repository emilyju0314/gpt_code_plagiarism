#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:64000000")
int n;
double minv, maxv;
int a[1 << 10];
int main() {
  scanf("%d", &n);
  maxv = 1e+9;
  minv = 1e+2;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    double x = (double)a[i] * 100.0;
    minv = max(minv, x / (double)(i + 1));
    maxv = min(maxv, (x + 100.0) / (double)(i + 1));
  }
  double d1 = minv * (double)(n + 1);
  double d2 = maxv * (double)(n + 1);
  double d1f = floor(d1 / 100.0 + 1e-7);
  double d2f = floor(d2 / 100.0 + 1e-7);
  d2 /= 100.0;
  if (fabs(d2 - d2f) < 1e-7) --d2f;
  if (fabs(d1f - d2f) < 1e-7) {
    puts("unique");
    cout << (int)d1f << endl;
    return 0;
  }
  puts("not unique");
  return 0;
}
