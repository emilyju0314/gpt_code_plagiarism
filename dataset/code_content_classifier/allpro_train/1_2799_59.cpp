#include <bits/stdc++.h>
using namespace std;
const int MAX = 6000 + 10;
const double INF = 1e9;
const double EPS = 1e-9;
int n, q, A, B;
int first[MAX];
struct node {
  node *p, *lc, *rc;
  double l;
  double a, b;
  double second;
};
void rotate(node* u) {
  node* fa = u->p;
  node* gfa = fa->p;
  if (fa->lc == u) {
    if (u->rc) u->rc->p = fa;
    fa->lc = u->rc;
    u->rc = fa;
  } else {
    if (u->lc) u->lc->p = fa;
    fa->rc = u->lc;
    u->lc = fa;
  }
  fa->p = u;
  if (gfa->lc == fa)
    gfa->lc = u;
  else
    gfa->rc = u;
  u->p = gfa;
}
void Splay(node* u) {
  node *fa, *gfa;
  for (; (fa = u->p); rotate(u))
    if ((gfa = fa->p)) rotate((gfa->lc == fa) == (fa->lc == u) ? fa : u);
}
namespace BF {
double ans[MAX];
struct line {
  double l, r, a, b;
  line(double first, double second, double z, double w) {
    l = first;
    r = second;
    a = z;
    b = w;
  }
  double zero() {
    double zz = -b / a;
    if (zz >= l && zz <= r) return zz;
    if (a > 0)
      return l;
    else
      return r;
  }
};
vector<line> now, tmp;
double solve(int u) {
  int i;
  double na = 2;
  double nb = -2 * first[u];
  double zz = -1;
  if (u != 1) {
    tmp.clear();
    double mm = 1e20;
    for ((i) = (0); (i) != (now.size()); ++(i)) {
      double t = now[i].zero();
      if (abs(t * now[i].a + now[i].b) < mm) {
        zz = t;
        mm = abs(t * now[i].a + now[i].b);
      }
    }
    double p;
    if (u != n + 1) {
      tmp.clear();
      for ((i) = (0); (i) != (now.size()); ++(i)) {
        if (now[i].r - now[i].l < 1e-10) continue;
        if (now[i].l <= zz)
          tmp.push_back(line(now[i].l + A, min(zz, now[i].r) + A, now[i].a + na,
                             now[i].b - now[i].a * A + nb));
        if (now[i].r >= zz)
          tmp.push_back(line(max(now[i].l, zz) + B, now[i].r + B, now[i].a + na,
                             now[i].b - now[i].a * B + nb));
      }
      tmp.push_back(line(zz + A, zz + B, na, nb));
      now = tmp;
      p = solve(u + 1);
    } else
      p = -1;
    if (p < 0 || (p - zz >= A && p - zz <= B))
      ans[u - 1] = zz;
    else if (abs(p - A - zz) < abs(p - B - zz))
      ans[u - 1] = p - A;
    else
      ans[u - 1] = p - B;
    ans[u - 1] = min(max(ans[u - 1], 1.0), (double)q);
    return ans[u - 1];
  } else {
    zz = first[1];
    now.push_back(line(1, q, na, nb));
    solve(2);
    return 0;
  }
}
int Main() {
  int i;
  double sum = 0;
  solve(1);
  for ((i) = (1); (i) <= (n); ++(i)) {
    printf("%lf ", ans[i]);
    sum += (ans[i] - first[i]) * (ans[i] - first[i]);
  }
  printf("\n%lf\n", sum);
  return 0;
}
}  // namespace BF
int main() {
  int i;
  scanf("%d%d%d%d", &n, &q, &A, &B);
  for ((i) = (1); (i) <= (n); ++(i)) scanf("%d", &first[i]);
  BF::Main();
}
