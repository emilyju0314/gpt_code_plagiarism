#include <bits/stdc++.h>
using namespace std;
long long ans;
double s3 = sqrt(3);
double dis(double x, double y) { return sqrt(x * x + y * y); }
int can(double x, double y, int n) {
  if ((dis(x + 0.5 * s3, y + 0.5) - 1e-9 < n) && (dis(x, y + 1) - 1e-9 < n) &&
      (dis(x - 0.5 * s3, y - 0.5) - 1e-9 < n))
    return 1;
  return 0;
}
int main() {
  int i, j, left, right, mid, n;
  long long ans;
  scanf("%d", &n);
  ans = 0;
  for (i = 0; i * sqrt(3) < n; i++) {
    left = 0;
    right = n;
    while (right - left > 1) {
      mid = (left + right) / 2;
      if (can((i + mid * 0.5) * s3, 1.5 * mid, n))
        left = mid;
      else
        right = mid;
    }
    ans += left;
  }
  ans *= 6;
  ans++;
  cout << ans << endl;
}
