#include <bits/stdc++.h>
using namespace std;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
double arr[105];
void IO() { freopen("in.txt", "r", stdin); }
int main() {
  long long n, ind;
  double v1, v2, x, y;
  while (~scanf("%I64d %lf %lf", &n, &v1, &v2)) {
    for (long long i = 1; i <= n; i++) scanf("%lf", &arr[i]);
    scanf("%lf %lf", &x, &y);
    double minm = 200000000000000000.0, d = 200000000000000000.0;
    for (long long i = 2; i <= n; i++) {
      double dis = sqrt(((arr[i] - x) * (arr[i] - x)) + ((0 - y) * (0 - y)));
      double t1 = (arr[i] / v1);
      double t2 = (dis / v2);
      double time = t1 + t2;
      if (time <= minm) {
        if (time == minm && dis < d) {
          d = dis;
          ind = i;
        } else if (time < minm) {
          d = dis;
          ind = i;
          minm = time;
        }
      }
    }
    printf("%I64d\n", ind);
  }
  return 0;
}
