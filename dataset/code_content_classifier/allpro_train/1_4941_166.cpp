#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000")
using namespace std;
struct P {
  long long x, y;
};
bool operator<(const P& a, const P& b) {
  return a.x < b.x || (a.x == b.x && a.y > b.y);
}
const int N = 100010;
P a[N], p[N];
long long DY(P a, P b, P c) {
  long long cy = (a.y + c.x * c.x - a.x * a.x) * (b.x - a.x) +
                 (b.y - b.x * b.x - (a.y - a.x * a.x)) * (c.x - a.x);
  return c.y * (b.x - a.x) - cy;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; scanf("%lld%lld", &a[i].x, &a[i].y), i++)
    ;
  sort(a, a + n);
  int k = 0;
  for (int i = 0; i < n;) {
    if (k == 0) {
      p[k++] = a[i];
      i++;
    } else if (a[i].x == p[k - 1].x)
      i++;
    else if (k == 1) {
      p[k++] = a[i];
      i++;
    } else if (DY(p[k - 2], p[k - 1], a[i]) <= 0) {
      p[k++] = a[i];
      i++;
    } else
      k--;
  }
  int r = 0;
  for (int i = 1; i < k; i++)
    if (i == 1 || DY(p[i - 2], p[i - 1], p[i]) < 0) r++;
  printf("%d\n", r);
  return 0;
}
