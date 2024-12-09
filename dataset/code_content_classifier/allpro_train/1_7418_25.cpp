#include <bits/stdc++.h>
using namespace std;
struct point {
  long double x, y;
};
point centroid(int n, point pnt[]);
long double dis(point a, point b);
point new_centroid(point pivot, long double dist);
long double ang(point final, point initial, point pivot);
point print(point p, point cent, long double angle, long double rot,
            long double dist);
int main() {
  int n, q;
  int i, j, k;
  scanf("%d %d", &n, &q);
  point pnt[n], cnt, prev_cnt, del;
  long double dist[n], an[n], rot = 0;
  int preva, prevb;
  cin >> del.x >> del.y;
  pnt[0].x = 0.0;
  pnt[0].y = 0.0;
  for (i = 1; i < n; i++) {
    long double ab, bb;
    cin >> ab >> bb;
    pnt[i].x = ab - del.x;
    pnt[i].y = bb - del.y;
  }
  cnt = centroid(n, pnt);
  for (i = 0; i < n; i++) {
    dist[i] = dis(pnt[i], cnt);
    an[i] = atan2(pnt[i].y - cnt.y, pnt[i].x - cnt.x);
  }
  preva = 0;
  prevb = 1;
  for (i = 0; i < q; i++) {
    scanf("%d", &j);
    if (j == 1) {
      int f, t, p;
      point piv;
      scanf("%d %d", &f, &t);
      prev_cnt = cnt;
      if (preva == f - 1) {
        p = prevb;
        preva = t - 1;
      } else {
        p = preva;
        prevb = t - 1;
      }
      piv = print(pnt[p], cnt, an[p], rot, dist[p]);
      cnt = new_centroid(piv, dist[p]);
      rot += -acos(-1.0) / 2 - atan2l(prev_cnt.y - piv.y, prev_cnt.x - piv.x);
    } else {
      int key;
      point ans;
      scanf("%d", &key);
      ans = print(pnt[key - 1], cnt, an[key - 1], rot, dist[key - 1]);
      cout << setprecision(10) << fixed << ans.x + del.x << " " << ans.y + del.y
           << endl;
    }
  }
  return 0;
}
point print(point p, point cent, long double angle, long double rot,
            long double dist) {
  point ans;
  ans.x = cent.x + dist * cos(angle + rot);
  ans.y = cent.y + dist * sin(angle + rot);
  return ans;
}
long double ang(point final, point initial, point pivot) {
  long double theta, a, b, c;
  a = dis(final, pivot);
  b = dis(initial, pivot);
  c = dis(final, initial);
  theta = acos((a * a + b * b - c * c) / (2 * a * b));
  if (theta < 0) theta += acos(-1.0);
  if (final.x > initial.x)
    return theta;
  else
    return -theta;
}
point new_centroid(point pivot, long double dist) {
  point cnt;
  cnt.x = pivot.x;
  cnt.y = pivot.y - dist;
  return cnt;
}
point centroid(int n, point pnt[]) {
  point cnt;
  long double area, k;
  int i, a, b;
  cnt.x = 0.0;
  cnt.y = 0.0;
  area = 0.0;
  for (i = 0; i < n; i++) {
    a = i;
    b = (i + 1) % n;
    k = pnt[a].x * pnt[b].y - pnt[a].y * pnt[b].x;
    cnt.x += (pnt[a].x + pnt[b].x) * k;
    cnt.y += (pnt[a].y + pnt[b].y) * k;
    area += k;
  }
  area *= 0.5;
  cnt.x /= (6 * area);
  cnt.y /= (6 * area);
  return cnt;
}
long double dis(point a, point b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
