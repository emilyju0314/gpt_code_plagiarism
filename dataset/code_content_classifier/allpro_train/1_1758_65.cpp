#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3F3F3F3F;
int l[200020], lc;
int ans[200020];
set<pair<int, int> > c[200020];
struct N {
  int x, y, z, r;
  N() {}
  N(int x, int y, int z, int r) : x(x), y(y), z(z), r(r) {}
  bool operator<(const N& a) const { return y > a.y || y == a.y && r < a.r; }
} a[200020];
int Q(int z) { return lower_bound(l, l + lc, z) - l; }
void R(int x, pair<int, int> y) {
  for (x++; x <= lc; x += x & -x) c[x].insert(y);
  return;
}
int G(int x, int y) {
  pair<int, int> re = pair<int, int>(inf, -1);
  for (x++; x; x -= x & -x) {
    set<pair<int, int> >::iterator it = c[x].lower_bound(make_pair(y, 0));
    if (it != c[x].end()) re = min(re, *it);
  }
  return re.second;
}
int main() {
  int n, m, ac;
  int x, y, z;
  scanf("%d%d", &n, &m);
  lc = ac = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d", &x, &y, &z);
    a[ac++] = N(x, y, z, -i - 1);
    l[lc++] = x;
  }
  for (int i = 0; i < m; i++) {
    scanf("%d%d%d", &x, &y, &z);
    a[ac++] = N(x, y, z, i);
    l[lc++] = x;
  }
  sort(a, a + ac);
  sort(l, l + lc);
  lc = unique(l, l + lc) - l;
  for (int i = 0; i < ac; i++) {
    if (a[i].r < 0)
      R(Q(a[i].x), pair<int, int>(a[i].z, -a[i].r));
    else
      ans[a[i].r] = G(Q(a[i].x), a[i].z);
  }
  for (int i = 0; i < m; i++) printf("%d ", ans[i]);
  return 0;
}
