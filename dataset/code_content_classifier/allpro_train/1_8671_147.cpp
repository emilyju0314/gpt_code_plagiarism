#include <bits/stdc++.h>
using namespace std;
struct point {
  long long x, y;
  point(long long a, long long b) : x(a), y(b){};
};
long long md(point a, point b) { return abs(a.x - b.x) + abs(a.y - b.y); }
int main() {
  vector<point> v;
  point s(0, 0);
  long long x0, y0, ax, bx, ay, by, t, maxx = 5e16, res = 0, n;
  cin >> x0 >> y0 >> ax >> ay >> bx >> by >> s.x >> s.y >> t;
  for (; x0 < maxx && y0 < maxx; x0 = ax * x0 + bx, y0 = ay * y0 + by)
    v.push_back(point(x0, y0));
  n = v.size();
  for (int i = 0; i < n; i++) {
    long long r = 1, tt = t - md(s, v[i]);
    for (int j = i - 1; j >= 0 && tt >= 0; j--) {
      tt -= md(v[j], v[j + 1]);
      r++;
    }
    if (tt < 0) {
      res = max(res, r - 1);
      continue;
    }
    if (i == n - 1) {
      res = max(res, r);
      continue;
    }
    tt -= md(v[0], v[i + 1]);
    r++;
    for (int j = i + 2; j < n && tt >= 0; j++) {
      tt -= md(v[j - 1], v[j]);
      r++;
    }
    if (tt < 0)
      res = max(res, r - 1);
    else
      res = max(res, r);
  }
  cout << res;
  return 0;
}
