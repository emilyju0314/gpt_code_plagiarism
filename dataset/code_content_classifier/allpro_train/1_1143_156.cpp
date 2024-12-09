#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7ffffff;
const double EPS = 1e-10;
inline int dcmp(double x, double y) {
  if (fabs(x - y) < EPS) return 0;
  return x > y ? 1 : -1;
}
struct Node {
  long long x1, y1;
  long long x2, y2;
} a[3];
long long F(Node p1, Node p2, Node &p) {
  int Xa1 = p1.x1;
  int Ya1 = p1.y1;
  int Xa2 = p1.x2;
  int Ya2 = p1.y2;
  int Xb1 = p2.x1;
  int Yb1 = p2.y1;
  int Xb2 = p2.x2;
  int Yb2 = p2.y2;
  if (max(Xa1, Xb1) <= min(Xa2, Xb2) && max(Ya1, Yb1) <= min(Ya2, Yb2)) {
    p.x1 = max(Xa1, Xb1);
    p.y1 = max(Ya1, Yb1);
    p.x2 = min(Xa2, Xb2);
    p.y2 = min(Ya2, Yb2);
    return (p.x2 - p.x1) * (p.y2 - p.y1);
  }
  return 0;
}
int main() {
  for (int i = 0; i < 3; ++i) {
    cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
  }
  long long sum = (a[0].x2 - a[0].x1) * (a[0].y2 - a[0].y1);
  long long sum1 = 0, sum2 = 0, sum3 = 0;
  Node p, p1;
  sum1 = F(a[0], a[1], p1);
  sum2 = F(a[0], a[2], p1);
  if (F(a[1], a[2], p)) sum3 = F(p, a[0], p1);
  if (sum1 + sum2 - sum3 < sum)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
