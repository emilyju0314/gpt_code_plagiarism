#include <bits/stdc++.h>
using namespace std;
const int maxn = 5005;
struct point {
  double x, y, z;
};
double dist(point p1, point p2) {
  return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y) +
              (p1.z - p2.z) * (p1.z - p2.z));
}
point arr[maxn];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i].x >> arr[i].y >> arr[i].z;
  double ans = 1e50;
  for (int i = 1; i < n; i++)
    for (int j = i + 1; j < n; j++)
      ans = min(ans, (dist(arr[0], arr[i]) + dist(arr[0], arr[j]) +
                      dist(arr[i], arr[j])) /
                         2.0);
  printf("%.10lf\n", ans);
  return 0;
}
