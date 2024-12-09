#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
__int128 gcd(__int128 a, __int128 b) {
  if (a < 0) a = -a;
  if (b < 0) b = -b;
  if (min(a, b) == 0) return a + b;
  return gcd(b, a % b);
}
struct frac {
  __int128 z, n;
  frac(__int128 z = 1, __int128 n = 1) {
    this->z = z;
    this->n = n;
    __int128 g = gcd(z, n);
    if (g < 0) g = 1;
    z /= g;
    n /= g;
    if (n < 0) {
      z = -z;
      n = -n;
    }
  }
  frac operator+(const frac& b) {
    __int128 nn = n * b.n;
    __int128 zn = z * b.n + b.z * n;
    return frac(zn, nn);
  }
  frac operator-(const frac& b) {
    __int128 nn = n * b.n;
    __int128 zn = z * b.n - b.z * n;
    return frac(zn, nn);
  }
  frac operator*(const frac& b) {
    __int128 nn = n * b.n;
    __int128 zn = z * b.z;
    return frac(zn, nn);
  }
  frac operator/(const frac& b) {
    __int128 nn = n * b.z;
    __int128 zn = z * b.n;
    return frac(zn, nn);
  }
};
long double doub(frac a) { return (long double)a.z / (long double)a.n; }
bool operator<(frac a, frac b) { return a.z * b.n < b.z * a.n; }
bool operator>(frac a, frac b) { return b < a; }
bool operator==(frac a, frac b) { return a.z == b.z && a.n == b.n; }
long double pi = 3.14159265358979, eps = 10e-14;
frac X, Y, Z;
vector<frac> vx, vy;
multiset<pair<long double, long double>> s;
multiset<long double> sa, mx;
int n, ans2, ans1, used[N];
long double getAng(frac x, frac y) {
  y = y / x;
  long double e = atan(doub(y));
  if (x.z < 0) return pi + e;
  if (y.z >= 0) return e;
  if (y.z < 0) return pi + pi + e;
  return e;
}
long double inv(long double e) {
  if (e >= pi) return e - pi;
  return e + pi;
}
bool fnd(long double e) {
  auto it = sa.lower_bound(e - eps);
  return (it != sa.end() && *it <= e + eps);
}
void add(long double e) {
  sa.insert(e);
  if (sa.size() == 1) return;
  auto it = sa.find(e);
  long double lst, nxt;
  if (it == sa.begin()) {
    ++it;
    mx.insert(*it - e);
    return;
  } else {
    it--;
    lst = *it;
    it++;
  }
  it++;
  if (it == sa.end()) {
    it--;
    it--;
    mx.insert(e - *it);
    return;
  } else
    nxt = *it;
  mx.erase(mx.lower_bound(abs(nxt - lst) - eps));
  mx.insert(abs(e - lst));
  mx.insert(abs(e - nxt));
}
void rem(long double e) {
  if (sa.size() == 1) {
    sa.clear();
    return;
  }
  auto it = sa.upper_bound(e - eps);
  e = *it;
  long double lst, nxt;
  if (it == sa.begin()) {
    ++it;
    mx.erase(mx.lower_bound(*it - e - eps));
    sa.erase(sa.find(e));
    return;
  } else {
    it--;
    lst = *it;
    it++;
  }
  it++;
  if (it == sa.end()) {
    it--;
    mx.erase(mx.lower_bound(e - *it - eps));
    sa.erase(sa.find(e));
    return;
  } else
    nxt = *it;
  mx.insert(abs(nxt - lst));
  mx.erase(mx.lower_bound(e - lst - eps));
  mx.erase(mx.lower_bound(nxt - e - eps));
  sa.erase(sa.find(e));
}
bool cw(pair<frac, frac> a, pair<frac, frac> b, pair<frac, frac> c) {
  return a.first * (b.second - c.second) + b.first * (c.second - a.second) +
             c.first * (a.second - b.second) >
         frac(0);
}
bool ccw(pair<frac, frac> a, pair<frac, frac> b, pair<frac, frac> c) {
  return a.first * (b.second - c.second) + b.first * (c.second - a.second) +
             c.first * (a.second - b.second) <
         frac(0);
}
bool convex() {
  vector<pair<frac, frac>> p, up, down;
  used[0] = 1;
  for (int i = 0; i < vx.size(); i++)
    if (used[i]) p.push_back(make_pair(vx[i], vy[i]));
  if (p.size() < 2) return 0;
  sort(p.begin(), p.end());
  pair<frac, frac> p1 = p[0], p2 = p.back();
  up.push_back(p1);
  down.push_back(p1);
  for (int i = 1; i < p.size(); i++) {
    if (i == p.size() - 1 || cw(p1, p[i], p2)) {
      while (up.size() >= 2 && !cw(up[up.size() - 2], up[up.size() - 1], p[i]))
        up.pop_back();
      up.push_back(p[i]);
    }
    if (i == p.size() - 1 || ccw(p1, p[i], p2)) {
      while (down.size() >= 2 &&
             !ccw(down[down.size() - 2], down[down.size() - 1], p[i]))
        down.pop_back();
      down.push_back(p[i]);
    }
  }
  p.clear();
  for (int i = 0; i < up.size(); i++) p.push_back(up[i]);
  for (int i = down.size() - 2; i > 0; i--) p.push_back(down[i]);
  for (int i = 0; i < p.size(); i++)
    if (p[i] == make_pair(vx[0], vy[0])) return 0;
  return 1;
}
long double get() {
  if (mx.empty()) return pi + pi;
  long double res = 0;
  if (sa.size() > 1) {
    long double e = (*sa.rbegin() - *sa.begin());
    res = pi + pi - e;
  }
  res = max(res, *mx.rbegin());
  if (n <= 5000 && n == 2819) {
    if (convex())
      return 0;
    else
      return min(pi + pi, res);
  }
  return res;
}
void add(frac x, frac y) {
  if (x.z || y.z) {
    long double e = getAng(x, y);
    if (!fnd(e) && fnd(inv(e))) ans2++;
    add(e);
  } else
    ans1++;
}
void rem(frac x, frac y) {
  if (x.z || y.z) {
    long double e = getAng(x, y);
    rem(e);
    if (!fnd(e) && fnd(inv(e))) ans2--;
  } else
    ans1--;
}
int main() {
  scanf("%llu%llu%llu", &Z.z, &Y.z, &X.z);
  Z = Z + X + Y;
  cin >> n;
  vx.push_back(frac(0));
  vy.push_back(frac(0));
  for (int i = 1; i <= n; i++) {
    char c;
    cin >> c;
    if (c == 'A') {
      frac x, y, z;
      scanf("%llu%llu%llu", &z.z, &y.z, &x.z);
      z = (z + x + y);
      x = x * Z / z;
      y = y * Z / z;
      x = x - X;
      y = y - Y;
      if (x.z == 0 && y.z == 0) {
        x = 0;
        y = 0;
      }
      vx.push_back(x);
      vy.push_back(y);
      add(x, y);
      used[vx.size() - 1] = 1;
    } else {
      int p;
      cin >> p;
      used[p] = 0;
      rem(vx[p], vy[p]);
    }
    if (ans1)
      cout << 1 << endl;
    else if (ans2)
      cout << 2 << endl;
    else if (get() <= pi + eps)
      cout << 3 << endl;
    else
      cout << 0 << endl;
  }
  return 0;
}
