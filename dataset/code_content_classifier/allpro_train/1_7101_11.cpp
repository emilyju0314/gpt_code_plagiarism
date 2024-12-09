#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const double eps = 1e-10;
int sgn(double x) {
  if (fabs(x) < eps) return 0;
  if (x > 0) return 1;
  return -1;
}
pair<double, double> lines[maxn];
double get(double x1, double y1, double x2, double y2) {
  if (sgn(x1 - x2) == 0) return x1;
  return x2 - (x2 - x1) * y2 / (y2 - y1);
}
double sum[maxn];
int main() {
  int sy, a, b;
  cin >> sy >> a >> b;
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%lf %lf", &lines[i].first, &lines[i].second),
        sum[i] = sum[i - 1] + lines[i].second - lines[i].first;
  sort(lines + 1, lines + 1 + n);
  int q;
  scanf("%d", &q);
  while (q--) {
    double x, y;
    scanf("%lf %lf", &x, &y);
    double left, right;
    left = get(x, y, a, sy);
    right = get(x, y, b, sy);
    int idx1 =
        upper_bound(lines + 1, lines + 1 + n, make_pair(left, left)) - lines;
    idx1--;
    int idx2 =
        upper_bound(lines + 1, lines + 1 + n, make_pair(right, right)) - lines;
    idx2--;
    if (idx1 == idx2) {
      if (sgn(lines[idx1].second - right) >= 0)
        printf("%.15f\n", 1.0 * (b - a) / 1);
      else {
        if (sgn(lines[idx1].second - left) <= 0)
          puts("0");
        else {
          double tmp = lines[idx1].second - left;
          double rate = tmp / (right - left);
          printf("%.15f\n", rate * (b - a));
        }
      }
    } else {
      double tmp = 0;
      if (sgn(lines[idx1].second - left) >= 0)
        tmp += (lines[idx1].second - left);
      if (sgn(lines[idx2].second - right) >= 0)
        tmp += right - lines[idx2].first;
      else
        tmp += lines[idx2].second - lines[idx2].first;
      idx2--;
      tmp += sum[idx2] - sum[idx1];
      double rate = tmp / (right - left);
      printf("%.15f\n", rate * (b - a) / 1);
    }
  }
  return 0;
}
