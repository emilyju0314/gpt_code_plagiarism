#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int n;
int a[maxn];
long long x_1, y_1, x2, y2, cx = 0, cy = 0;
long long time1[maxn], time2[maxn];
long long sumx[maxn], sumy[maxn];
char s[maxn];
bool check(long long mid) {
  long long fx = mid / n * sumx[n] + sumx[mid % n];
  long long fy = mid / n * sumy[n] + sumy[mid % n];
  if (abs(x2 - (x_1 + fx)) + abs(y2 - (y_1 + fy)) <= mid)
    return true;
  else
    return false;
}
int main() {
  long long ans = 0;
  scanf("%lld %lld %lld %lld", &x_1, &y_1, &x2, &y2);
  scanf("%d", &n);
  scanf("%s", s + 1);
  for (int i = 1; i <= n; i++) {
    if (s[i] == 'U') {
      time1[i] = 0;
      time2[i] = 1;
    }
    if (s[i] == 'D') {
      time1[i] = 0;
      time2[i] = -1;
    }
    if (s[i] == 'L') {
      time1[i] = -1;
      time2[i] = 0;
    }
    if (s[i] == 'R') {
      time1[i] = 1;
      time2[i] = 0;
    }
    sumx[i] = sumx[i - 1] + time1[i];
    sumy[i] = sumy[i - 1] + time2[i];
    cx += time1[i];
    cy += time2[i];
  }
  long long resx = x2 - x_1, resy = y2 - y_1, d = 0,
            res = abs(resx) + abs(resy);
  for (int i = 1; i <= n; i++) {
    if (time1[i] * resx > 0)
      res--;
    else
      res++;
    if (time2[i] * resy > 0)
      res--;
    else
      res++;
    if (res <= i) {
      ans = i;
      printf("%lld", ans);
      return 0;
    }
  }
  if (resx * cx <= 0 && cx != 0) d += cx;
  if (resy * cy <= 0 && cy != 0) d += cy;
  if (d >= n) {
    ans = -1;
    printf("%lld", ans);
    return 0;
  }
  long long l = 1, r = 1ll << 62, mid;
  while (l + 1 < r) {
    mid = (l + r) >> 1;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  if (check(l))
    ans = l;
  else if (check(r))
    ans = r;
  else
    ans = -1;
  printf("%lld", ans);
  return 0;
}
