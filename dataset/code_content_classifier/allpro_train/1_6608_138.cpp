#include <bits/stdc++.h>
using namespace std;
struct gnomes {
  double y;
  int x;
} a[1001];
int cmp(gnomes f, gnomes s) {
  if (f.y > s.y || (f.y == s.y && f.x < s.x))
    return 1;
  else
    return 0;
}
int main() {
  int n, m1, m2, k, i, v1, v2;
  double z1, z2;
  cin >> n >> m1 >> m2 >> k;
  for (i = 1; i <= n; i++) {
    a[i].x = i;
    cin >> v1 >> v2;
    z1 = 1.0 * v1 * m1 * (100 - k) / 100 + v2 * m2;
    z2 = 1.0 * v2 * m1 * (100 - k) / 100 + v1 * m2;
    if (z1 > z2)
      a[i].y = z1;
    else
      a[i].y = z2;
  }
  sort(a + 1, a + 1 + n, cmp);
  for (i = 1; i <= n; i++) {
    cout << a[i].x;
    printf(" %.2f\n", a[i].y);
  }
  return 0;
}
