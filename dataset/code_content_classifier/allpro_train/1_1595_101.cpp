#include <bits/stdc++.h>
using namespace std;
struct shar {
  double x, v, m;
  shar(){};
  shar(double x, double v, double m) : x(x), v(v), m(m){};
  friend istream& operator>>(istream& is, shar& a) {
    is >> a.x >> a.v >> a.m;
    return is;
  }
};
const double EPS = 1e-6;
void bums(shar& a, shar& b) {
  double tempav = ((a.m - b.m) * a.v + 2 * b.m * b.v) / (a.m + b.m);
  b.v = ((b.m - a.m) * b.v + 2 * a.m * a.v) / (a.m + b.m);
  a.v = tempav;
}
const int MAXN = 10;
int n, t;
vector<shar> Q;
void moveall(double t) {
  for (int i = 0; i < (n); ++i) {
    Q[i].x += Q[i].v * t;
  }
}
int main() {
  cin >> n >> t;
  Q.resize(n);
  for (int i = 0; i < (n); ++i) cin >> Q[i];
  double t0 = 0;
  while (true) {
    double tt = t - t0;
    int ia, ib;
    for (int i = 0; i < (n); ++i) {
      for (int j = 0; j < (n); ++j) {
        if (i != j && abs(Q[i].v - Q[j].v) > EPS &&
            abs(Q[i].x - Q[j].x) > EPS &&
            (Q[i].x - Q[j].x) / (Q[j].v - Q[i].v) < tt &&
            (Q[i].x - Q[j].x) / (Q[j].v - Q[i].v) > EPS) {
          ia = i;
          ib = j;
          tt = (Q[i].x - Q[j].x) / (Q[j].v - Q[i].v);
        }
      }
    }
    if (abs(t0 + tt - t) < EPS) {
      moveall(tt);
      break;
    }
    moveall(tt);
    for (int i = 0; i < (n); ++i)
      for (int j = i + 1; j < n; ++j) {
        if (i != j && abs(Q[i].x - Q[j].x) < EPS) {
          bums(Q[i], Q[j]);
          break;
        }
      }
    t0 += tt;
  }
  for (int i = 0; i < (n); ++i) {
    printf("%.12f\n", Q[i].x);
  }
  return 0;
}
