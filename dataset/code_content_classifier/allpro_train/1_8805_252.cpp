#include <bits/stdc++.h>
using namespace std;
void fileio() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  if (fopen("input.txt", "r")) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  }
}
struct point {
  long long x, y;
};
point p[4], q[4];
long long area(point a, point b, point c) {
  return abs((a.x - c.x) * (b.y - a.y) - (a.x - b.x) * (c.y - a.y));
}
int main() {
  fileio();
  for (int i = 0; i < 4; i++) cin >> p[i].x >> p[i].y;
  for (int i = 0; i < 4; i++) cin >> q[i].x >> q[i].y;
  long long lx = min({p[0].x, p[1].x, p[2].x, p[3].x});
  long long hx = max({p[0].x, p[1].x, p[2].x, p[3].x});
  long long ly = min({p[0].y, p[1].y, p[2].y, p[3].y});
  long long hy = max({p[0].y, p[1].y, p[2].y, p[3].y});
  long long Sq = area(q[0], q[1], q[2]) + area(q[0], q[2], q[3]);
  for (long long x = lx; x <= hx; x++)
    for (long long y = ly; y <= hy; y++) {
      point t;
      t.x = x, t.y = y;
      if ((area(t, q[0], q[1]) + area(t, q[1], q[2]) + area(t, q[2], q[3]) +
           area(t, q[0], q[3])) == Sq) {
        cout << "YES";
        return 0;
      }
    }
  cout << "NO";
  return 0;
}
