#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-12;
const double INF = 1e50;
struct Point {
  long long x, y, z;
  void Read() { cin >> x >> y >> z; }
  Point operator+=(Point p) {
    x += p.x;
    y += p.y;
    z += p.z;
  }
  Point operator-=(Point p) {
    x -= p.x;
    y -= p.y;
    z -= p.z;
  }
};
Point A, V;
long long ca;
long long R;
int n;
Point A2[100];
long long R2[100];
int m[100];
Point P[100][10];
long long DotProduct(Point a, Point b) {
  return a.x * b.x + a.y * b.y + a.z * b.z;
}
void Read() {
  A.Read();
  V.Read();
  cin >> R;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    A2[i].Read();
    cin >> R2[i] >> m[i];
    for (int j = 0; j < m[i]; ++j) {
      P[i][j].Read();
      P[i][j] += A2[i];
    }
  }
}
double Com(Point B, long long r) {
  Point d = A;
  d -= B;
  long long cb = DotProduct(V, d) * 2;
  long long cc = DotProduct(d, d) - (R + r) * (R + r);
  long long delta = cb * cb - ca * cc * 4;
  if (delta < 0) return INF;
  double sd = sqrt(delta);
  double res1 = ((double)-cb - sd) / ca / 2, res2 = ((double)-cb + sd) / ca / 2;
  if (res1 > res2) swap(res1, res2);
  if (res2 < EPS) return INF;
  if (res1 < EPS) return res2;
  return res1;
}
bool Solve(double &res) {
  ca = DotProduct(V, V);
  res = INF;
  for (int i = 0; i < n; ++i) {
    res = min(res, Com(A2[i], R2[i]));
    for (int j = 0; j < m[i]; ++j) {
      res = min(res, Com(P[i][j], 0));
    }
  }
  if (res > INF / 2) return false;
  return true;
}
int main() {
  Read();
  double res;
  if (Solve(res))
    printf("%.8lf\n", res);
  else
    printf("-1\n");
  return 0;
}
