#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
struct node1 {
  double x, y;
};
struct node2 {
  node1 s, e;
};
map<pair<pair<long long, long long>, int>, bool> mp;
node2 seg[1007];
int n;
long long getabs(long long x) {
  if (x > 0)
    return x;
  else
    return -x;
}
long long getgcd(long long a, long long b) {
  long long t;
  while (b > 0) {
    t = b;
    b = a % b;
    a = t;
  }
  return a;
}
double cal(node1 a, node1 b, node1 c) {
  return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}
double getk(node1 p1, node1 p2) {
  return (double)(p2.y - p1.y) / (double)(p2.x - p1.x);
}
bool judge(node1 a, node1 b, node1 c, node1 d) {
  if (cal(a, b, c) * cal(a, b, d) < eps && cal(c, d, a) * cal(c, d, b) < eps &&
      getk(a, b) != getk(c, d))
    return 1;
  else
    return false;
}
node1 getpoint(node1 a, node1 b, node1 c, node1 d) {
  node1 res;
  double a1, b1, c1, a2, b2, c2;
  a1 = a.y - b.y, b1 = b.x - a.x, c1 = a.x * b.y - b.x * a.y;
  a2 = c.y - d.y, b2 = d.x - c.x, c2 = c.x * d.y - d.x * c.y;
  res.x = (b1 * c2 - b2 * c1) / (a1 * b2 - a2 * b1);
  res.y = -(a1 * c2 - a2 * c1) / (a1 * b2 - a2 * b1);
  return res;
}
bool isinterger(double x) {
  double t1;
  long long t2;
  t2 = x;
  t1 = t2;
  if (fabs(x - t1) < eps) return 1;
  return 0;
}
int main() {
  node1 res;
  long long ans, x1, y1, x2, y2;
  int i, j;
  scanf("%d", &n);
  ans = 0;
  for (i = 1; i <= n; i++) {
    scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
    seg[i].s.x = (double)x1, seg[i].e.x = (double)x2, seg[i].s.y = (double)y1,
    seg[i].e.y = (double)y2;
    ans += (getgcd(getabs(x1 - x2), getabs(y1 - y2)) + 1);
  }
  for (i = 1; i <= n; i++) {
    for (j = i + 1; j <= n; j++) {
      if (judge(seg[i].s, seg[i].e, seg[j].s, seg[j].e)) {
        res = getpoint(seg[i].s, seg[i].e, seg[j].s, seg[j].e);
        if (isinterger(res.x) && isinterger(res.y)) {
          x1 = res.x, y1 = res.y;
          if (!mp[make_pair(make_pair(x1, y1), i)] ||
              !mp[make_pair(make_pair(x1, y1), j)]) {
            mp[make_pair(make_pair(x1, y1), i)] = 1;
            mp[make_pair(make_pair(x1, y1), j)] = 1;
            ans--;
          }
        }
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}
