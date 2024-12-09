#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3fffffff;
const int SINF = 0x7fffffff;
const long long LINF = 0x3fffffffffffffff;
const long long SLINF = 0x7fffffffffffffff;
const int MAXN = 1007;
const int MAXT = 50;
const int MAX = 2000007;
const double ANS_EPS = 3e-9;
const double EPS = 1e-13;
const double PI = acos(-1.0);
struct cT {
  cT() : x(0), y(0) {}
  cT(int _x, int _y) : x(_x), y(_y) {}
  int x, y;
} cr[MAXN];
struct eT {
  void setd(double _d, int _x) { deg = _d, x = _x; }
  bool operator<(const eT &a) const { return deg < a.deg; }
  double deg;
  int x;
} ev[MAXN * 5 + 107];
int W, H, n;
int ke;
int p[MAXN];
void init();
void input();
void work();
bool check(int i, double tst);
void add(double d1, double d2, double od, int x);
double getdist(const cT &a, const cT &b) {
  return sqrt(
      static_cast<double>(static_cast<long long>(a.x - b.x) * (a.x - b.x) +
                          static_cast<long long>(a.y - b.y) * (a.y - b.y)));
}
int main() {
  init();
  input();
  work();
}
void init() { ios::sync_with_stdio(false); }
void input() {
  scanf("%d%d%d", &W, &H, &n);
  for (int i = 1; i <= n; ++i) scanf("%d%d", &cr[i].x, &cr[i].y);
}
void work() {
  double ans = 0;
  double l, r, mid;
  for (int i = 1; i <= n; ++i) p[i] = i;
  random_shuffle(p + 1, p + 1 + n);
  for (int _i = 1; _i <= n; ++_i) {
    int i = p[_i];
    if (!check(i, ans + ANS_EPS)) continue;
    l = ans, r = MAX;
    for (int _t = 0; _t < MAXT; ++_t) {
      mid = l + (r - l) / 2;
      if (check(i, mid))
        l = mid;
      else
        r = mid;
    }
    ans = l;
  }
  cout << setprecision(15) << fixed << ans << endl;
}
bool check(int i, double tst) {
  ke = 0;
  add(tst, W - cr[i].x, 0, MAXN);
  add(tst, H - cr[i].y, PI / 2, MAXN);
  add(tst, cr[i].x, PI, MAXN);
  add(tst, cr[i].y, PI * 3 / 2, MAXN);
  for (int j = 1; j <= n; ++j) {
    if (i ^ j) {
      if (cr[i].x == cr[j].x && cr[i].y == cr[j].y) {
      } else
        add(tst, getdist(cr[i], cr[j]) / 2,
            atan2(cr[j].y - cr[i].y, cr[j].x - cr[i].x), 1);
    }
  }
  sort(ev + 1, ev + 1 + ke);
  double pre = 0;
  int nc = 0;
  for (int j = 1; j <= ke; ++j) {
    if (nc <= 1 && ev[j].deg - pre > EPS) return true;
    nc += ev[j].x;
    pre = ev[j].deg;
  }
  if (2 * PI - pre > EPS) return true;
  return false;
}
void add(double d1, double d2, double od, int x) {
  if (d1 - d2 < EPS) return;
  double dd = acos(d2 / d1);
  double dl = od - dd, dr = od + dd;
  while (dl < -EPS) dl += 2 * PI;
  while (dl > 2 * PI - EPS) dl -= 2 * PI;
  while (dr < -EPS) dr += 2 * PI;
  while (dr > 2 * PI - EPS) dr -= 2 * PI;
  if (dr - dl > -EPS) {
    ev[++ke].setd(dl, x);
    ev[++ke].setd(dr, -x);
  } else {
    ev[++ke].setd(0, x);
    ev[++ke].setd(dr, -x);
    ev[++ke].setd(dl, x);
    ev[++ke].setd(2 * PI, -x);
  }
}
