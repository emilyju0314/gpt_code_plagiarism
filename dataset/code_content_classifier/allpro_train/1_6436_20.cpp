#include <bits/stdc++.h>
using namespace std;
const int Maxn = 105;
const double Eps = 1e-7;
inline int eps(double x, double y) {
  if (fabs(x - y) < Eps) return 0;
  return x < y ? -1 : 1;
}
struct Node {
  double x, y;
  Node() {}
  Node(double x, double y) : x(x), y(y) {}
  double dist(const Node &e) const {
    return (x - e.x) * (x - e.x) + (y - e.y) * (y - e.y);
  }
  double operator*(const Node &e) const { return x * e.x + y * e.y; }
} node[Maxn];
int n;
bool perpendicular;
double ans;
bool find(Node e) {
  for (int i = 0; i < n; ++i)
    if (eps(node[i].x, e.x) == 0 && eps(node[i].y, e.y) == 0) return true;
  return false;
}
bool checkLen(double r, Node e) {
  for (int i = 0; i < n; ++i)
    if (eps(e.dist(node[i]), r) < 0) return false;
  return true;
}
bool check(int i, int j, int k) {
  int tmp = eps(Node(node[j].x - node[i].x, node[j].y - node[i].y) *
                    Node(node[k].x - node[i].x, node[k].y - node[i].y),
                0);
  if (tmp == 0 && find(Node(node[j].x + node[k].x - node[i].x,
                            node[j].y + node[k].y - node[i].y))) {
    Node o = Node((node[j].x + node[k].x) / 2, (node[j].y + node[k].y) / 2);
    double r = o.dist(node[i]);
    if (checkLen(r, o)) ans = max(ans, r);
  }
  return tmp > 0;
}
Node getC(int i, int j, int k) {
  double x1 = node[i].x, y1 = node[i].y;
  double x3 = node[j].x, y3 = node[j].y;
  double x4 = node[k].x, y4 = node[k].y;
  return Node(0.5 * (((y3 - y1) * (x4 * x4 + y4 * y4) +
                      (y4 - y3) * (x1 * x1 + y1 * y1) -
                      (y4 - y1) * (x3 * x3 + y3 * y3)) /
                     ((x4 - x1) * (y3 - y1) - (x3 - x1) * (y4 - y1))),
              0.5 * (((x3 - x1) * (x4 * x4 + y4 * y4) +
                      (x4 - x3) * (x1 * x1 + y1 * y1) -
                      (x4 - x1) * (x3 * x3 + y3 * y3)) /
                     ((y4 - y1) * (x3 - x1) - (y3 - y1) * (x4 - x1))));
}
bool solve() {
  ans = -1;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      for (int k = j + 1; k < n; ++k) {
        if (!check(i, j, k) || !check(j, i, k) || !check(k, i, j)) continue;
        Node o = getC(i, j, k);
        double r = o.dist(node[i]);
        if (checkLen(r, o)) ans = max(ans, r);
      }
    }
  }
  return ans > 0;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%lf%lf", &node[i].x, &node[i].y);
  if (!solve())
    puts("-1");
  else
    printf("%.6f\n", sqrt(ans));
  return 0;
}
