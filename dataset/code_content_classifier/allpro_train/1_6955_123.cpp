#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool Up(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool Down(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
struct Vec {
  int x, y;
  explicit Vec(int x, int y) : x(x), y(y) {}
  explicit Vec() : x(0), y(0) {}
  Vec operator+(const Vec &rhs) const { return Vec(x + rhs.x, y + rhs.y); }
  Vec operator-(const Vec &rhs) const { return Vec(x - rhs.x, y - rhs.y); }
  Vec operator*(const int &k) const { return Vec(x * k, y * k); }
  int operator*(const Vec &rhs) const { return x * rhs.x + y * rhs.y; }
  int operator^(const Vec &rhs) const { return x * rhs.y - y * rhs.x; }
  double getDist() const { return hypot(x, y); }
} P[129];
Vec operator*(const int &a, const Vec &b) { return Vec(a * b.x, a * b.y); }
Vec findCircumcenter(Vec o, Vec a, Vec b) {
  a = a - o;
  b = b - o;
  Vec p(a.x * a.x + a.y * a.y, b.x * b.x + b.y * b.y);
  double d = 2 * (a ^ b);
  return Vec((p ^ Vec(a.y, b.y)) / d, (Vec(a.x, b.x) ^ p) / d) + o;
}
int N, sqr[129];
bool isHole = false;
double ans = 0.0f;
double Ox, Oy;
bool Check(Vec O, double d) { return false; }
bool findCir(int x, int y) {
  for (int i(1); i <= (N); ++i)
    if (P[i].x == x && P[i].y == y) return true;
  return false;
}
void Calc(double a, double b, double c, double d, double e, double f) {
  double D = a * e - b * d;
  Ox = (c * e - b * f) / D;
  Oy = (a * f - c * d) / D;
}
int main() {
  scanf("%d", &N);
  for (int i(1); i <= (N); ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    P[i] = Vec(x, y);
    sqr[i] = x * x + y * y;
  }
  int tmp;
  static int p[3];
  for (int i(1); i <= (N); ++i)
    for (int j(i + 1); j <= (N); ++j)
      for (int k(j + 1); k <= (N); ++k) {
        p[0] = i;
        p[1] = j;
        p[2] = k;
        bool done = false;
        bool good = true;
        do {
          const Vec &a(P[p[0]]), &b(P[p[1]]), &c(P[p[2]]);
          tmp = (b - a) * (c - a);
          if (tmp < 0) good = false;
          if (tmp == 0) {
            if (!findCir(b.x + c.x - a.x, b.y + c.y - a.y))
              good = false;
            else if (tmp == 0) {
              done = true;
              Ox = 0.5 * (b.x + c.x);
              Oy = 0.5 * (b.y + c.y);
            }
          }
        } while (next_permutation(p, p + 3));
        if (!good) continue;
        const Vec &a(P[i]), &b(P[j]), &c(P[k]);
        if (!done) {
          done = true;
          Calc(2 * (a.x - c.x), 2 * (a.y - c.y), sqr[i] - sqr[k],
               2 * (b.x - c.x), 2 * (b.y - c.y), sqr[j] - sqr[k]);
        }
        double d(hypot(a.x - Ox, a.y - Oy));
        for (int c(1); c <= (N); ++c)
          if (c != i && c != j && c != k)
            if (hypot(P[c].x - Ox, P[c].y - Oy) + (1e-6) < d) {
              good = false;
              break;
            }
        if (!good) continue;
        Up(ans, d);
        isHole = true;
      }
  if (!isHole)
    puts("-1");
  else
    printf("%.6lf\n", ans);
  return 0;
}
