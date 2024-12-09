#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0;
  bool flg = false;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') flg = true;
  for (; isdigit(ch); ch = getchar()) x = (x << 3) + (x << 1) + (ch ^ 48);
  return flg ? -x : x;
}
const double eps = 1e-10;
int n;
struct Pt {
  double x, y;
} a[100010];
Pt operator+(Pt x, Pt y) { return (Pt){x.x + y.x, x.y + y.y}; }
Pt operator-(Pt x, Pt y) { return (Pt){x.x - y.x, x.y - y.y}; }
Pt operator-(Pt x) { return (Pt){-x.x, -x.y}; }
Pt operator*(Pt x, Pt y) {
  return (Pt){x.x * y.x - x.y * y.y, x.x * y.y + x.y * y.x};
}
Pt operator*(Pt x, double y) { return (Pt){x.x * y, x.y * y}; }
double dot(Pt x, Pt y) { return x.x * y.x + x.y * y.y; }
double cross(Pt x, Pt y) { return x.x * y.y - x.y * y.x; }
bool operator<(Pt x, Pt y) {
  bool a = x.x > eps || fabs(x.x) < eps && x.y > eps;
  bool b = y.x > eps || fabs(y.x) < eps && y.y > eps;
  if (a ^ b) return a > b;
  return cross(x, y) < -eps;
}
struct C {
  int t, v;
} c[200010];
int top;
bool operator<(const C &x, const C &y) { return x.t < y.t; }
struct E {
  Pt v;
  int p;
} b[200010];
int btop;
bool operator<(const E &x, const E &y) {
  if (x.v < y.v) return 1;
  if (y.v < x.v) return 0;
  return x.p < y.p;
}
int d[200010];
int tri[200010], S;
void add(int x, int v) {
  S += v;
  for (; x <= btop; x += x & -x) tri[x] += v;
}
int ask(int x) {
  int res = 0;
  for (; x; x -= x & -x) res += tri[x];
  return res;
}
long long check(double r) {
  if (fabs(r) < eps) return 0;
  long long tot = 0;
  top = btop = 0;
  double r2 = r * r, d2;
  int I = 0, O = 0;
  for (int i = 1; i <= n; i++)
    if ((d2 = dot(a[i], a[i])) < r2 + eps)
      I++;
    else {
      O++;
      double d = sqrt(d2);
      double _cos = r / d, s = sqrt(d2 - r2), _sin = s / d;
      Pt A = a[i] * (Pt){_cos, _sin};
      Pt B = a[i] * (Pt){_cos, -_sin};
      b[++btop] = (E){A, i}, b[++btop] = (E){B, i + n};
    }
  stable_sort(b + 1, b + btop + 1);
  for (int i = 1; i <= btop; i++) d[b[i].p] = i;
  for (int i = 1; i <= n; i++)
    if ((d2 = dot(a[i], a[i])) < r2 + eps)
      ;
    else {
      int x = d[i], y = d[i + n];
      if (x <= y)
        c[++top] = (C){x, y}, c[++top] = (C){y, -y};
      else
        add(y, 1), c[++top] = (C){y, -y}, c[++top] = (C){x, y};
    }
  sort(c + 1, c + top + 1);
  for (int i = 1; i <= top; i++) {
    C &t = c[i];
    if (t.v > 0) {
      if (t.t <= t.v) {
        tot += ask(t.v) - ask(t.t);
      } else {
        tot += S - ask(t.t) + ask(t.v);
      }
      add(t.v, 1);
    } else {
      add(-t.v, -1);
    }
  }
  long long res =
      1LL * I * (I - 1) / 2 + 1LL * I * O + 1LL * O * (O - 1) / 2 - tot;
  S = 0;
  for (int i = 1; i <= btop; i++) tri[i] = 0;
  return res;
}
int main() {
  n = read();
  long long K = read();
  for (int i = 1; i <= n; i++) a[i].x = read(), a[i].y = read();
  double l = 0, r = 14200, mid;
  for (int T = 60; T--;) {
    mid = (l + r) / 2;
    if (check(mid) >= K)
      r = mid;
    else
      l = mid;
  }
  printf("%.10lf\n", l);
  return 0;
}
