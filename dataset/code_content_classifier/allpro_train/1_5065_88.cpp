#include <bits/stdc++.h>
using namespace std;
const long double pi = acos(-1);
struct Mat {
  long double a[3][3];
  Mat() { memset(a, 0, sizeof(a)); }
};
Mat t[4 * 300005];
Mat mat;
long double rot[300005], len[300005];
Mat operator*(const Mat &x, const Mat &y) {
  Mat ret;
  for (int i = (0); i <= (2); i++) {
    for (int j = (0); j <= (2); j++) {
      for (int k = (0); k <= (2); k++) {
        ret.a[i][j] += x.a[i][k] * y.a[k][j];
      }
    }
  }
  return ret;
}
Mat get_rot(long double alpha) {
  Mat ret;
  ret.a[0][0] = cos(alpha);
  ret.a[0][1] = sin(alpha);
  ret.a[1][0] = -sin(alpha);
  ret.a[1][1] = cos(alpha);
  ret.a[2][2] = 1;
  return ret;
}
Mat get_len(long double len) {
  Mat ret;
  for (int i = (0); i <= (2); i++) ret.a[i][i] = 1;
  ret.a[0][2] = len;
  return ret;
}
void push_up(int rt) { t[rt] = t[rt << 1] * t[rt << 1 | 1]; }
void build(int l, int r, int rt) {
  if (l == r) {
    t[rt] = get_rot(rot[l]) * get_len(len[l]);
    return;
  }
  int mid = (l + r) >> 1;
  build(l, mid, rt << 1);
  build(mid + 1, r, rt << 1 | 1);
  push_up(rt);
}
void update(int l, int r, int rt, int p) {
  if (l == r) {
    t[rt] = get_rot(rot[l]) * get_len(len[l]);
    return;
  }
  int mid = (l + r) >> 1;
  if (p <= mid)
    update(l, mid, rt << 1, p);
  else
    update(mid + 1, r, rt << 1 | 1, p);
  push_up(rt);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  while (cin >> n >> m) {
    for (int i = (1); i <= (n); i++) {
      len[i] = 1;
      rot[i] = 0;
    }
    build(1, n, 1);
    for (int i = (1); i <= (m); i++) {
      int x, y, z;
      cin >> x >> y >> z;
      if (x == 2)
        rot[y] += (long double)z / 180 * pi;
      else
        len[y] += z;
      update(1, n, 1, y);
      cout << fixed << setprecision(15) << t[1].a[0][2] << " " << t[1].a[1][2]
           << endl;
    }
  }
  return 0;
}
