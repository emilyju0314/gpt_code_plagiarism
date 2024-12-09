#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.00), eps = 1e-9;
struct point {
  double x, y, w, a;
};
point st, en, tank[11111];
int n, k;
void norm(double &theta) {
  while (theta < -pi + eps) theta += 2 * pi;
  while (theta > pi + eps) theta -= 2 * pi;
}
bool check(double v) {
  int i, j, s, p, q, nk = 0, it;
  double now_t, theta, dist, T, w;
  double ltheta, low, high, mid, mt, vs, fs, bs, mx, my, fx, fy;
  bool ft;
  dist = sqrt((en.x - st.x) * (en.x - st.x) + (en.y - st.y) * (en.y - st.y));
  T = dist / v;
  for (i = 0; i < n; i++) {
    theta = atan2(en.y - tank[i].y, en.x - tank[i].x);
    while (theta < tank[i].a - eps) theta += 2 * pi;
    theta -= tank[i].a;
    if (theta > pi) theta = 2 * pi - theta;
    now_t = theta / tank[i].w;
    if (v * now_t <
        sqrt((en.x - st.x) * (en.x - st.x) + (en.y - st.y) * (en.y - st.y))) {
      nk++;
      continue;
    }
    ltheta = atan2(st.y - tank[i].y, st.x - tank[i].x);
    theta = ltheta;
    while (theta < tank[i].a - eps) theta += 2 * pi;
    theta -= tank[i].a;
    if (theta > pi) theta = 2 * pi - theta;
    now_t = theta / tank[i].w;
    if (v * now_t >
        sqrt((en.x - st.x) * (en.x - st.x) + (en.y - st.y) * (en.y - st.y)))
      continue;
    if (tank[i].w == 0)
      continue;
    else {
      while (ltheta < tank[i].a - eps) ltheta += 2 * pi;
      ltheta -= tank[i].a;
      w = tank[i].w;
      if (ltheta > pi) {
        w = -w;
        ltheta = 2 * pi - ltheta;
      }
      theta = atan2(en.y - st.y, en.x - st.x);
      low = ltheta / tank[i].w;
      high = T;
      if (low > high) continue;
      mt = low;
      fs = (st.x + v * cos(theta) * mt - tank[i].x) * sin(tank[i].a + w * mt) -
           (st.y + v * sin(theta) * mt - tank[i].y) * cos(tank[i].a + w * mt);
      mt = high;
      bs = (st.x + v * cos(theta) * mt - tank[i].x) * sin(tank[i].a + w * mt) -
           (st.y + v * sin(theta) * mt - tank[i].y) * cos(tank[i].a + w * mt);
      if ((fs < eps && bs > -eps) || (fs > -eps && bs < eps)) {
        nk++;
        continue;
      }
      for (it = 0; it < 100; it++) {
        mx = mt = (2 * low + high) / 3.;
        fx =
            (st.x + v * cos(theta) * mt - tank[i].x) * sin(tank[i].a + w * mt) -
            (st.y + v * sin(theta) * mt - tank[i].y) * cos(tank[i].a + w * mt);
        my = mt = (low + 2 * high) / 3.;
        fy =
            (st.x + v * cos(theta) * mt - tank[i].x) * sin(tank[i].a + w * mt) -
            (st.y + v * sin(theta) * mt - tank[i].y) * cos(tank[i].a + w * mt);
        if ((fs > 0 && fx > fy) || (fs < 0 && fx < fy))
          low = mx;
        else
          high = my;
      }
      mt = 0.5 * (low + high);
      fx = (st.x + v * cos(theta) * mt - tank[i].x) * sin(tank[i].a + w * mt) -
           (st.y + v * sin(theta) * mt - tank[i].y) * cos(tank[i].a + w * mt);
      if ((fs > 0 && fx < eps) || (fs < 0 && fx > -eps)) {
        nk++;
        continue;
      }
    }
  }
  return nk <= k;
}
int main() {
  int i, j, s, p, q;
  double low, high, mid;
  scanf("%lf%lf%lf%lf", &st.x, &st.y, &en.x, &en.y);
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%lf%lf%lf%lf", &tank[i].x, &tank[i].y, &tank[i].a, &tank[i].w);
    norm(tank[i].a);
  }
  scanf("%d", &k);
  low = 0;
  high = 1e9;
  while (low < high - eps) {
    mid = (low + high) * 0.5;
    if (check(mid))
      high = mid;
    else
      low = mid + eps;
  }
  printf("%.20f\n", (low + high) * 0.5);
  return 0;
}
