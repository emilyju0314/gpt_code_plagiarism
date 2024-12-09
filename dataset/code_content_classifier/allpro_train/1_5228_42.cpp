#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;
int cmp(double a, double b = 0) {
  return a + EPS < b ? -1 : a - EPS > b ? 1 : 0;
}
struct Point {
  double x, y;
  double ang;
  Point() {}
  Point(double x, double y) : x(x), y(y) {}
  Point operator*(double k) { return Point(x * k, y * k); }
  Point operator+(Point p) { return Point(p.x + x, p.y + y); }
  Point operator-(Point p) { return Point(x - p.x, y - p.y); }
  Point operator/(double d) { return Point(x / d, y / d); }
};
struct Recta {
  double A, B, C;
  double aux2;
  Recta() {}
  Recta(Point a, Point b) {
    A = b.y - a.y;
    B = a.x - b.x;
    C = A * a.x + B * a.y;
    aux2 = sqrt(A * A + B * B);
  }
};
double norma(Point a) { return sqrt(a.x * a.x + a.y * a.y); }
inline double dist(Recta R, Point P) {
  double aux1 = (R.A * P.x) + (R.B * P.y) - R.C;
  double aux2 = R.aux2;
  return aux1 / aux2;
}
inline double maximo(double a, double b) {
  if (cmp(a, b) < 0) return b;
  return a;
}
Point P[305];
int main() {
  int n;
  scanf("%d", &n);
  double x, y;
  for (int i = 0; i < n; i++) {
    scanf("%lf%lf", &x, &y);
    P[i] = Point(x, y);
  }
  double d;
  double area = 0.0;
  double abajo, arriva;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      Recta eje = Recta(P[i], P[j]);
      abajo = 0.0;
      arriva = 0.0;
      for (int k = 0; k < n; k++)
        if (k != i and k != j) {
          d = dist(eje, P[k]);
          if (cmp(d) < 0)
            arriva = maximo(arriva, fabs(d));
          else
            abajo = maximo(abajo, fabs(d));
        }
      if (cmp(abajo) != 0 and cmp(arriva) != 0)
        area = maximo(area, norma(P[i] - P[j]) * (abajo + arriva));
    }
  }
  printf("%.9lf\n", area / 2);
  return 0;
}
