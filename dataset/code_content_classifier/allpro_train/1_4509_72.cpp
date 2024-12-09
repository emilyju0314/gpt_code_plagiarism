#include <bits/stdc++.h>
using namespace std;
const int N = 300 + 9;
struct Point {
  long long x, y;
  int id;
  Point operator-(const Point& b) const { return (Point){x - b.x, y - b.y}; }
  double ang() { return atan2(y, x); }
  long long cross(Point b) { return x * b.y - b.x * y; }
} p[N];
long long dp[N][N][7];
struct Seg {
  Point s, t;
  bool operator<(const Seg& b) const {
    double anga = (t - s).ang(), angb = (b.t - b.s).ang();
    if (fabs(anga - angb) > 1e-8) return anga < angb;
    return (t - s).cross(b.t - b.s) > 0;
  }
} seg[N * N];
int main() {
  int n;
  int cnt = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld %lld", &p[i].x, &p[i].y);
    p[i].id = i;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      seg[++cnt] = (Seg){p[i], p[j]};
      seg[++cnt] = (Seg){p[j], p[i]};
    }
  }
  sort(seg + 1, seg + 1 + cnt);
  for (int i = 1; i <= cnt; ++i) {
    int tid = seg[i].t.id, sid = seg[i].s.id;
    dp[sid][tid][1] += 1;
    for (int j = 1; j <= n; ++j) {
      for (int k = 2; k <= 5; ++k) {
        dp[sid][j][k] += dp[tid][j][k - 1];
      }
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; ++i) ans += dp[i][i][5];
  printf("%lld", ans);
}
