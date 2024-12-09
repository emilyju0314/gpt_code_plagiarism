#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int s = 0;
  char c;
  while ((c = getchar()) < '0' || c > '9')
    ;
  do {
    s = s * 10 + c - '0';
  } while ((c = getchar()) >= '0' && c <= '9');
  return s;
}
const int N = 100010, RN = 1e5;
int n, tot, mi, t;
int cv[N * 6];
struct vct {
  long long x, y;
  double ang;
  vct() {}
  vct(int x, int y) : x(x), y(y){};
  bool operator==(const vct &b) const { return x == b.x && y == b.y; }
} v[N * 6];
inline long long cross(long long ax, long long ay, long long bx, long long by) {
  return ax * by - ay * bx;
}
void insertvct(int x, int y) {
  int i = ++tot;
  v[i].x = x, v[i].y = y;
  if (v[i].x < v[mi].x || (v[i].x == v[mi].x && v[i].y < v[mi].y)) mi = i;
}
bool cmp(const vct &a, const vct &b) {
  if (a.ang != b.ang) return a.ang < b.ang;
  return a.x > b.x;
}
void make_convex() {
  cv[1] = 1;
  int k = 2;
  while (v[k] == v[1]) k++;
  cv[2] = k++;
  while (v[k] == v[cv[2]]) k++;
  cv[t = 3] = k;
  v[++tot] = v[1];
  for (int i = k + 1; i <= tot; i++) {
    while (t >= 3 &&
           cross(v[i].x - v[cv[t]].x, v[i].y - v[cv[t]].y,
                 v[cv[t]].x - v[cv[t - 1]].x, v[cv[t]].y - v[cv[t - 1]].y) >= 0)
      t--;
    cv[++t] = i;
  }
  t--;
}
inline double getr(const vct &a, const vct &b, const vct &c) {
  double aa = (sqrt(((a.x - b.x) * (a.x - b.x)) + ((a.y - b.y) * (a.y - b.y)))),
         bb = (sqrt(((b.x - c.x) * (b.x - c.x)) + ((b.y - c.y) * (b.y - c.y)))),
         cc = (sqrt(((c.x - a.x) * (c.x - a.x)) + ((c.y - a.y) * (c.y - a.y))));
  double ss = 2.0 * abs(cross(b.x - a.x, b.y - a.y, c.x - a.x, c.y - a.y));
  if (ss <= 1e-10) return 0;
  return aa * bb * cc / ss;
}
int main() {
  int i, j, aa, bb, cc;
  n = read(), mi = 1;
  for (i = 1; i <= n; i++) {
    aa = read(), bb = read();
    cc = read();
    if (aa - cc >= 0)
      insertvct(aa - cc, bb);
    else
      insertvct(0, min(RN, bb + cc - aa)), insertvct(0, max(0, bb - cc + aa));
    if (aa + cc <= RN)
      insertvct(aa + cc, bb);
    else
      insertvct(RN, min(RN, bb + cc - (RN - aa))),
          insertvct(RN, max(0, bb - cc + (RN - aa)));
    if (bb - cc >= 0)
      insertvct(aa, bb - cc);
    else
      insertvct(min(RN, aa + cc - bb), 0), insertvct(max(0, aa - cc + bb), 0);
    if (bb + cc <= RN)
      insertvct(aa, bb + cc);
    else
      insertvct(min(RN, aa + cc - (RN - bb)), RN),
          insertvct(max(0, aa - cc + (RN - bb)), RN);
  }
  swap(v[1], v[mi]);
  for (i = 2; i <= tot; i++) v[i].ang = atan2(v[i].y - v[1].y, v[i].x - v[1].x);
  sort(v + 2, v + 1 + tot, cmp);
  make_convex();
  double mx = getr(v[cv[t]], v[cv[1]], v[cv[2]]), tmp;
  int a1 = t, a2 = 1, a3 = 2;
  if ((tmp = getr(v[cv[t - 1]], v[cv[t]], v[cv[1]])) > mx)
    a1 = t - 1, a2 = t, a3 = 1, mx = tmp;
  for (i = 3; i <= t; i++)
    if ((tmp = getr(v[cv[i - 2]], v[cv[i - 1]], v[cv[i]])) > mx)
      a3 = i, mx = tmp;
  if (a3 >= 3) a1 = a3 - 2, a2 = a3 - 1;
  printf("%I64d %I64d\n%I64d %I64d\n%I64d %I64d\n", v[cv[a1]].x, v[cv[a1]].y,
         v[cv[a2]].x, v[cv[a2]].y, v[cv[a3]].x, v[cv[a3]].y);
  return 0;
}
