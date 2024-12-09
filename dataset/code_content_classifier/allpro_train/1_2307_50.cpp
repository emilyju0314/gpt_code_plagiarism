#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
struct node {
  double x, y;
} po[1010];
double dis(node a, node b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
node mark;
double cha(node a, node b, node c) {
  return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}
double get(node a, node b, node c) {
  return abs(cha(a, b, c)) / dis(a, b) / 2.0;
}
int main() {
  int n;
  cin >> n;
  double ans = 1e9;
  for (int i = (0); i < (n); ++i) cin >> po[i].x >> po[i].y;
  for (int i = (0); i < (n); ++i) {
    ans = min(ans, get(po[(i - 1 + n) % n], po[(i + 1) % n], po[i]));
  }
  cout << fixed << setprecision(10) << ans << '\n';
}
