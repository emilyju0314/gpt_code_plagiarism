#include <bits/stdc++.h>
using namespace std;
const double INF = 1e15;
double ans;
int l[200010], c[200010], p[200010], n, t, q;
inline double f(int x, int c) {
  if (c == -1) return INF;
  if (c >= l[x]) return 0;
  return (double)p[x] * l[x] / (c + 1 + l[x]) / (c + l[x]);
}
inline double g(int x) {
  return (double)p[x] * min(c[x], l[x]) / (min(c[x], l[x]) + l[x]);
}
class node {
 public:
  double v;
  int x, c;
  node(int _x = 0, int _c = -1) {
    x = _x;
    c = _c;
    v = f(x, c);
  }
  inline bool operator<(const node &w) const {
    return v == w.v ? x < w.x : v < w.v;
  }
};
multiset<node> S, E;
inline void insert() {
  auto it = --S.end();
  ans += it->v;
  int x = it->x;
  E.erase(node(x, c[x] - 1));
  E.insert(*it);
  S.erase(it);
  S.insert(node(x, ++c[x]));
}
inline void erase() {
  auto it = E.begin();
  ans -= it->v;
  int x = it->x;
  S.erase(node(x, c[x]));
  S.insert(*it);
  E.erase(it);
  E.insert(node(x, (--c[x]) - 1));
}
int main() {
  scanf("%d%d%d", &n, &t, &q);
  for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &l[i]);
  for (int i = 1; i <= n; i++) S.insert(node(i, 0)), E.insert(node(i));
  for (int i = 1; i <= t; i++) insert();
  for (int i = 1, ti, tj; i <= q; i++) {
    scanf("%d%d", &ti, &tj);
    S.erase(node(tj, c[tj]));
    E.erase(node(tj, c[tj] - 1));
    ans -= g(tj);
    l[tj] += ti == 1 ? 1 : -1;
    S.insert(node(tj, c[tj]));
    E.insert(node(tj, c[tj] - 1));
    ans += g(tj);
    while (S.rbegin()->v > E.begin()->v + 1e-10) erase(), insert();
    printf("%.10lf\n", ans);
  }
  return 0;
}
