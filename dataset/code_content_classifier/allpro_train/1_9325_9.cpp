#include <bits/stdc++.h>
using namespace std;
struct Point {
  double x;
  double y;
};
Point C, S, H;
double AE, BE, cs, sh, ch;
double fn(double ratio) {
  Point p;
  p.x = ratio * S.x + (1 - ratio) * H.x;
  p.y = ratio * S.y + (1 - ratio) * H.y;
  double cp = hypot(C.x - p.x, C.y - p.y);
  double ps = hypot(p.x - S.x, p.y - S.y);
  double ph = hypot(p.x - H.x, p.y - H.y);
  if (AE + cs + sh > cp + ps + sh && BE + ch > cp + ph) {
    return cp + min(AE + cs + sh - cp - ps - sh, BE + ch - cp - ph);
  }
  Point q;
  double l = 0, r = 1, m, cq, qs, qh;
  for (int i = 0; i < 100; ++i) {
    m = (l + r) * 0.5;
    q.x = (1 - m) * C.x + m * p.x;
    q.y = (1 - m) * C.y + m * p.y;
    cq = m * cp;
    qs = hypot(q.x - S.x, q.y - S.y);
    qh = hypot(q.x - H.x, q.y - H.y);
    if (AE + cs + sh > cq + qs + sh && BE + ch > cq + qh) {
      l = m;
    } else {
      r = m;
    }
  }
  return (l + r) * 0.5 * cp;
}
int main() {
  cin >> AE >> BE >> C.x >> C.y >> H.x >> H.y >> S.x >> S.y;
  cs = hypot(C.x - S.x, C.y - S.y);
  sh = hypot(S.x - H.x, S.y - H.y);
  ch = hypot(C.x - H.x, C.y - H.y);
  AE += 1e-10;
  BE += 1e-10;
  if (BE + ch > cs + sh) {
    cout << fixed << setw(6) << min(AE + cs + sh, BE + ch) << endl;
  } else {
    double l = 0, r = 1, lm, rm;
    for (int i = 0; i < 100; ++i) {
      lm = (2 * l + r) / 3;
      rm = (l + 2 * r) / 3;
      if (fn(lm) > fn(rm)) {
        r = rm;
      } else {
        l = lm;
      }
    }
    cout << fixed << setw(6) << fn((l + r) * 0.5) << endl;
  }
  return 0;
}
